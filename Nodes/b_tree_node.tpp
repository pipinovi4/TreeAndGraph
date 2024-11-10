#ifndef B_TREE_NODE_TPP
#define B_TREE_NODE_TPP

#include <array>
#include "b_tree_node.h"
#include <stack>

// Constructor to initialize a B-tree node
BTreeNode::BTreeNode(const int t, const bool is_leaf) {
    _t = t;                     // Minimum degree of the B-tree; controls key range per node
    _is_leaf = is_leaf;         // True if the node is a leaf node (no children), else False
    _keys = {};                 // Initialize an empty list of keys
    _children = {};             // Initialize an empty list of child nodes
}

// Destructor to clean up memory by deleting child nodes iteratively
BTreeNode::~BTreeNode() {
    std::stack<BTreeNode*> stackNodes;  // Stack to track nodes for deletion
    for (auto* child : _children) {     // Add each non-null child of the root node to stack
        if (child) stackNodes.push(child);
    }

    // Iteratively delete nodes in stack, handling children first
    while (!stackNodes.empty()) {
        const auto& currentNode = stackNodes.top(); // Get the top node
        stackNodes.pop();                           // Remove it from the stack

        // Push all children of currentNode to stack for deletion
        for (auto* currentChild : currentNode->_children) {
            if (currentChild) stackNodes.push(currentChild); // Add non-null children to stack
        }

        delete currentNode; // Delete the current node to prevent memory leak
    }
}

// Split the child `y` of this node at index `i`
// This is called when `y` is full, so it splits into two nodes and promotes the median key
void BTreeNode::splitChild(const int& i, BTreeNode* y) {
    const int t = static_cast<int>(_t);  // Get the minimum degree
    auto* z = new BTreeNode(t, y->_is_leaf); // Create a new node `z` with the same leaf status as `y`

    // Move the last `t` keys from `y` to `z`
    z->_keys.assign(y->_keys.begin() + t, y->_keys.end());

    // If `y` is not a leaf, also move the last `t` children from `y` to `z`
    if (!y->_is_leaf) {
        z->_children.assign(y->_children.begin() + t, y->_children.end());
    }

    // Resize `y`'s keys and children to exclude the moved elements
    y->_keys.resize(t - 1);
    y->_children.resize(t);

    // Insert `z` into this node's children and promote the median key from `y`
    _children.insert(_children.begin() + i + 1, z);
    _keys.insert(_keys.begin() + i, y->_keys.back());
}

// Insert a key into a non-full node using an iterative approach
void BTreeNode::insertNonFull(const int& key) {
    std::stack<BTreeNode*> stackNodes;
    stackNodes.emplace(this); // Begin with the current node

    while (!stackNodes.empty()) {
        int i = static_cast<int>(_keys.size()) - 1; // Start at the last key position
        BTreeNode* currentNode = stackNodes.top();  // Get the current node from the stack
        stackNodes.pop();

        // If it's a leaf node, find the correct position and insert the key
        if (currentNode->_is_leaf) {
            currentNode->_keys.push_back(0); // Add temporary space for the new key
            while (i >= 0 && key < currentNode->_keys[i]) { // Shift keys right to make space
                currentNode->_keys[i + 1] = currentNode->_keys[i];
                i -= 1;
            }
            currentNode->_keys[i + 1] = key; // Place the key in the correct position
        } else {
            // If not a leaf, find the child that will receive the new key
            while (i >= 0 && key < currentNode->_keys[i]) i--;
            i++;
            // Split the child if it is full
            if (currentNode->_children[i]->_keys.size() == 2 * currentNode->_t - 1) {
                splitChild(i, currentNode->_children[i]);
                if (key > currentNode->_keys[i]) i++;
            }
            // Add the chosen child to stack for further processing
            stackNodes.emplace(currentNode->_children[i]);
        }
    }
}

// Search for a key in the B-tree, returning the node containing it (or nullptr if not found)
BTreeNode* BTreeNode::search(const int& key) {
    std::stack<BTreeNode*> stackNodes;
    stackNodes.push(this); // Start with the root node

    while (!stackNodes.empty()) {
        auto* currentNode = stackNodes.top();
        stackNodes.pop();

        const size_t i = currentNode->findKey(key); // Locate the key position in current node
        if (i < currentNode->_keys.size() && currentNode->_keys[i] == key) {
            return currentNode; // Key found, return the current node
        }
        if (currentNode->_is_leaf) return nullptr; // Key not found in a leaf node, return nullptr
        stackNodes.push(currentNode->_children[i]); // Continue search in the appropriate child
    }
    return nullptr; // Key not found
}

// Remove a key from the tree using an iterative approach
void BTreeNode::remove(const int& key) {
    std::stack<BTreeNode*> stackNodes;
    stackNodes.push(this);

    while (!stackNodes.empty()) {
        auto* currentNode = stackNodes.top();
        stackNodes.pop();

        const size_t idx = findKey(key); // Find the position of the key in current node

        if (idx < currentNode->_keys.size() && currentNode->_keys[idx] == key) {
            if (currentNode->_is_leaf) removeFromLeaf(idx); // Remove from leaf node directly
            else removeFromNonLeaf(idx, stackNodes);        // Remove from non-leaf node iteratively
        } else {
            if (currentNode->_is_leaf) return;              // Key not found and node is leaf, end
            const size_t flag = idx == currentNode->_keys.size();
            if (currentNode->_children[idx]->_keys.size() < currentNode->_t) currentNode->fill(idx); // Ensure enough keys in child
            if (flag && idx > currentNode->_keys.size()) {
                stackNodes.push(currentNode->_children[idx - 1]);
            } else {
                stackNodes.push(currentNode->_children[idx]);
            }
        }
    }
}

