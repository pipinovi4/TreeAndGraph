#ifndef TREAP_H
#define TREAP_H

#pragma once
#include "../../../Nodes/TreapNode/treap_node.h"
#include <vector>
#include <string>

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
     * Initializes an empty Treap with no root node and sets the priority counter to zero.
     */
    Treap();

    /**
     * @brief Destructor for the Treap class.
     *
     * Cleans up memory allocated for the Treap nodes by performing a post-order traversal.
     */
    ~Treap();

    /**
     * @brief Search for a key in the Treap.
     *
     * @param key The key to search for.
     * @return True if the key is found, otherwise false.
     *
     * @note The search operation maintains O(log n) complexity on average.
     */
    bool search(const int& key);

    /**
     * @brief Insert a key into the Treap.
     *
     * If the key already exists, no action is taken. If no priority is provided,
     * a unique priority is generated automatically.
     *
     * @param key The key to insert.
     * @param priority (Optional) The priority associated with the key.
     *
     * @note The insertion operation maintains the Treap's BST and heap properties by performing rotations if needed.
     */
    void insert(const int& key, const int priority = -1);

    /**
     * @brief Remove a key from the Treap.
     *
     * Deletes the node with the specified key, if it exists, and rebalances the Treap accordingly.
     *
     * @param key The key to remove.
     *
     * @note The removal operation maintains the Treap's properties by performing rotations if needed.
     */
    void remove(const int& key);

    /**
     * @brief Perform an in-order traversal of the Treap.
     *
     * @return A vector of pairs where each pair contains a key and its corresponding priority.
     *
     * @note The in-order traversal returns the nodes in sorted order based on their keys.
     */
    std::vector<std::pair<int, int>> inorder();

    /**
     * @brief Print the Treap structure for debugging purposes.
     *
     * Displays the Treap with indentation to represent different levels and prefixes to indicate the role of each node.
     */
    void printTree();

private:
    TreapNode* _root;            /**< Pointer to the root node of the Treap. */
    int _priority_counter;       /**< Counter for generating unique priorities. */

    /**
     * @brief Perform a left rotation at the given node.
     *
     * A left rotation is performed to maintain the heap property when the right child has a higher priority.
     *
     * @param node The node where the left rotation is performed.
     * @return The new root of the rotated subtree.
     *
     * @note This operation is used during insertions and deletions to restore the Treap's properties.
     */
    TreapNode* _leftRotation(TreapNode* node);

    /**
     * @brief Perform a right rotation at the given node.
     *
     * A right rotation is performed to maintain the heap property when the left child has a higher priority.
     *
     * @param node The node where the right rotation is performed.
     * @return The new root of the rotated subtree.
     *
     * @note This operation is used during insertions and deletions to restore the Treap's properties.
     */
    TreapNode* _rightRotation(TreapNode* node);

    /**
     * @brief Generate a unique priority for a node.
     *
     * A random priority between 1 and 1,000,000 is generated.
     *
     * @return A unique integer priority.
     *
     * @note Ensures that each node has a unique priority to avoid collisions.
     */
    int _generateUniquePriority();

    /**
     * @struct StackNode
     * @brief A helper structure to represent a node during the iterative tree traversal.
     *
     * Contains the node pointer, the current level in the tree, and a prefix string for visualization.
     */
    struct StackNode {
        TreapNode* node;     /**< Pointer to the current Treap node. */
        int level;           /**< The current level of the node in the tree. */
        std::string prefix;  /**< The prefix indicating the role of the node (e.g., "Root: ", "L--- ", "R--- "). */

        /**
         * @brief Constructor for the StackNode struct.
         *
         * @param n Pointer to the Treap node.
         * @param l The level of the node in the tree.
         * @param p The prefix string indicating the role of the node.
         */
        StackNode(TreapNode* n, int l, std::string p) : node(n), level(l), prefix(p) {}
    };
};

// Include the implementation of the Treap class template
#include "../source/treap.tpp"

#endif // TREAP_H
