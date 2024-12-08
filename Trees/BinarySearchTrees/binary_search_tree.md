# Binary Search Tree Documentation

## Overview

A **Binary Search Tree (BST)** is a data structure that facilitates fast lookup, addition, and removal of elements. It is a type of binary tree where each node has at most two children, and for any given node, the values in the left subtree are less than the node's value, while the values in the right subtree are greater than the node's value. This property allows for efficient searching, insertion, and deletion operations.

## Core Structure

- **Node**: The fundamental component of the tree, containing:
  - **Data**: The value stored in the node.
  - **Left Child**: A pointer/reference to the left subtree (lesser values).
  - **Right Child**: A pointer/reference to the right subtree (greater values).

- **Root**: The topmost node in the tree, from which all operations begin.

## Key Operations

1. **Insertion**:
   - Adds a new value to the tree while maintaining the BST properties.
   - If the tree is empty, the new value becomes the root.
   - For each subsequent value, traverse the tree and place the new value in the appropriate left or right position.

2. **Searching**:
   - To find a value, start at the root and compare the value to be found with the current node's value.
   - If it matches, the search is successful.
   - If it is less than the current node's value, continue searching in the left subtree; if greater, search the right subtree.
   - This process continues recursively until the value is found or a leaf node is reached.

3. **Deletion**:
   - Remove a value from the tree while preserving its structure and properties.
   - There are three cases:
     - **Node with no children**: Simply remove the node.
     - **Node with one child**: Remove the node and link its parent directly to its child.
     - **Node with two children**: Find the node's in-order successor (the smallest value in the right subtree), replace the node's value with this successor, and then delete the successor.

4. **Traversal**:
   - Various methods to traverse and access all nodes in the tree:
     - **In-order**: Visit the left subtree, the node, then the right subtree (produces sorted order).
     - **Pre-order**: Visit the node, then traverse the left and right subtrees.
     - **Post-order**: Traverse the left and right subtrees before visiting the node.
     - **Level-order**: Visit nodes from left to right on each level, which aligns with the insertion order.

## Example Structure

A basic Binary Search Tree:      15
                                / \
                               10  20
                              / \ / \
                             8 12 17 25

In this example:
- `5` is the root node.
- Nodes `3` and `7` are the children of `5`.
- Nodes `2`, `4`, `6`, and `8` are the leaf nodes.

## Complexity

- **Time Complexity**:
  - **Insertion**: Average case `O(log n)`; worst case `O(n)` if the tree becomes unbalanced.
  - **Search**: Average case `O(log n)`; worst case `O(n)`.
  - **Deletion**: Average case `O(log n)`; worst case `O(n)`.

- **Space Complexity**:
  - **Tree Structure**: `O(n)`, where `n` is the number of nodes, as each node needs space.
  - **Call Stack Space**: `O(h)` for recursive operations, where `h` is the height of the tree.

## Summary

A **Binary Search Tree** is a powerful data structure that allows for efficient insertion, searching, and deletion of values. It maintains a sorted order of elements, making it ideal for applications that require frequent lookups and ordered data. The performance of BST operations can be greatly affected by the shape of the tree, emphasizing the importance of balance for optimal performance.
