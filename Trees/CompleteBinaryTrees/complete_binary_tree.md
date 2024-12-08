# CompleteBinaryTree Documentation

## Overview

A **Complete Binary Tree** is a binary tree in which all levels are fully filled, except possibly the last level, which is filled from left to right. This structure is commonly used in applications where a balanced and efficient data structure is needed, such as binary heaps.

## Core Structure

- **Root Node**: The topmost node in the tree, serving as the starting point.
- **Levels**:
  - All levels are completely filled except possibly the last level.
  - In the last level, nodes are filled from left to right without any gaps.

## Key Operations

1. **Tree Creation**: Nodes are inserted level-by-level to maintain the complete structure. Each new node fills the next available position from left to right.

2. **Traversal**:
   - **Level-order**: Visit nodes from left to right on each level, which aligns with the insertion order in a complete binary tree.
   - **Pre-order**: Visit the root, then recursively traverse the left and right children.
   - **In-order**: Recursively visit the left child, then the node, followed by the right child.
   - **Post-order**: Recursively visit the left and right children before visiting the node.

3. **Node Insertion**:
   - Nodes are inserted to maintain completeness, filling each level from left to right.
   - If the current level is filled, a new level is started.

4. **Node Search**:
   - A search operation traverses the tree, often level-by-level, to find a specific node.

5. **Node Printing**: A level-order traversal is typically used to print nodes, as it shows the structure from top to bottom, left to right.

## Example Structure

A basic complete binary tree:    1
                                / \
                               2   3
                              / \ /
                             4 5 6

In this example:

- `1` is the root.
- Nodes `2` and `3` are children of `1`.
- Nodes `4`, `5`, and `6` fill the tree from left to right, maintaining completeness.

If a new node (e.g., `7`) is added, it will become the right child of node `3`, completing the last level.

## Complexity

- **Time Complexity**:
  - **Insertion**: `O(log n)` because a complete binary tree maintains balance as it grows.
  - **Traversal**: `O(n)` for all traversal types (level-order, pre-order, in-order, post-order), as each node is visited once.

- **Space Complexity**:
  - **Tree Structure**: `O(n)`, where `n` is the total number of nodes.
  - **Traversal Auxiliary Space**: `O(h)`, where `h` is the tree height, for stack or queue space during traversal.

## Summary

A `CompleteBinaryTree` is efficient for hierarchical data that requires a balanced structure, making it ideal for applications like binary heaps. It maintains balance by filling nodes from left to right at each level, optimizing both insertion and search operations.
