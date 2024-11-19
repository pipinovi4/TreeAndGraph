#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include "cstddef"
#include "vector"

/// @class FenwickTree
/// @brief A Fenwick Tree (Binary Indexed Tree) implementation for efficient prefix sum queries and updates.
class FenwickTree {
public:
    /// @brief Internal data structure to store the tree.
    std::vector<int> _tree;

    /// @brief The size of the Fenwick Tree.
    size_t _size;

    /**
     * @brief Constructor to initialize the Fenwick Tree with a given size.
     * @param size The number of elements in the tree.
     */
    inline explicit FenwickTree(size_t size);

    /**
     * @brief Updates the Fenwick Tree by adding a delta value to a specific index.
     *
     * This method updates the tree to reflect the addition of `delta` at `index`.
     * @param index The index to update (0-based).
     * @param delta The value to add to the index.
     */
    inline void update(size_t index, int delta);

    /**
     * @brief Queries the prefix sum from index 0 to the given index.
     *
     * This method retrieves the cumulative sum from the start of the tree
     * up to the specified index.
     * @param index The end index (0-based) of the prefix sum query.
     * @return The sum of elements from index 0 to `index`.
     */
    inline int query(size_t index) const;

    /**
     * @brief Queries the sum of a range [left, right].
     *
     * This method retrieves the sum of elements within the specified range
     * using two prefix sum queries.
     * @param left The starting index of the range (0-based).
     * @param right The ending index of the range (0-based).
     * @return The sum of elements in the range [left, right].
     */
    inline int range_query(int left, int right) const;

    /**
     * @brief Builds a Fenwick Tree from a given data array.
     *
     * This static method initializes and constructs a Fenwick Tree based on
     * the input data, precomputing the necessary values for the tree.
     * @param data The input array to build the tree from.
     * @return A FenwickTree instance containing the built tree.
     */
    static inline FenwickTree build(const std::vector<int>& data);
};

#include "fenwick_tree.tpp"

#endif //FENWICK_TREE_H
