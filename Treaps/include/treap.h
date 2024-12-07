#ifndef TREAP_H
#define TREAP_H

#pragma once
#include "../../Nodes/TreapNode/treap_node.h"

/**
 * @class Treap
 * @brief A data structure that combines a Binary Search Tree (BST) and a heap.
 *
 * The Treap maintains BST properties for keys while ensuring the heap property
 * for priorities. This implementation supports search, insertion, and deletion
 * operations. Rotations are used to balance the tree while preserving its properties.
 */
class Treap {
public:
    /**
     * @brief Constructor for the Treap class.
     *
     * Initializes an empty Treap with no root node.
     */
    Treap();

    /**
     * @brief Destructor for the Treap class.
     *
     * Cleans up memory allocated for the Treap nodes.
     */
    ~Treap();

    /**
     * @brief Search for a key in the Treap.
     *
     * @param key The key to search for.
     * @return True if the key is found, otherwise false.
     */
    bool search(const int& key);

    /**
     * @brief Insert a key into the Treap.
     *
     * If the key already exists, no action is taken. If no priority is provided,
     * a unique priority is generated.
     *
     * @param key The key to insert.
     * @param priority (Optional) The priority associated with the key.
     */
    void insert(const int& key, const int* priority = nullptr);

    /**
     * @brief Remove a key from the Treap.
     *
     * @param key The key to remove. If the key does not exist, no action is taken.
     */
    void remove(const int& key);

private:
    TreapNode* _root; /**< Pointer to the root node of the Treap. */
    int _priority_counter; /**< Counter for generating unique priorities. */

    /**
     * @brief Perform a left rotation at the given node.
     *
     * @param node The node where the left rotation is performed.
     * @return The new root of the rotated subtree.
     */
    TreapNode* _leftRotation(TreapNode* node);

    /**
     * @brief Perform a right rotation at the given node.
     *
     * @param node The node where the right rotation is performed.
     * @return The new root of the rotated subtree.
     */
    TreapNode* _rightRotation(TreapNode* node);

    /**
     * @brief Generate a unique priority for a node.
     *
     * If a base priority is provided, it will be used as the starting point for
     * generating the unique priority.
     *
     * @param basedPriority (Optional) Pointer to the base priority value.
     * @return A unique integer priority.
     */
    int _generateUniquePriority(int* basedPriority = nullptr);
};

#include "../source/treap.tpp"

#endif //TREAP_H
