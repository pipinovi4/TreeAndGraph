#ifndef NODE_H
#define NODE_H

#pragma once

/**
 * @class Node
 * @brief A class representing a node in a binary tree.
 * 
 * Each node stores an integer value and has pointers to its left and right child nodes.
 * This class is designed to be used within binary tree structures, such as FullBinaryTree.
 */
class Node {
public:
    int data;        ///< The data value stored in the node.
    Node* left;      ///< Pointer to the left child node.
    Node* right;     ///< Pointer to the right child node.
    size_t height{}; ///< Counter height of the node

    /**
     * @brief Constructor to initialize a node with a given value.
     * 
     * Initializes the node's data with the provided value and sets the left
     * and right child pointers to nullptr, indicating that the node has no children initially.
     * 
     * @param value An integer value to initialize the node's data.
     */
    explicit inline Node(int value);
};

#include "node.tpp"

#endif // NODE_H
