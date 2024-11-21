#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#pragma once
#include "../../Nodes/defaultNodes/node.h"
#include <vector>

/**
 * SplayTree class
 *
 * A self-adjusting binary search tree with the additional property that
 * recently accessed elements are moved closer to the root to improve
 * subsequent access efficiency. This is achieved using splay operations.
 *
 * Supported Operations:
 * 1. `search`: Searches for an element and splays the tree.
 * 2. `insert`: Inserts a new element while maintaining tree structure.
 * 3. `remove`: Deletes an element and rebalances the tree.
 * 4. `inorder`: Traverses the tree in sorted order (in-order traversal).
 */
class SplayTree {
public:
    /**
     * Constructor: Initializes an empty Splay Tree.
     */
    SplayTree();

    /**
     * Destructor: Frees up all dynamically allocated nodes.
     */
    ~SplayTree();

    /**
     * Search for a node with the specified value.
     *
     * If the value exists, the node containing the value is splayed to the root.
     * If the value does not exist, the closest node is splayed to the root.
     *
     * @param data The value to search for.
     * @return A pointer to the node containing the value, or nullptr if not found.
     */
    Node* search(int data);

    /**
     * Insert a new value into the tree.
     *
     * If the value already exists, no changes are made. The inserted value
     * will be splayed to the root.
     *
     * @param data The value to insert into the tree.
     */
    void insert(int data);

    /**
     * Remove a value from the tree.
     *
     * If the value exists, it is removed, and the tree is restructured
     * to maintain its properties. If the value does not exist, no changes
     * are made.
     *
     * @param data The value to remove from the tree.
     */
    void remove(int data);

    /**
     * Perform an in-order traversal of the tree.
     *
     * In-order traversal visits the nodes in sorted order (left, root, right).
     * The result is appended to the provided vector.
     *
     * @param node The starting node for traversal (typically the root).
     * @param result A reference to a vector to store the traversal result.
     */
    std::vector<int> inorder();

private:
    Node* _root; ///< Pointer to the root of the tree.

    /**
     * Perform a splay operation on the tree.
     *
     * Moves the node containing the specified value to the root of the tree.
     * If the value does not exist, the closest node is moved to the root.
     *
     * @param node The current root of the subtree.
     * @param data The value to splay.
     * @return A pointer to the new root of the subtree.
     */
    Node* _splay(Node* node, int data);

    /**
     * Perform a left rotation on the given node.
     *
     * The right child becomes the new root of the subtree, and the current
     * root becomes its left child.
     *
     * @param node The node to perform the left rotation on.
     * @return A pointer to the new root of the subtree.
     */
    Node* _leftRotation(Node* node);

    /**
     * Perform a right rotation on the given node.
     *
     * The left child becomes the new root of the subtree, and the current
     * root becomes its right child.
     *
     * @param node The node to perform the right rotation on.
     * @return A pointer to the new root of the subtree.
     */
    Node* _rightRotation(Node* node);
};

#include "splay_tree.tpp"

#endif // SPLAY_TREE_H
