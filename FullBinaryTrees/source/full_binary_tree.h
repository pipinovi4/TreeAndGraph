#ifndef FULL_BINARY_TREE_H
#define FULL_BINARY_TREE_H

#pragma once
#include "../../Nodes/defaultNodes/node.h"

// FullBinaryTree class to represent a full binary tree structure
class FullBinaryTree {
public:
    // Pointer to the root node of the tree. Initialized to nullptr, indicating an empty tree.
    Node* root = nullptr;

    // Constructor: Initializes a FullBinaryTree instance, typically setting up the root.
    inline FullBinaryTree();

    // Destructor: Releases any resources or memory associated with the tree.
    inline ~FullBinaryTree();

    /**
     * Adds two children to a specified parent node if it has no children.
     * This enforces the full binary tree structure, where each node has either
     * 0 or 2 children.
     * 
     * @param parent - Pointer to the parent node where children will be added.
     * @param left_data - The data for the left child.
     * @param right_data - The data for the right child.
     * 
     * @throws std::runtime_error if the parent already has children.
     */
    static inline void addChildren(Node* parent, int left_data, int right_data);

    /**
     * Searches the tree for a node with the specified target value using pre-order traversal.
     * 
     * @param node - The current node to start the search from (usually the root).
     * @param target - The value being searched for in the tree.
     * 
     * @return true if the target value is found, false otherwise.
     */
    static inline bool search(const Node* node, int target);

    /**
     * Performs a pre-order traversal of the tree, printing each node's value.
     * This method traverses from the specified node and prints the tree in
     * the following order: root, left subtree, right subtree.
     * 
     * @param node - The starting node for the traversal (usually the root).
     */
    static inline void printTree(const Node* node);
};

#include "full_binary_tree.tpp"

#endif // FULL_BINARY_TREE_H
