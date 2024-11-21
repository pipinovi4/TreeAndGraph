#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#pragma once
#include "../../Nodes/BPTreeNodes/b_plus_tree_node.h"
#include <cstddef>
#include <vector>

/**
 * @class BPTree
 * @brief Represents a B+ Tree data structure, widely used in databases and file systems.
 *
 * A B+ Tree is a balanced tree data structure that maintains sorted data and allows
 * efficient insertion, deletion, and search operations. All keys are stored in the leaf
 * nodes, which are linked for efficient range queries.
 */
class BPTree {
public:
    BPTreeNode* _root; ///< Pointer to the root node of the B+ Tree.
    size_t _t;         ///< Minimum degree of the B+ Tree (defines node capacity).

    /**
     * @brief Constructs a B+ Tree with a specified minimum degree.
     * @param t Minimum degree of the tree. Each node can have at most `2*t - 1` keys
     * and at least `t - 1` keys (except for the root).
     */
    inline explicit BPTree(size_t t);

    /**
     * @brief Destructor for the B+ Tree. Recursively deletes all nodes to free memory.
     */
    inline ~BPTree();

    /**
     * @brief Inserts a key into the B+ Tree.
     * @param key The key to be inserted.
     *
     * If the key already exists, no action is taken. If a node becomes overfull after
     * the insertion, it is split, and the split may propagate upward.
     */
    inline void insert(int key);

    /**
     * @brief Searches for a key in the B+ Tree.
     * @param key The key to search for.
     * @return Pointer to the leaf node containing the key, or nullptr if the key is not found.
     */
    inline BPTreeNode* search(int key) const;

    /**
     * @brief Removes a key from the B+ Tree.
     * @param key The key to be removed.
     *
     * Handles underflow by borrowing or merging nodes as necessary to maintain the
     * B+ Tree properties.
     */
    inline void remove(int key);

    /**
     * @brief Performs a range query to find all keys within a specified range.
     * @param start_key The lower bound of the range (inclusive).
     * @param end_key The upper bound of the range (inclusive).
     * @return A vector containing all keys within the specified range.
     *
     * The range query leverages the linked list of leaf nodes for efficient traversal.
     */
    inline std::vector<int> rangeQuery(int start_key, int end_key) const;

    /**
     * @brief Prints the B+ Tree in level-order for debugging or visualization.
     *
     * Each level of the tree is displayed on a separate line, with the keys of each node
     * enclosed in square brackets.
     */
    inline void printTree() const;

private:
    /**
     * @brief Fixes a child node that has fewer keys than required after a deletion.
     * @param parent Pointer to the parent node of the underfull child.
     * @param index Index of the child in the parent's `_children` vector.
     *
     * Attempts to borrow keys from siblings or merges the underfull node with a sibling
     * to restore the B+ Tree properties.
     */
    inline void _fixChild(BPTreeNode* parent, size_t index);

    /**
     * @brief Merges two sibling nodes and updates the parent node.
     * @param parent Pointer to the parent node containing the keys and children to be merged.
     * @param index Index of the first child to be merged in the parent's `_children` vector.
     *
     * After merging, the parent is updated, and the right child is deleted.
     */
    static inline void _mergeNodes(BPTreeNode* parent, int index);
};

#include "b_plus_tree.tpp"

#endif // B_PLUS_TREE_H
