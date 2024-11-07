#ifndef PERFECT_BINARY_TREE_H
#define PERFECT_BINARY_TREE_H

#pragma once
#include "../Nodes/node.h"  // Include the Node class definition
#include <vector>           // Include vector for dynamic array functionality

/**
 * Class representing a Perfect Binary Tree.
 * A Perfect Binary Tree is a binary tree in which all interior nodes have two children 
 * and all leaves are at the same level.
 */
class PerfectBinaryTree {
public:
    Node* root;  // Pointer to the root node of the tree

    // Constructor to initialize the PerfectBinaryTree with given data and depth
    inline PerfectBinaryTree(const std::vector<int>& data, int depth);
    
    // Destructor to clean up resources
    inline ~PerfectBinaryTree();

    // Builds the perfect binary tree recursively
    static inline Node* buildPerfectTree(std::vector<int> data, int depth);

    // Searches for a target value in the tree
    static inline bool search(const Node* node, int target);

    // Prints the tree in a structured format (in-order)
    static inline void printTree(const Node* node);
};

#include "perfect_binary_tree.tpp"  // Include the implementation file

#endif //PERFECT_BINARY_TREE_H
