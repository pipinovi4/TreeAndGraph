#ifndef B_TREE_TPP
#define B_TREE_TPP

#include "b_tree.h"
#include <stack>

// Constructor for BTree: Initializes an empty B-Tree with a root node
BTree::BTree(const int& t) {
    _root = new BTreeNode(t, true);  // Create a new root as a leaf
    _t = t;                          // Set the minimum degree
}

// Destructor for BTree: Iteratively deletes all nodes in the B-Tree
BTree::~BTree() {
    std::stack<BTreeNode*> stackNodes;  // Stack for nodes to delete
    stackNodes.push(_root);             // Start with the root node

    // Use a stack to process all nodes iteratively
    while (!stackNodes.empty()) {
        const auto* currentNode = stackNodes.top();
        stackNodes.pop();

        // Push each child of the current node onto the stack
        if (currentNode && !currentNode->_children.empty()) {
            for (auto* child : currentNode->_children) {
                stackNodes.push(child);
            }
        }

        // Delete the current node after its children are handled
        delete currentNode;
    }
}

// Insert a key into the B-Tree
void BTree::insert(const int& key) {
    BTreeNode* root = _root;
    // If the root is full, it must be split to maintain B-Tree properties
    if (root->_keys.size() == 2 * _t - 1) {
        auto* new_root = new BTreeNode(_t, false);  // Create a new root as non-leaf
        new_root->_children.push_back(_root);       // New root has old root as its first child
        new_root->splitChild(0, root);              // Split the old root and move the middle key up

        // Determine the appropriate child to insert the new key into
        const size_t idx = key < new_root->_keys[0] ? 0 : 1;
        new_root->_children[idx]->insertNonFull(key);  // Insert the key in the appropriate subtree
        _root = new_root;  // Update the root to the new root
    } else {
        root->insertNonFull(key);  // Insert into the existing root if it is not full
    }
}

// Search for a key in the B-Tree
BTreeNode* BTree::search(const int& key) const {
    // Start the search from the root, if the root exists
    return _root ? _root->search(key) : nullptr;
}

// Remove a key from the B-Tree
void BTree::remove(const int& key) {
    if (!_root) return;  // If tree is empty, nothing to remove

    _root->remove(key);  // Start removal from the root node

    // After removal, adjust the root if it is empty
    if (_root->_keys.empty()) {
        _root = !_root->_is_leaf ? _root->_children[0] : nullptr;  // Update root if necessary
    }
}

// Print the B-Tree structure level by level
void BTree::printTree() const {
    if (_root) {
        std::stack<std::pair<BTreeNode*, int>> stack;  // Stack to track nodes and their levels
        stack.emplace(_root, 0);  // Start with the root node at level 0

        // Process all nodes using the stack
        while (!stack.empty()) {
            auto* currentNode = stack.top().first;
            const auto& currentLevel = stack.top().second;
            stack.pop();

            // Print the keys of the current node at its level
            std::cout << "Level " << currentLevel << ": [";
            for (size_t i = 0; i < currentNode->_keys.size(); ++i) {
                std::cout << currentNode->_keys[i];
                if (i != currentNode->_keys.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "] ";

            // Push children onto the stack with incremented level
            if (!currentNode->_is_leaf) {
                for (auto* child : currentNode->_children) {
                    if (!child->_keys.empty()) stack.emplace(child, currentLevel + 1);
                }
            }

            std::cout << std::endl;  // End the line after printing a node's keys
        }
    } else {
        std::cout << "Tree is empty." << std::endl;  // Print message if the tree has no nodes
    }
}

#endif // B_TREE_TPP
