#ifndef B_PLUS_TREE_NODE_TPP
#define B_PLUS_TREE_NODE_TPP

#include "b_plus_tree_node.h"

// Constructor for BPTreeNode
// Initializes a new node with a specified minimum degree and a leaf status
BPTreeNode::BPTreeNode(const size_t t, const bool is_leaf) {
    // Set the minimum degree (t) of the node.
    // This defines the minimum and maximum number of keys the node can hold.
    _t = t;

    // Set whether this node is a leaf node.
    // If true, the node will have no child pointers, only keys and a `next` pointer.
    _is_leaf = is_leaf;

    // Initialize the keys array as an empty vector.
    // This will hold the keys for this node.
    _keys = {};

    // Initialize the children array as an empty vector.
    // This will hold pointers to child nodes if this is an internal node.
    _children = {};

    // Initialize the `next` pointer to nullptr.
    // This pointer is used only for leaf nodes to link them in a sequence for range queries.
    _next = nullptr;
}

// Destructor for BPTreeNode
// This destructor deletes only child nodes that are dynamically allocated.
// Other nodes in the B+ tree structure will handle their own deletion.
BPTreeNode::~BPTreeNode() {
    // Delete all children nodes if they are pointers
    for (const auto& child : _children) {
        delete child;  // This calls the destructor of each child node
    }
    _children.clear();  // Clear the vector after deleting children to prevent dangling pointers
}

// Inserts a key into a node that is not full. If the node is a leaf, it inserts
// the key directly into the correct position. If it's an internal node, it finds
// the correct child node and descends into it, splitting the child if necessary.
void BPTreeNode::insertNonFull(const int key) {
    size_t i = _keys.size() - 1;  // Start from the last key in the node

    // If the node is a leaf, find the correct position and insert the key
    if (_is_leaf) {
        i = 0;
        // Find the appropriate index to insert the key in a sorted order
        while (i < _keys.size() && _keys[i] < key) {
            i++;
        }
        // Insert the key at the found position in the sorted order
        _keys.insert(_keys.begin() + static_cast<int>(i), key);
    } else {
        // Descend to the appropriate child without using recursion
        auto currentNode = this;
        while (!currentNode->_is_leaf) {
            // Find the child that will have the key by iterating through keys
            i = currentNode->_keys.size() - 1;
            while (key < currentNode->_keys[i]) {
                if (i == 0) break;  // Prevent unsigned wraparound
                i--;
            }
            i++;

            // If the child node is full, split it before proceeding
            if (currentNode->_children[i]->_keys.size() == 2 * currentNode->_t - 1) {
                currentNode->splitChildren(i);
                // After splitting, the new key at index `i` may need adjustment
                if (key > currentNode->_keys[i]) {
                    i++;
                }
            }

            // Move to the child node
            currentNode = currentNode->_children[i];
        }

        // At this point, `currentNode` is a leaf node; insert the key here
        i = 0;
        while (i < currentNode->_keys.size() && currentNode->_keys[i] < key) {
            i++;
        }
        currentNode->_keys.insert(currentNode->_keys.begin() + static_cast<int>(i), key);
    }
}

// Splits a full child node at the specified index. The child node is divided into
// two nodes, and the middle key is moved up into the current node.
void BPTreeNode::splitChildren(const size_t i) {
    const int t = static_cast<int>(_t);  // Minimum degree
    BPTreeNode* child = _children[i];  // The child node to be split
    const auto newChild = new BPTreeNode(t, child->_is_leaf);  // Create a new node for the split

    // Split the keys of the child: move the second half of keys to the new child node
    newChild->_keys = {child->_keys.begin() + t, child->_keys.end()};
    child->_keys = {child->_keys.begin(), child->_keys.begin() + t - 1};

    // If the child is not a leaf, split its children as well
    if (!child->_is_leaf) {
        // Move the second half of the child pointers to the new child node
        newChild->_children = {child->_children.begin() + t, child->_children.end()};
        child->_children = {child->_children.begin(), child->_children.begin() + t};
    }

    // Adjust `next` pointers for leaf nodes to maintain linked leaf sequence
    if (child->_is_leaf) {
        newChild->_next = child->_next;  // Link new child to the next leaf
        child->_next = newChild;         // Update the old child to point to the new child
    }

    // Insert the middle key from the child into the current node
    // and insert a pointer to the new child node
    _keys.insert(_keys.begin() + static_cast<int>(i), child->_keys.back());
    child->_keys.pop_back();  // Remove the middle key from the old child
    _children.insert(_children.begin() + static_cast<int>(i) + 1, newChild);
}

#endif // B_PLUS_TREE_NODE_TPP
