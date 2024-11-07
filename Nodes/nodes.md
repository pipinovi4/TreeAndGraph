# Node Class Documentation

## Overview

The **Node** class represents an individual element within a binary tree. Each node stores a data value and references to its left and right child nodes, allowing for hierarchical tree structures.

## Attributes

- **data**: The value stored in the node. This can be any data type, depending on the application of the tree.
- **left**: A reference to the left child node. Initially set to `null` or `None`, indicating that the node has no left child.
- **right**: A reference to the right child node. Initially set to `null` or `None`, indicating that the node has no right child.

## Constructor

The constructor initializes a node with a specified value and sets both child references to `null` or `None`.

### Parameters

- **data**: The value assigned to the `data` attribute, representing the content of the node.

### Example Usage

An example of how a Node might be used in constructing a simple binary tree:    root
                                                                               /    \
                                                                             left  right

1. **Creating Nodes**:
   - `root = Node(1)`
   - `root.left = Node(2)`
   - `root.right = Node(3)`

2. **Attributes After Creation**:
   - `root.data`: `1`
   - `root.left.data`: `2`
   - `root.right.data`: `3`

## Summary

The `Node` class is a fundamental building block in binary trees, where each node can reference two children. This structure enables the creation of complex tree hierarchies for data storage, traversal, and manipulation.
