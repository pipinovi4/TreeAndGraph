# FullBinaryTree Documentation

## Overview

A **Full Binary Tree** is a binary tree where each node has either zero or exactly two children. This structure is efficient for organizing data in a symmetrical, hierarchical format.

## Core Structure

- **Root Node**: The starting point of the tree.
- **Children Nodes**: Each node has:
  - **Zero Children**: Leaf nodes with no branches.
  - **Two Children**: Nodes with exactly two branches, maintaining the "full" property.

## Key Operations

1. **Tree Creation**: Connects each node to two children until the desired structure is reached, with no nodes having only one child.

2. **Traversal**:
   - **Pre-order**: Visit the node, then its children (root-left-right).
   - **In-order**: Visit left child, node, then right child.
   - **Post-order**: Visit children before the node.

3. **Node Printing**: Traversal methods allow printing of node values in a defined order. Pre-order prints nodes from root to leaves.

## Example Structure

A basic full binary tree:    1
                            / \
                           2   3
                          / \ / \
                         4  5 6  7


Here:
- `1` is the root.
- `2` and `3` are children of `1`.
- `4`, `5`, `6`, and `7` are leaf nodes.

## Complexity

- **Time Complexity**:
  - **Insertion**: `O(log n)` if the tree maintains a balanced structure.
  - **Traversal**: `O(n)` for pre-order, in-order, and post-order traversals since each node is visited once.

- **Space Complexity**:
  - **Tree Structure**: `O(n)`, where `n` is the total number of nodes, as each node requires storage.
  - **Traversal Auxiliary Space**: `O(h)`, where `h` is the tree height, representing stack space in recursive traversal or queue space in iterative traversal.

## Summary

A `FullBinaryTree` is ideal for organizing hierarchical data where each node has a clear, fixed structure.
 It is beneficial for cases requiring balanced, symmetrical layouts, with traversal options to manage and display node data in specific orders.
