#ifndef B_PLUS_TREE_NODE_H
#define B_PLUS_TREE_NODE_H

#pragma once

#include <vector>

/**
 * @class BPTreeNode
 * @brief Represents a node in a B+ Tree data structure.
 *
 * A `BPTreeNode` is a building block of a B+ Tree, which is commonly used in databases and file systems
 * to efficiently store and retrieve data. Each node can hold multiple keys and, if not a leaf, pointers
 * to child nodes. Leaf nodes are linked to allow fast range queries.
 */
class BPTreeNode {
public:
    size_t _t;  ///< Minimum degree of the B+ Tree node. This defines the range of the number of keys.
    bool _is_leaf;  ///< Boolean indicating if this node is a leaf (true if leaf, false if internal).
    std::vector<int> _keys;  ///< Vector storing keys in the node, sorted in ascending order.
    std::vector<BPTreeNode*> _children;  ///< Vector storing pointers to child nodes (only used if not a leaf).
    BPTreeNode* _parent;  ///< Pointer to the parent node (for propagating above in hierarchy)
    BPTreeNode* _next;  ///< Pointer to the next leaf node (used for range queries in leaf nodes).

    /**
     * @brief Constructs a B+ Tree node with the given minimum degree and leaf status.
     * @param t Minimum degree of the B+ Tree node.
     * @param is_leaf Boolean indicating if the node is a leaf (default is false).
     */
    inline explicit BPTreeNode(size_t t, bool is_leaf = false, BPTreeNode* parent = nullptr);

    /**
     * @brief Inserts a key into the node if it is not full.
     *
     * If the node is a leaf, the key is inserted directly. If it is an internal node,
     * the method descends to the appropriate child node to perform the insertion.
     * @param key The key to insert into the node.
     */
    inline void insertNonFull(int key);

    /**
     * @brief Splits a full child node to ensure the B+ Tree properties are maintained.
     *
     * When a child node is full (has the maximum number of keys), this function splits it into two nodes.
     * The middle key is moved up to the current node, and the children are adjusted accordingly.
     * @param i Index of the child to be split.
     */
    inline void splitChildren(size_t i);
};

#include "b_plus_tree_node.tpp"

#endif // B_PLUS_TREE_NODE_H
