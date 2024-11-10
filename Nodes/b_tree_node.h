#ifndef B_TREE_NODE_H
#define B_TREE_NODE_H

#pragma once
#include <vector>
#include <cstddef>
#include <stack>

/**
 * @class BTreeNode
 * @brief Represents a single node in a B-tree, a self-balancing tree data structure commonly used in databases and file systems.
 *
 * The BTreeNode class implements the functionality of a node in a B-tree of minimum degree `t`.
 * Each node contains up to `2t - 1` keys and `2t` children pointers, with methods to perform
 * key insertion, deletion, searching, and internal tree balancing operations.
 */
class BTreeNode {
public:
    /**
     * @brief Constructs a BTreeNode with a specified minimum degree and leaf status.
     * @param t Minimum degree of the B-tree (defines the range of keys in the node).
     * @param is_leaf True if the node is a leaf node; false otherwise.
     */
    inline BTreeNode(int t, bool is_leaf);

    /**
     * @brief Destructor to free dynamically allocated memory in the B-tree.
     * Iteratively deallocates child nodes to avoid stack overflow in deep trees.
     */
    inline ~BTreeNode();

    /**
     * @brief Searches for a given key in the B-tree rooted at this node.
     * @param key The key to search for.
     * @return Pointer to the node containing the key, or nullptr if the key is not found.
     */
    inline BTreeNode* search(const int& key);

    /**
     * @brief Removes a key from the subtree rooted at this node.
     * This function handles removal from both leaf and internal nodes, maintaining B-tree properties.
     * @param key The key to be removed.
     */
    inline void remove(const int& key);

    /**
     * @brief Ensures the B-tree property is maintained by filling a child node that has fewer than `t` keys.
     * If the child has too few keys, it borrows from its siblings or merges with an adjacent child.
     * @param idx Index of the child to fill.
     */
    inline void fill(const size_t& idx);

private:
    size_t _t;                    ///< Minimum degree of the B-tree.
    bool _is_leaf;                ///< True if the node is a leaf node.
    std::vector<int> _keys;       ///< Vector of keys stored in this node.
    std::vector<BTreeNode*> _children;  ///< Vector of pointers to child nodes.

    /**
     * @brief Inserts a key into a non-full node.
     * This method assumes the node is not full when called and inserts the key while preserving order.
     * @param key The key to insert.
     */
    inline void insertNonFull(const int& key);

    /**
     * @brief Splits a full child node into two nodes and adjusts the keys and children of this node.
     * This operation is used during insertion when a child node exceeds the maximum number of keys.
     * @param i Index of the child to split.
     * @param y Pointer to the child node to be split.
     */
    inline void splitChild(const int& i, BTreeNode* y);

    /**
     * @brief Finds the index of the first key greater than or equal to a given key.
     * This function is used in search and deletion operations.
     * @param key The key to find.
     * @return Index of the first key greater than or equal to `key`.
     */
    inline size_t findKey(const int& key) const;

    /**
     * @brief Finds the predecessor key of a given index in an internal node.
     * The predecessor is the largest key in the left subtree of the specified index.
     * @param idx Index of the key whose predecessor is needed.
     * @return The predecessor key.
     */
    inline int getPred(const size_t& idx) const;

    /**
     * @brief Finds the successor key of a given index in an internal node.
     * The successor is the smallest key in the right subtree of the specified index.
     * @param idx Index of the key whose successor is needed.
     * @return The successor key.
     */
    inline int getSucc(const size_t& idx) const;

    /**
     * @brief Removes a key from a leaf node.
     * This function is called when the key to be deleted is present in a leaf node.
     * @param idx Index of the key to be removed in the `_keys` vector.
     */
    inline void removeFromLeaf(const size_t& idx);

    /**
     * @brief Removes a key from a non-leaf node, ensuring the B-tree properties remain intact.
     * If the key exists in a non-leaf node, it must be replaced by either its predecessor or successor key.
     * @param idx Index of the key to remove.
     * @param stackNodes Stack to store nodes for iterative removal.
     */
    inline void removeFromNonLeaf(const size_t& idx, std::stack<BTreeNode*>& stackNodes);

    /**
     * @brief Borrows a key from the previous sibling to fill the child node at index `idx`.
     * This operation is used when the child at `idx` has too few keys, and its left sibling can spare a key.
     * @param idx Index of the child node.
     */
    inline void borrowFromPrev(const size_t& idx);

    /**
     * @brief Borrows a key from the next sibling to fill the child node at index `idx`.
     * This operation is used when the child at `idx` has too few keys, and its right sibling can spare a key.
     * @param idx Index of the child node.
     */
    inline void borrowFromNext(const size_t& idx);

    /**
     * @brief Merges a child node with its sibling when both have fewer than `t` keys.
     * After merging, the middle key is moved down from the parent node to the newly merged node.
     * @param idx Index of the child node to merge.
     */
    inline void merge(const size_t& idx);

    /**
     * @brief Prints the keys of the B-tree starting from this node.
     * The tree is printed level by level, useful for debugging and visualizing the tree structure.
     * @param level Starting level for the current node in the tree (default is 0).
     */
    inline void printNode(int level=0) const;
};

#include "b_tree_node.tpp"

#endif // B_TREE_NODE_H
