#ifndef FENWICK_TREE_TPP
#define FENWICK_TREE_TPP

#include "fenwick_tree.h"

// Constructor to initialize the Fenwick Tree with the given size.
FenwickTree::FenwickTree(const size_t size) {
    _size = size;  // Set the size of the tree.
    _tree.resize(size + 1, 0);  // Initialize the tree with zeros. +1 because Fenwick Tree is 1-indexed.
}

// Updates the Fenwick Tree at the given index by adding delta to it.
void FenwickTree::update(size_t index, const int delta) {
    // Traverse and update all relevant nodes in the tree.
    while (index <= _size) {
        _tree[index] += delta;  // Add delta to the current node.
        index += index & -index;  // Move to the next index using the LSB.
    }
}

// Queries the prefix sum from index 1 to the given index.
int FenwickTree::query(size_t index) const {
    int sum_ = 0;  // Initialize sum to 0.
    // Traverse backward through the tree to compute the prefix sum.
    while (index > 0) {
        sum_ += _tree[index];  // Add the value at the current node to the sum.
        index -= index & -index;  // Move to the parent node using the LSB.
    }
    return sum_;  // Return the computed prefix sum.
}

// Queries the sum of the range [left, right].
int FenwickTree::range_query(const int left, const int right) const {
    // Use the difference of two prefix sums to compute the range sum.
    return query(right) - query(left - 1);  // Subtract prefix sum up to left-1 from prefix sum up to right.
}

// Builds a Fenwick Tree from a given data array.
FenwickTree FenwickTree::build(const std::vector<int>& data) {
    const size_t n = data.size();  // Get the size of the input data.
    auto fenwick = FenwickTree(n);  // Initialize a Fenwick Tree of the same size.

    // Populate the Fenwick Tree using the input data.
    for (int i = 1; i < n; i++) {  // Start from 1 because Fenwick Tree is 1-indexed.
        fenwick.update(i, data[i]);  // Update the tree with the value at index i.
    }
    return fenwick;  // Return the constructed Fenwick Tree.
}

#endif //FENWICK_TREE_TPP
