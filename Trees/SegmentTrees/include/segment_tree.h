#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#pragma once
#include <vector>
#include <functional>
#include <cmath>

/**
 * SegmentTree class
 *
 * A generic implementation of a segment tree for efficient range queries and point updates.
 * The segment tree is a flat array representation designed to handle associative operations
 * such as minimum, maximum, or sum queries over a specified range in logarithmic time.
 *
 * @tparam T - The type of elements stored in the segment tree (e.g., int, float, double).
 */
template <typename T>
class SegmentTree {
public:
    /**
     * Constructor for the SegmentTree.
     *
     * Initializes the segment tree with the input data and builds it in O(n) time.
     * The tree allows efficient range queries and updates.
     *
     * @param data - A vector containing the input array to initialize the segment tree.
     * @param func - An associative function to apply on ranges (e.g., min, max, sum).
     * @param identity - A pointer to the identity value for the given function.
     *                   For example:
     *                     - Infinity for min queries
     *                     - -Infinity for max queries
     *                     - 0 for sum queries
     */
    SegmentTree(const std::vector<T>& data, std::function<T(T, T)> func, T identity = nullptr);

    /**
     * Updates a value at a specific index in the segment tree.
     *
     * Updates the value in the original array and propagates the changes upwards
     * to maintain the correctness of the segment tree.
     *
     * @param index - The index in the original array to update (0-based).
     * @param value - The new value to set at the specified index.
     * @throws std::out_of_range - If the index is out of bounds.
     *
     * Complexity: O(log n)
     */
    void update(int index, T value);

    /**
     * Queries the result of the associative function over a range [left, right).
     *
     * Computes the result of applying the associative function over the specified range.
     *
     * @param left - The start index of the range (inclusive, 0-based).
     * @param right - The end index of the range (exclusive, 0-based).
     * @return T - The result of applying the function over the specified range.
     * @throws std::out_of_range - If the range is invalid or out of bounds.
     *
     * Complexity: O(log n)
     */
    T query(int left, int right);

private:
    int _n;                               // Number of elements in the input array
    T identity;                          // Identity value for the associative function
    std::function<T(T, T)> _func;         // Associative function to combine segments
    std::vector<T> _tree;                 // Flat array representation of the segment tree

    /**
     * Builds the segment tree.
     *
     * Initializes the leaves of the segment tree with the input data and computes
     * internal nodes in a bottom-up approach.
     *
     * @param data - The input array to initialize the tree.
     *
     * Complexity: O(n)
     */
    void _build(std::vector<T> data);
};

#include "../source/segment_tree.tpp"

#endif // SEGMENT_TREE_H
