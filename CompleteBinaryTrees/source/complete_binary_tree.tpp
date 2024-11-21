#ifndef COMPLETE_BINARY_TREE_TPP
#define COMPLETE_BINARY_TREE_TPP

#include "complete_binary_tree.h"  // Include the header file for CompleteBinaryTree
#include <cmath>                   // Include cmath for mathematical functions
#include <algorithm>               // Include algorithm for standard algorithms like std::any_of

// Constructor for CompleteBinaryTree
inline CompleteBinaryTree::CompleteBinaryTree() {
    nodes = {};  // Initialize the nodes vector as empty
}

// Destructor for CompleteBinaryTree
inline CompleteBinaryTree::~CompleteBinaryTree() {
    // Iterate through the nodes vector and delete each node to free memory
    for (const Node* node : nodes) {
        delete node;  // Deallocate memory for each node
    }
}

// Inserts a new node into the Complete Binary Tree
inline void CompleteBinaryTree::insert(const int data) {
    const auto new_data = new Node(data);  // Create a new Node instance with the given data
    nodes.push_back(new_data);  // Add the new node to the end of the nodes vector

    const size_t index = nodes.size() - 1;  // Get the index of the newly added node
    if (index > 0) {  // Ensure the node is not the root
        const int parent_idx = std::floor((index - 1) / 2);  // Calculate the parent index
        // Assign the new node as the left or right child of its parent
        if (!nodes[parent_idx]->left) {
            nodes[parent_idx]->left = new_data;  // Assign as left child if not occupied
        } else {
            nodes[parent_idx]->right = new_data;  // Otherwise, assign as right child
        }
    }
}

// Searches for a target value in the Complete Binary Tree
inline bool CompleteBinaryTree::search(const int target) const {
    // Use std::any_of to check if any node's data matches the target value
    return std::any_of(nodes.begin(), nodes.end(), [target](const Node* node) {
        return node->data == target;  // Return true if a match is found
    });
}

// Prints the values of the Complete Binary Tree in level order
void CompleteBinaryTree::printTree() const {
    // Iterate through the nodes vector and print each node's data
    for (const Node* node : nodes) {
        std::cout << node->data << " ";  // Output the data of the current node
    }
}

#endif // COMPLETE_BINARY_TREE_TPP
