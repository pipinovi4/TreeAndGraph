#ifndef FULL_BINARY_TREE_TPP
#define FULL_BINARY_TREE_TPP

#include "full_binary_tree.h"
#include <iostream>
#include <stack>
#include <stdexcept>

// Constructor: Initializes the tree by creating the root node with value 1
FullBinaryTree::FullBinaryTree() {
    this->root = new Node(1); // Set the root node to have data = 1
}

// Destructor: Releases allocated memory. Note: This only deletes the root and does not
// clean up the entire tree; a full recursive deletion method would be needed for larger trees.
FullBinaryTree::~FullBinaryTree() {
    delete root; // Only deletes root; does not handle all nodes in the tree
}

// Adds two children to the specified parent node, if it has no children.
// Throws an error if the parent already has children, enforcing the full binary tree property.
void FullBinaryTree::addChildren(Node* parent, const int left_data, const int right_data) {
    if (parent->left == nullptr && parent->right == nullptr) { // Ensure no children exist
        if (left_data && right_data) { // Check that both left and right data are provided
            parent->left = new Node(left_data); // Create left child with specified data
            parent->right = new Node(right_data); // Create right child with specified data
        } else {
            throw std::runtime_error("A full binary tree requires either 0 or 2 children.");
        }
    } else {
        throw std::runtime_error("Parent already has children"); // Error if children already exist
    }
}

// Searches the tree for a node containing the target value using an iterative pre-order traversal.
bool FullBinaryTree::search(const Node* node, const int target) {
    if (node == nullptr) {
        return false; // Return false if tree is empty or node is null
    }

    std::stack<const Node*> stack;
    stack.push(node); // Start with the root node

    // Iteratively traverse nodes using a stack
    while (!stack.empty()) {
        const Node* current = stack.top();
        stack.pop();

        if (current->data == target) { // Check if the current node matches the target
            return true;
        }

        // Push right child first so left child is processed next, preserving pre-order
        if (current->right) {
            stack.push(current->right);
        }
        if (current->left) {
            stack.push(current->left);
        }
    }

    return false; // Return false if target is not found
}

// Prints the tree in a pre-order traversal order, iteratively using a stack.
void FullBinaryTree::printTree(const Node* node) {
    if (!node) return; // Check for null root

    std::stack<const Node*> stack; // Stack to hold nodes for traversal
    stack.push(node); // Start traversal from the root node

    while (!stack.empty()) {
        const Node* current = stack.top();
        stack.pop();

        std::cout << current->data << " "; // Print the data of the current node

        // Push right child first so left child is processed next (pre-order traversal)
        if (current->right) {
            stack.push(current->right);
        }
        if (current->left) {
            stack.push(current->left);
        }
    }
}

#endif // FULL_BINARY_TREE_TPP
