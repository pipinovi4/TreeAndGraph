#ifndef SEGMENT_TREE_TPP
#define SEGMENT_TREE_TPP

#include "segment_tree.h"

template <typename T>
SegmentTree<T>::SegmentTree(const std::vector<T>& data, std::function<T(T, T)> func, T* identity)
    : _func(func), identity(identity), _n(data.size()), _tree(2 * data.size(), identity) {
    // Build the tree during construction
    _build(data);
}

template <typename T>
void SegmentTree<T>::_build(std::vector<T> data) {
    // Initialize the leaves with the input data
    for (int i = 0; i < _n; i++) {
        _tree[_n + i] = data[i];
    }

    // Build the internal nodes in a bottom-up manner
    for (int i = _n - 1; i > 0; i--) {
        _tree[i] = _func(_tree[2 * i], _tree[2 * i + 1]);
    }
}

template <typename T>
void SegmentTree<T>::update(int index, const T value) {
    if (index < 0 || index >= _n) {
        throw std::out_of_range("Index out of bounds");
    }

    // Update the corresponding leaf node
    index += _n;
    _tree[index] = value;

    // Propagate changes up to the root
    while (index > 1) {
        index /= 2;
        _tree[index] = _func(_tree[2 * index], _tree[2 * index + 1]);
    }
}

template <typename T>
T SegmentTree<T>::query(int left, int right) {
    if (left < 0 || right > _n || left >= right) {
        throw std::out_of_range("Invalid query range");
    }

    // Map the range to corresponding leaf nodes
    left += _n;
    right += _n;

    T result = identity; // Initialize result with identity value

    while (left < right) {
        // If left is a right child, include it in the result
        if (left % 2 == 1) {
            result = _func(result, _tree[left]);
            left++;
        }
        // If right is a right child, include it in the result
        if (right % 2 == 1) {
            right--;
            result = _func(result, _tree[right]);
        }

        // Move to the parent nodes
        left = std::floor(left / 2);
        right = std::floor(right / 2);
    }

    return result; // Return the final result
}

#endif // SEGMENT_TREE_TPP
