# PerfectBinaryTree Documentation

## Overview

A **Perfect Binary Tree** is a type of binary tree where all interior nodes have two children and all leaves are at the same level. This structure is highly efficient for certain applications, such as in full tree traversals and heap implementations.

## Core Structure

- **Root Node**: The topmost node in the tree, which serves as the starting point.
- **Levels**:
  - All levels are completely filled with nodes.
  - Every node has either two children or is a leaf node at the last level.

## Key Operations

1. **Tree Creation**:
   - Nodes are inserted such that the tree remains perfect, filling each level completely before moving to the next.
   - Nodes can be built from a provided array of data and a specified depth.

2. **Traversal**:
   - **In-order**: Traverse the left subtree, visit the node, then traverse the right subtree.
   - **Pre-order**: Visit the node, then traverse the left and right subtrees.
   - **Post-order**: Traverse the left and right subtrees before visiting the node.
   - **Level-order**: Visit nodes from left to right on each level, which aligns with the insertion order.

3. **Node Insertion**:
   - Nodes are inserted from a given array, ensuring that the tree remains perfect.
   - If a node is created, it will always have two children if it is not a leaf.

4. **Node Search**:
   - A search operation traverses the tree recursively to find a specific node.

5. **Node Printing**:
   - Level-order traversal is typically used to print nodes in the structure, showing them from top to bottom and left to right.

## Example Structure

A basic perfect binary tree:      1
                                /   \
                               2     3
                              / \   / \
                             4   5 6   7


In this example:
- `1` is the root.
- Nodes `2` and `3` are children of `1`.
- Nodes `4`, `5`, `6`, and `7` are leaf nodes, filling the tree completely.

## Complexity

- **Time Complexity**:
  - **Insertion**: `O(n)` for inserting nodes in level order, where `n` is the number of nodes.
  - **Traversal**: `O(n)` for all traversal types, since each node is visited once.

- **Space Complexity**:
  - **Tree Structure**: `O(n)`, where `n` is the total number of nodes.
  - **Traversal Auxiliary Space**: `O(h)`, where `h` is the height of the tree, for stack space during recursive traversal.

## Summary

A `PerfectBinaryTree` is a specialized type of binary tree that is fully balanced, ensuring efficient data organization and access. It is particularly useful in scenarios where complete data structures are essential, such as in heap-based algorithms.
