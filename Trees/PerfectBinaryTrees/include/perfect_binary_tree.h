#ifndef PERFECT_BINARY_TREE_H
#define PERFECT_BINARY_TREE_H

#pragma once
#include "../../../Nodes/defaultNodes/node.h"
#include <vector>           // Include vector for dynamic array functionality

/**
 * Class representing a Perfect Binary Tree.
 * A Perfect Binary Tree is a binary tree in which all interior nodes have two children
 * and all leaves are at the same level.
 */
class PerfectBinaryTree {
public:
    Node* root;  // Pointer to the root node of the tree

    /**
     * Constructor to initialize the PerfectBinaryTree.
     *
     * @param data A vector of integers used to populate the tree.
     * @param depth The depth of the perfect binary tree. Determines how many levels the tree will have.
     * This constructor builds the tree based on the provided data and specified depth.
     */
    inline PerfectBinaryTree(const std::vector<int>& data, int depth);

    /**
     * Destructor for the PerfectBinaryTree.
     * Cleans up dynamically allocated resources when a PerfectBinaryTree object is destroyed.
     */
    inline ~PerfectBinaryTree();

    /**
     * Builds the perfect binary tree recursively.
     *
     * @param data A vector of integers used to create the nodes of the tree.
     * @param depth The remaining depth to construct the tree.
     * @returns A pointer to the newly created Node that represents the root of the subtree.
     */
    static inline Node* buildPerfectTree(std::vector<int> data, int depth);

    /**
     * Searches for a target value in the tree.
     *
     * @param node A pointer to the current node being examined.
     * @param target The value to search for in the tree.
     * @returns true if the target is found, false otherwise.
     */
    static inline bool search(const Node* node, int target);

    /**
     * Prints the tree in a structured format (in-order).
     *
     * @param node A pointer to the node from which the printing starts (usually the root).
     * This method traverses the tree and prints the values of the nodes in an in-order fashion.
     */
    static inline void printTree(const Node* node);
};

#include "../source/perfect_binary_tree.tpp"  // Include the implementation file

#endif //PERFECT_BINARY_TREE_H