// Helper to find index of the first key >= key
size_t BTreeNode::findKey(const int& key) const {
    size_t idx = 0;
    while (idx < _keys.size() && _keys[idx] < key) {
        idx += 1;
    }
    return idx;
}

// Get the predecessor (largest key in left subtree) for a non-leaf node
int BTreeNode::getPred(const size_t& idx) const {
    const BTreeNode* cur = _children[idx];
    while (!cur->_is_leaf) { // Keep moving to the rightmost child until a leaf
        cur = cur->_children.back();
    }
    return cur->_keys.back(); // Return the last key
}

// Get the successor (smallest key in right subtree) for a non-leaf node
int BTreeNode::getSucc(const size_t& idx) const {
    const BTreeNode* cur = _children[idx + 1];
    while (!cur->_is_leaf) { // Move to the leftmost child until a leaf
        cur = cur->_children[0];
    }
    return cur->_keys[0]; // Return the first key
}

// Remove a key from a leaf node
void BTreeNode::removeFromLeaf(const size_t& idx) {
    _keys.erase(_keys.begin() + static_cast<int>(idx)); // Erase key directly from leaf
}

// Remove a key from a non-leaf node, pushing next nodes into stack
void BTreeNode::removeFromNonLeaf(const size_t& idx, std::stack<BTreeNode*>& stackNodes) {
    if (_children[idx]->_keys.size() >= _t) { // Check if left child has enough keys
        const int pred = getPred(idx);       // Get predecessor
        _keys[idx] = pred;                   // Replace key with predecessor
        stackNodes.push(_children[idx]);     // Push child to stack for removal
    } else if (_children[idx + 1]->_keys.size() >= _t) { // Check if right child has enough keys
        const int succ = getSucc(idx);       // Get successor
        _keys[idx] = succ;                   // Replace key with successor
        stackNodes.push(_children[idx + 1]); // Push right child for further removal
    } else {                                 // If both children are small, merge them
        merge(idx);                          // Merge children
        stackNodes.push(_children[idx]);     // Push merged child for further removal
    }
}

// Ensure the node at `idx` has enough keys, by borrowing or merging
void BTreeNode::fill(const size_t& idx) {
    if (idx != 0 && _children[idx - 1]->_keys.size() >= _t) {
        borrowFromPrev(idx); // Borrow from previous sibling
    } else if (idx != _keys.size() && _children[idx + 1]->_keys.size() >= _t) {
        borrowFromNext(idx); // Borrow from next sibling
    } else {
        if (idx != _keys.size()) merge(idx); // Merge with next sibling
        else merge(idx - 1);                 // Merge with previous sibling
    }
}

// Borrow a key from the previous sibling
void BTreeNode::borrowFromPrev(const size_t& idx) {
    BTreeNode* child = _children[idx];
    BTreeNode* sibling = _children[idx - 1];

    child->_keys.insert(child->_keys.begin(), _keys[idx - 1]); // Transfer key from parent to child
    if (!child->_is_leaf || !sibling->_children.empty()) {     // Transfer last child if not a leaf
        BTreeNode* lastChild = sibling->_children.back();
        sibling->_children.pop_back();
        child->_children.insert(child->_children.begin(), lastChild);
    }
    _keys[idx - 1] = sibling->_keys.back(); // Move last sibling key to parent
    sibling->_keys.pop_back();              // Remove last sibling key
}

// Borrow a key from the next sibling
void BTreeNode::borrowFromNext(const size_t& idx) {
    BTreeNode* child = _children[idx];
    BTreeNode* sibling = _children[idx + 1];

    child->_keys.push_back(_keys[idx]);     // Transfer key from parent to child
    if (!child->_is_leaf) {                 // Transfer sibling's first child if not a leaf
        child->_children.push_back(sibling->_children[0]);
        sibling->_children.erase(sibling->_children.begin());
    }
    _keys[idx] = sibling->_keys.front();    // Move sibling's first key to parent
    sibling->_keys.erase(sibling->_keys.begin());
}

// Merge child at `idx` with the next child
void BTreeNode::merge(const size_t& idx) {
    BTreeNode* child = _children[idx];
    BTreeNode* sibling = _children[idx + 1];

    child->_keys.push_back(_keys[idx]);     // Append parent's key to child
    _keys.erase(_keys.begin() + static_cast<int>(idx));       // Remove key from parent

    child->_keys.insert(child->_keys.end(), sibling->_keys.begin(), sibling->_keys.end());
    if (!child->_is_leaf) {                 // Transfer sibling's children if not a leaf
        child->_children.insert(child->_children.end(), sibling->_children.begin(), sibling->_children.end());
    }
    _children.erase(_children.begin() + static_cast<int>(idx) + 1); // Remove sibling from parent
}

// Print the tree level-by-level, starting from this node
void BTreeNode::printNode(const int level) const {
    std::queue<std::pair<const BTreeNode*, int>> nodeQueue; // Queue for level-order traversal
    nodeQueue.emplace(this, 0);                             // Start with the root at level 0

    while (!nodeQueue.empty()) {
        auto [currentNode, level] = nodeQueue.front();      // Get current node and its level
        nodeQueue.pop();

        // Print the keys in the current node
        std::cout << "Level " << level << " Keys: ";
        for (const auto& key : currentNode->_keys) {
            std::cout << key << " ";
        }
        std::cout << std::endl;

        // Add children of current node to queue, incrementing their level
        for (const auto* child : currentNode->_children) {
            if (child) {
                nodeQueue.emplace(child, level + 1);
            }
        }
    }
}

#endif // B_TREE_NODE_TPP