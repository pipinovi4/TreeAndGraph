#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H

#pragma once
#include <vector>
#include "../Nodes/defaultNodes/node.h"

/**
 * Class representing a Complete Binary Tree.
 * A Complete Binary Tree is a binary tree where all levels are fully filled 
 * except possibly the last level, which is filled from left to right.
 */
class CompleteBinaryTree {
public:
    std::vector<Node*> nodes;  // Vector to store pointers to nodes in level order

    /**
     * Constructor for CompleteBinaryTree.
     * Initializes an empty Complete Binary Tree.
     */
    inline CompleteBinaryTree();

    /**
     * Destructor for CompleteBinaryTree.
     * Cleans up any allocated resources (if applicable).
     */
    inline ~CompleteBinaryTree();

    /**
     * Inserts a new node with the given data into the Complete Binary Tree.
     * Nodes are added from left to right to maintain completeness.
     *
     * @param data The value to be stored in the new node.
     */
    inline void insert(int data);

    /**
     * Searches for a target value in the Complete Binary Tree.
     *
     * @param target The value to search for.
     * @return true if the target is found; otherwise, false.
     */
    inline bool search(int target) const;

    /**
     * Prints the values of the Complete Binary Tree in level order.
     * The output displays the nodes from top to bottom, left to right.
     */
    inline void printTree() const;
};

#include "complete_binary_tree.tpp"  // Include the implementation of inline methods

#endif // COMPLETE_BINARY_TREE_H
