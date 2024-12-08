#ifndef AVL_TREE_H
#define AVL_TREE_H

#pragma once
#include "../../../Nodes/defaultNodes/node.h"
#include <cstddef>

/**
 * @class AVLTree
 * @brief A class representing an AVL (Adelson-Velsky and Landis) Tree, a self-balancing binary search tree.
 *
 * The AVL Tree ensures that the height difference (balance factor) between the left and right subtrees of
 * each node is no more than one, maintaining balanced height. This guarantees O(log n) time complexity
 * for insertion, deletion, and search operations, making it efficient for dynamic sets where elements
 * are inserted or deleted frequently.
 */
class AVLTree {
public:
    /**
     * @brief Constructor for AVLTree. Initializes an empty AVL tree.
     */
    inline AVLTree();

    /**
     * @brief Destructor for AVLTree. Cleans up and deallocates all nodes in the tree.
     */
    ~AVLTree();

    /**
     * @brief Inserts a new value into the AVL tree and maintains its balance.
     * @param data The value to insert into the AVL tree.
     */
    inline void insert(int data);

    /**
     * @brief Searches for a specified value in the AVL tree.
     * @param target The value to search for.
     * @return true if the value exists in the tree; false otherwise.
     */
    inline bool search(int target) const;

    /**
     * @brief Removes a specified value from the AVL tree and rebalances if necessary.
     * @param data The value to delete from the AVL tree.
     */
    inline void remove(int data);

    /**
     * @brief Performs an in-order traversal of the AVL tree and prints each node's value.
     *
     * In-order traversal visits nodes in sorted order, from smallest to largest.
     */
    inline void printInOrder() const;

private:
    /**
     * @brief Root node of the AVL tree.
     */
    Node* root;

    /**
     * @brief Calculates the height of a given node.
     * @param node Pointer to the node whose height is calculated.
     * @return The height of the node; returns 0 if the node is nullptr.
     */
    static inline size_t _height(const Node* node);

    /**
     * @brief Updates the height of a given node based on its children's heights.
     * @param node Pointer to the node whose height is updated.
     */
    static inline void _updateHeight(Node* node);

    /**
     * @brief Calculates the balance factor of a given node.
     * @param node Pointer to the node whose balance factor is calculated.
     * @return The balance factor (difference in height between left and right subtrees).
     */
    static inline int _getBalance(const Node* node);

    /**
     * @brief Performs a right rotation on the subtree rooted at a specified node.
     * @param y The root of the subtree to rotate.
     * @return New root of the rotated subtree.
     */
    static inline Node* _rightRotation(Node* y);

    /**
     * @brief Performs a left rotation on the subtree rooted at a specified node.
     * @param x The root of the subtree to rotate.
     * @return New root of the rotated subtree.
     */
    static inline Node* _leftRotation(Node* x);
};

#include "../source/avl_tree.tpp"

#endif // AVL_TREE_H
