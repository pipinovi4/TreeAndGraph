#ifndef TREAP_NODE_H
#define TREAP_NODE_H

#pragma once
#include <random>

/**
 * @class TreapNode
 * @brief Represents a node in a Treap data structure.
 *
 * A Treap is a randomized binary search tree that maintains a heap property based on node priorities.
 * Each node contains a key, a priority, and pointers to its left and right children.
 */
class TreapNode {
public:
    int key;       /**< The key value of the node. */
    int priority;  /**< The priority value of the node, used to maintain heap property. */
    TreapNode* left;   /**< Pointer to the left child node. */
    TreapNode* right;  /**< Pointer to the right child node. */

    /**
     * @brief Constructs a TreapNode with a specified key and priority.
     *
     * @param key The key value of the node.
     * @param priority The priority value of the node.
     * @param min The minimum value for the random priority (default is 1).
     * @param max The maximum value for the random priority (default is 100).
     *
     * If the provided priority is within the range [min, max], it is assigned to the node.
     * Otherwise, a random priority within the specified range is generated.
     */
    inline explicit TreapNode(const int& key, const int& priority, const int& min = 1, const int& max = 100);

private:
    /**
     * @brief Generates a random integer within a specified range.
     *
     * @param min The minimum value of the range (inclusive).
     * @param max The maximum value of the range (inclusive).
     * @return A random integer between min and max.
     *
     * This function is used to assign a random priority to a node if no valid priority is provided.
     */
    static int getRandomInt(const int& min = 1, const int& max = 100);
};

#include "treap_node.tpp"

#endif // TREAP_NODE_H
