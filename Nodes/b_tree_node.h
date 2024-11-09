#ifndef B_TREE_NODE_H
#define B_TREE_NODE_H

#pragma once
#include <vector>

/**
 * @class BTreeNode
 * @brief Represents a node in a B-Tree.
 *
 * A BTreeNode class is used within a B-Tree data structure to store keys and child pointers.
 * This class supports operations such as adding and removing keys, checking if the node is full, and
 * storing child pointers for non-leaf nodes.
 */
class BTreeNode {
public:
    /**
     * @brief Constructor for BTreeNode.
     * @param is_leaf Indicates if the node is a leaf node.
     *
     * Initializes a BTreeNode as a leaf or internal node. Leaf nodes do not have child pointers,
     * while internal nodes may contain child pointers.
     */
    inline explicit BTreeNode(bool is_leaf);

    /**
     * @brief Destructor for BTreeNode.
     *
     * Cleans up any resources associated with the BTreeNode, if needed.
     * The destructor is currently default as no dynamic memory allocation is done in the node.
     */
    inline ~BTreeNode();

    bool is_leaf;                   ///< Indicates whether the node is a leaf.
    std::vector<int> keys;          ///< Stores the keys present in the node.
    std::vector<BTreeNode*> children;      ///< Stores child pointers for internal nodes. Empty if node is a leaf.

    /**
     * @brief Adds a key to the node in sorted order.
     * @param key The key to add to the node.
     *
     * Inserts a new key into the node's key list, maintaining sorted order.
     */
    inline void addKey(int key);

    /**
     * @brief Removes a specified key from the node.
     * @param key The key to remove from the node.
     *
     * Searches for the specified key and removes it from the node's key list if found.
     */
    inline void removeKey(int key);

    /**
     * @brief Checks if the node has reached the maximum allowed number of keys.
     * @param max_keys The maximum number of keys allowed in the node.
     * @return True if the node contains the maximum number of keys, false otherwise.
     *
     * Determines if the node is full based on the specified `max_keys` limit, which is necessary
     * to know when the node needs to be split in a B-Tree.
     */
    inline bool isFull(int max_keys) const;
};

#include "b_tree_node.tpp"

#endif // B_TREE_NODE_H
