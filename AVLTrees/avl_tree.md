# AVL Tree

An AVL Tree (Adelson-Velsky and Landis Tree) is a self-balancing binary search tree designed to maintain balance automatically. In an AVL Tree, the difference in height (balance factor) between the left and right subtrees of each node is at most one. This constraint is achieved through rotations, keeping operations such as insertion, deletion, and search efficient with a time complexity of \( O(\log n) \).

## Key Features

- **Self-Balancing**: The AVL Tree maintains balance after each operation to ensure optimal performance.
- **Balance Factor**: Each node’s balance factor, representing the height difference between its left and right subtrees, stays within the range of -1 to 1.
- **Rotations**: Left and right rotations keep the tree balanced after structural changes like insertion and deletion.

## Overview of Core Operations

The AVL Tree supports several fundamental operations, including insertion, deletion, search, and traversal. Each operation is explained below, along with the mechanisms that ensure the tree remains balanced.

### Insertion

**Purpose**: Insert a new value while maintaining the AVL balance property.

**Process**:
1. Traverse the tree to find the appropriate insertion point based on the value.
2. Insert the new node as a leaf.
3. After insertion, traverse back up the tree to check each node’s balance factor.
4. If any node becomes unbalanced, perform a rotation (or a combination of rotations) to restore balance.

**Rotations Used**:
- **Single Rotations**: Left or right rotations for simple imbalances.
- **Double Rotations**: A left-right or right-left rotation to correct complex imbalances.

### Deletion

**Purpose**: Remove a specified value from the tree and maintain balance.

**Process**:
1. Traverse the tree to locate the node to delete.
2. Handle different deletion cases:
    - **No children**: Directly remove the node.
    - **One child**: Replace the node with its child.
    - **Two children**: Replace the node’s value with its in-order successor or predecessor, then delete the successor or predecessor.
3. After deletion, backtrack up the tree and check each node's balance factor.
4. If any node is unbalanced, apply the appropriate rotation(s) to restore balance.

### Searching

**Purpose**: Determine whether a specific value exists within the AVL Tree.

**Process**:
1. Start from the root and compare the target value to each node’s value.
2. Traverse left or right based on the comparison until finding the target value or reaching a `nullptr` (indicating the target is not in the tree).

### In-Order Traversal

**Purpose**: Print or retrieve nodes in ascending order.

**Process**:
1. Traverse the tree from left to right, visiting nodes in increasing order of their values.
2. This traversal method is useful for retrieving sorted data from the tree.

## Rotation Mechanisms

To maintain the AVL Tree's balance, rotations are performed when a node's balance factor is outside the allowed range (-1 to 1). There are four types of rotations, categorized by the imbalance direction:

- **Right Rotation (LL Case)**: Applied when a node’s left child becomes too heavy. The left child becomes the new root of the subtree.
- **Left Rotation (RR Case)**: Applied when a node’s right child becomes too heavy. The right child becomes the new root of the subtree.
- **Left-Right Rotation (LR Case)**: Applied when a node’s left child’s right subtree causes imbalance. A left rotation is applied to the left child, followed by a right rotation on the node.
- **Right-Left Rotation (RL Case)**: Applied when a node’s right child’s left subtree causes imbalance. A right rotation is applied to the right child, followed by a left rotation on the node.

## Complexity Analysis

The AVL Tree provides efficient operations due to its balanced nature:

- **Insertion**: \( O(\log n) \)
- **Deletion**: \( O(\log n) \)
- **Search**: \( O(\log n) \)

These complexities are guaranteed because the AVL Tree remains balanced after each operation, making it suitable for scenarios where frequent insertions and deletions occur.

---

## Example Visualization

Below is an example visualization of an AVL Tree after performing several insertions. This example shows how rotations maintain balance.

### Insertions: 30, 20, 40, 10, 25, 35, 50, 5

```plaintext
Insert 30
    30

Insert 20
    30
   /
  20

Insert 40
    30
   /  \
  20   40

Insert 10 (Left-Left imbalance, Right Rotation on 30)
    20
   /  \
  10   30
         \
          40

Insert 25
    20
   /  \
  10   30
      /  \
     25   40

Insert 35
    20
   /  \
  10   30
      /  \
     25   40
          /
         35

Insert 50
    20
   /  \
  10   30
      /  \
     25   40
          / \
         35  50

Insert 5 (Left imbalance, no rotation needed)
    20
   /  \
  10   30
  /    /  \
 5    25   40
          / \
         35  50
```

This example visualization illustrates AVL Tree insertions while explaining each rotation type in a structured manner. This format allows readers to easily understand the rotation process, ensuring that the AVL Tree maintains its balanced structure.
