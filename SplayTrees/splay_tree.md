# Splay Tree

A **Splay Tree** is a self-adjusting binary search tree that ensures recently accessed elements are quick to access again. It achieves this by performing rotations to bring the accessed element to the root. This structure is particularly useful for scenarios where the access pattern exhibits temporal locality, such as caches or frequently queried datasets.

## Key Features

- **Self-Adjusting**: The tree adjusts its structure during every operation, bringing the most recently accessed element to the root.
- **No Balance Guarantees**: Unlike AVL or Red-Black trees, the Splay Tree does not guarantee a balanced structure but adapts to access patterns.
- **Amortized Efficiency**: Operations have an amortized time complexity of \(O(\log n)\), making them efficient for dynamic datasets.
- **Simplified Implementation**: No need for explicit balancing like in AVL or Red-Black trees.

## Overview of Core Operations

The Splay Tree supports standard binary search tree operations, including insertion, deletion, search, and in-order traversal, with the added feature of self-adjustment through **splaying**.

---

### Splaying

**Purpose**: Adjust the tree structure by bringing a specific node to the root.

**Process**:
1. **Zig**: Perform a single rotation if the node is a direct child of the root.
2. **Zig-Zig**: Perform two consecutive rotations in the same direction (left-left or right-right) if the node and its parent are both on the same side of the grandparent.
3. **Zig-Zag**: Perform two consecutive rotations in opposite directions (left-right or right-left) if the node and its parent are on opposite sides of the grandparent.

---

### Insertion

**Purpose**: Add a new value to the Splay Tree.

**Process**:
1. If the tree is empty, set the new value as the root.
2. Splay the tree to bring the closest match to the root.
3. Insert the new value as the new root:
   - The old root becomes the right or left child of the new root, depending on the value.

---

### Deletion

**Purpose**: Remove a value from the Splay Tree.

**Process**:
1. Splay the tree to bring the value to the root.
2. If the value exists:
   - If the root has no left child, replace the root with the right child.
   - If the root has no right child, replace the root with the left child.
   - If both children exist:
     - Splay the largest node in the left subtree to the root.
     - Attach the right subtree to the new root.

---

### Searching

**Purpose**: Check if a value exists in the Splay Tree.

**Process**:
1. Traverse the tree like a binary search tree.
2. Splay the tree to bring the target value (or the closest match) to the root.
3. Return true if the value exists; otherwise, return false.

---

### In-Order Traversal

**Purpose**: Traverse the tree in ascending order of values.

**Process**:
1. Recursively visit the left subtree.
2. Process the current node.
3. Recursively visit the right subtree.

---

## Complexity Analysis

The Splay Tree's performance is amortized, meaning that a sequence of \(m\) operations takes \(O(m \log n)\) time. The complexity of individual operations depends on the structure of the tree at the time of the operation.

- **Insertion**: \(O(\log n)\) amortized.
- **Deletion**: \(O(\log n)\) amortized.
- **Search**: \(O(\log n)\) amortized.
- **In-Order Traversal**: \(O(n)\).

---

## Example of Operations

### Input Data

**Values to Insert**: [10, 20, 5, 15, 30]

**Values to Search**: [5, 30, 15]

---

### Insertion Example

Insert values into the Splay Tree in the order: 10, 20, 5, 15, 30.

1. **Insert 10**:
   - Tree becomes:
     ```plaintext
     10
     ```

2. **Insert 20**:
   - Splay 10 to the root, then insert 20:
     ```plaintext
     20
    /
   10
     ```

3. **Insert 5**:
   - Splay 20 to the root, then insert 5:
     ```plaintext
        5
         \
         20
        /
      10
     ```

4. **Insert 15**:
   - Splay 5 to the root, then insert 15:
     ```plaintext
         15
        /  \
       5    20
            /
          10
     ```

5. **Insert 30**:
   - Splay 15 to the root, then insert 30:
     ```plaintext
          30
         /
       15
      /  \
     5    20
         /
       10
     ```

---

### Searching Example

Search for 5, 30, and 15 in the tree.

1. **Search 5**:
   - Splay 5 to the root:
     ```plaintext
          5
           \
           30
          /
        15
       /  \
      10   20
     ```

2. **Search 30**:
   - Splay 30 to the root:
     ```plaintext
          30
         /
       15
      /  \
     10   20
    /
   5
     ```

3. **Search 15**:
   - Splay 15 to the root:
     ```plaintext
          15
         /  \
        5    30
            /
          20
         /
       10
     ```

---

### Deletion Example

Delete 15 and 5 from the tree.

1. **Delete 15**:
   - Splay 15 to the root, then replace it with the right subtree (after splaying the largest node in the left subtree to the root):
     ```plaintext
          10
         /  \
        5    30
            /
          20
     ```

2. **Delete 5**:
   - Splay 5 to the root, then replace it with the right subtree:
     ```plaintext
          10
            \
            30
           /
         20
     ```

---

## Applications

1. **Cache Implementations**:
   - Splay Trees are often used in caches to keep recently accessed elements easily accessible.
2. **Amortized Data Structures**:
   - Useful when the cost of individual operations can be distributed over multiple operations.
3. **Dynamic Graphs**:
   - Splay Trees are used in dynamic graph algorithms such as maintaining connectivity in forests.
4. **Text Editors**:
   - Used to maintain dynamic sequences in text editors for efficient cursor movement and modification.

---

### Conclusion

The **Splay Tree** is a simple yet powerful data structure for scenarios involving non-uniform access patterns. Its self-adjusting nature ensures efficient access to frequently used elements, making it suitable for caches, priority queues, and dynamic sets. By combining simplicity and amortized efficiency, the Splay Tree provides a versatile tool for various applications.