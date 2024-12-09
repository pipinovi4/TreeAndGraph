#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#pragma once
#include "../../Nodes/defaultNodes/node.h"

/**
 * @class BinarySearchTree
 * @brief A class representing a Binary Search Tree (BST) with basic functionalities.
 *
 * This class provides the ability to insert, search, and delete nodes in a Binary Search Tree.
 * Each node in the tree stores an integer value. Nodes are organized such that for any given node,
 * all values in the left subtree are less than the node's value, and all values in the right subtree are greater.
 *
 * Public Member Functions:
 * - `insert(int data)`: Inserts a new node with the specified data into the BST.
 * - `search(int target) const`: Searches for a specific value in the BST, returning `true` if found and `false` otherwise.
 * - `remove(int data)`: Deletes the node with the specified data from the BST, if it exists.
 * - `print_tree() const`: Prints the values in the BST using an in-order traversal, displaying nodes in sorted order.
 */
class BinarySearchTree {
public:
    /**
     * @brief Root node of the BST.
     *
     * This pointer holds the root node of the tree. It is initialized to nullptr if the tree is empty.
     */
    Node* root;

    /**
     * @brief Default Constructor
     *
     * Initializes an empty Binary Search Tree with the root set to nullptr.
     */
    inline BinarySearchTree();

    /**
     * @brief Destructor
     *
     * Recursively deletes all nodes in the tree, freeing allocated memory.
     */
    inline ~BinarySearchTree();

    /**
     * @brief Inserts a new node with the specified data into the BST.
     *
     * @param data The integer value to be inserted into the tree.
     * If the value already exists in the BST, no duplicate is inserted.
     */
    inline void insert(int data);

    /**
     * @brief Searches for a specified value in the BST.
     *
     * @param target The integer value to search for.
     * @return `true` if the value exists in the tree, otherwise `false`.
     */
    inline bool search(int target) const;

    /**
     * @brief Removes the node with the specified data from the BST.
     *
     * @param data The integer value of the node to be deleted.
     * If the node has two children, it is replaced by its in-order successor.
     */
    inline void remove(int data);

    /**
     * @brief Prints the values in the BST.
     *
     * This function performs an in-order traversal of the tree, printing nodes in ascending order.
     * Each node's data is printed to `std::cout`.
     */
    inline void print_tree() const;
};

#include "../source/binary_search_tree.tpp"

#endif // BINARY_SEARCH_TREE_H
