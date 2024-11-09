#ifndef B_TREE_NODE_TPP
#define B_TREE_NODE_TPP

#include "b_tree_node.h"
#include <algorithm>

// Constructor initializes whether the node is a leaf or not
BTreeNode::BTreeNode(const bool is_leaf) : is_leaf(is_leaf) {}

// Destructor recursive delete all BTreeNodes descent by children
inline BTreeNode::~BTreeNode() {
    std::stack<BTreeNode*> nodeStack;

    // Start by pushing the current node (this) onto the stack if it has children
    if (!children.empty()) {
        nodeStack.push(this);
    }

    // Iteratively delete nodes and their children
    while (!nodeStack.empty()) {
        BTreeNode* current = nodeStack.top();
        nodeStack.pop();

        // Push all children of the current node onto the stack
        for (BTreeNode* child : current->children) {
            if (child) {
                nodeStack.push(child);
            }
        }

        // Clear children pointers to avoid dangling pointers after deletion
        current->children.clear();

        // Delete the current node
        delete current;
    }
}

/**
 * Adds a key to the node in sorted order.
 * @param key The key to add.
 */
void BTreeNode::addKey(const int key) {
    keys.push_back(key);
    std::sort(keys.begin(), keys.end()); // Keep keys sorted
}

/**
 * Removes a key from the node, if it exists.
 * @param key The key to remove.
 */
void BTreeNode::removeKey(const int key) {
    const auto it = std::find(keys.begin(), keys.end(), key);
    if (it != keys.end()) {
        keys.erase(it); // Remove the key if found
    }
}

/**
 * Checks if the node is full, based on the maximum number of allowed keys.
 * @param max_keys Maximum keys allowed in the node.
 * @return True if the node has reached the maximum number of keys, otherwise false.
 */
bool BTreeNode::isFull(const int max_keys) const {
    return keys.size() == max_keys;
}

#endif // B_TREE_NODE_TPP
