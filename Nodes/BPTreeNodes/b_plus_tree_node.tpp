#ifndef B_PLUS_TREE_NODE_TPP
#define B_PLUS_TREE_NODE_TPP

#include "b_plus_tree_node.h"
#include <iostream>
#include <algorithm>

// Constructor for BPTreeNode
// Initializes a new node with a specified minimum degree and a leaf status
BPTreeNode::BPTreeNode(const size_t t, const bool is_leaf, BPTreeNode* parent) {
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

    // Set the parent of the node
    // This pointer is used only for propagation above by hierarchy
    _parent = parent;

    // Initialize the `next` pointer to nullptr.
    // This pointer is used only for leaf nodes to link them in a sequence for range queries.
    _next = nullptr;
}

// Inserts a key into a node that is not full. If the node is a leaf, it inserts
// the key directly into the correct position. If it's an internal node, it finds
// the correct child node and descends into it, splitting the child if necessary.
void BPTreeNode::insertNonFull(const int key) {
    auto current = this;

    while (!current->_is_leaf) {
        // Navigate to the correct child for insertion
        const auto it = std::upper_bound(current->_keys.begin(), current->_keys.end(), key);
        int i = static_cast<int>(std::distance(current->_keys.begin(), it));

        // Split child if it is full
        if (i < current->_children.size() && current->_children[i]->_keys.size() == 2 * _t - 1) {
            current->splitChildren(i);

            // Adjust the target child index if the key should go to the newly created right child
            if (key > current->_keys[i]) {
                i += 1;
            }
        }

        // Move down to the child node
        current = current->_children[i];
    }

    // ** Check for duplicates in the leaf node **
    if (std::find(current->_keys.begin(), current->_keys.end(), key) != current->_keys.end()) {
        return; // Key already exists, do nothing
    }

    // Insert key into the correct position in the leaf node
    const auto pos = std::lower_bound(current->_keys.begin(), current->_keys.end(), key);
    current->_keys.insert(pos, key);
}

// Splits a full child node at the specified index. The child node is divided into
// two nodes, and the middle key is moved up into the current node.
void BPTreeNode::splitChildren(const size_t i) {
    const int t = static_cast<int>(_t);  // Minimum degree
    BPTreeNode* child = _children[i];  // The child node to be split

    if (!child) {
        throw std::invalid_argument("Child node is null and cannot be split.");
    }

    if (child->_keys.size() < 2 * t - 1) {
        throw std::length_error("Child node does not have enough keys to split.");
    }

    // Create a new node for the split
    auto* newChild = new BPTreeNode(t, child->_is_leaf);

    // Move the second half of keys to the new child
    newChild->_keys = std::vector<int>(
        std::make_move_iterator(child->_keys.begin() + t),
        std::make_move_iterator(child->_keys.end())
    );
    child->_keys.resize(t - 1);  // Retain the first `t - 1` keys in the original child

    // If the child is not a leaf, move its children as well
    if (!child->_is_leaf) {
        newChild->_children = std::vector<BPTreeNode*>(
            std::make_move_iterator(child->_children.begin() + t),
            std::make_move_iterator(child->_children.end())
        );
        child->_children.resize(t);  // Retain the first `t` children in the original child

        for (auto* grandchild : newChild->_children) {
            grandchild->_parent = newChild;
        }
    }

    // Adjust `next` pointers for leaf nodes to maintain linked leaf sequence
    if (child->_is_leaf) {
        newChild->_next = child->_next;  // Link new child to the next leaf
        child->_next = newChild;         // Update the old child to point to the new child
    }

    // Insert the middle key into the parent node and update children
    _keys.insert(_keys.begin() + static_cast<int>(i), child->_keys[t - 1]); // Move the middle key
    _children.insert(_children.begin() + static_cast<int>(i) + 1, newChild);
}

#endif // B_PLUS_TREE_NODE_TPP
