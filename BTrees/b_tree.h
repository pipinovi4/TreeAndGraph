#ifndef B_TREE_H
#define B_TREE_H

#include "../Nodes/BTreeNodes/b_tree_node.h"

/**
 * @class BTree
 * @brief Implements a B-Tree, a self-balancing tree data structure used for efficient
 * storage and retrieval of large datasets.
 *
 * B-Trees maintain sorted data in a way that allows for efficient insertion, deletion,
 * and search operations. Each node in a B-Tree can contain multiple keys and has a flexible number
 * of child nodes within a defined range, determined by the tree's minimum degree `t`. This structure
 * enables the B-Tree to remain balanced, minimizing the height and allowing for quick access to any element.
 *
 * The BTree class contains the root node and manages tree-wide operations such as insertion, deletion, and
 * searching for keys. Nodes within the B-Tree are represented by instances of the `BTreeNode` class.
 */
class BTree {
public:
    /**
     * @brief Constructs a BTree with a specified minimum degree.
     * @param t The minimum degree of the B-Tree, defining the minimum and maximum number of children per node.
     *
     * Each node (except the root) contains at least `t-1` keys and at most `2t-1` keys. The root may contain fewer than `t-1` keys.
     */
    inline explicit BTree(const int& t);

    /**
     * @brief Destructor for BTree, which recursively deallocates all nodes within the tree.
     */
    inline ~BTree();

    /**
     * @brief Inserts a key into the B-Tree while maintaining the B-Tree properties.
     * @param key The key to insert.
     *
     * If the root node becomes full during insertion, it is split, and a new root is created,
     * increasing the height of the tree. This process ensures that the B-Tree remains balanced.
     */
    inline void insert(const int& key);

    /**
     * @brief Searches for a key in the B-Tree.
     * @param key The key to search for.
     * @return Pointer to the node containing the key if found, or nullptr if the key does not exist.
     *
     * The search operation begins at the root and traverses down the tree, following the appropriate child pointers
     * based on key comparisons. This enables efficient searching in O(log n) time.
     */
    inline BTreeNode* search(const int& key) const;

    /**
     * @brief Removes a key from the B-Tree, preserving the B-Tree properties.
     * @param key The key to remove.
     *
     * If the key is in a leaf node, it is removed directly. If the key is in an internal node, it is replaced by either
     * its predecessor or successor to maintain the B-Tree properties. Nodes are merged or keys are borrowed as necessary
     * to ensure no node (except the root) contains fewer than `t-1` keys after deletion.
     */
    inline void remove(const int& key);

    /**
     * @brief Prints the B-Tree level by level, showing the keys at each level.
     *
     * This method provides a visual overview of the B-Tree structure, which is helpful for understanding
     * the hierarchical organization of keys and for debugging purposes. Each level's keys are printed in order.
     */
    inline void printTree() const;

private:
    BTreeNode* _root;  ///< Pointer to the root node of the B-Tree.
    int _t;            ///< Minimum degree of the B-Tree, affecting the number of keys per node.
};

#include "b_tree.tpp"

#endif //B_TREE_H
