# Treap (Tree + Heap)

A **Treap** is a hybrid data structure that combines properties of a **Binary Search Tree (BST)** and a **Heap**. It maintains the binary search tree property with respect to keys and the heap property with respect to priorities. This makes the Treap a randomized balanced search tree that ensures balanced operations with high probability.

## Key Concepts

1. **Binary Search Tree (BST) Property**:
   - For each node, the key of the left child is smaller, and the key of the right child is larger.

2. **Heap Property**:
   - For each node, the priority of a node is greater than or equal to the priorities of its children (max-heap).
   - Alternatively, some implementations use a min-heap where the priority of a node is less than or equal to its children.

3. **Random Priorities**:
   - Each node is assigned a random priority when inserted. This randomness helps ensure that the tree remains balanced with high probability.

---

## Structure of a Treap Node

Each node in a Treap contains:
1. **Key**: The value used for maintaining the BST property.
2. **Priority**: A randomly assigned value used for maintaining the heap property.
3. **Left Child**: The left subtree, which contains nodes with keys less than the current node.
4. **Right Child**: The right subtree, which contains nodes with keys greater than the current node.

---

## Core Operations

### 1. Insertion

**Purpose**: Insert a new node while maintaining both the BST property and the heap property.

**Process**:
1. Insert the node following the **BST insertion rule** (based on the key).
2. Assign a **random priority** to the new node.
3. Perform **rotations** to restore the heap property:
   - If the priority of the new node is higher than its parent, rotate the subtree to maintain the heap property.

**Example**:
1. **Insert (key: 10, priority: 50)**:
   - Tree:
     ```plaintext
     10 (50)
     ```

2. **Insert (key: 5, priority: 70)**:
   - Insert as a left child following the BST rule.
   - Since 70 > 50 (violates the heap property), rotate right:
     ```plaintext
         5 (70)
          \
          10 (50)
     ```

### 2. Deletion

**Purpose**: Remove a node while maintaining both the BST property and the heap property.

**Process**:
1. Locate the node to be deleted.
2. If the node has **two children**, perform **rotations** to push the node down to a leaf position while maintaining the heap property.
3. Once the node becomes a leaf, delete it directly.

**Example**:
1. **Delete 10** in the following Treap:
   ```plaintext
       5 (70)
        \
        10 (50)
   ```
   - Delete 10 directly since it’s a leaf.

### 3. Search

**Purpose**: Check if a node with a specific key exists.

**Process**:
1. Traverse the tree like a standard BST:
   - If the key is less than the current node’s key, search the left subtree.
   - If the key is greater, search the right subtree.
   - If the key matches, the node is found.

---

## Rotations in Treap

Rotations are used to restore the heap property after an insertion or deletion:

1. **Right Rotation**:
   - Used when the left child has a higher priority than the current node.
   - Example:
     ```plaintext
         A (50)
        /
      B (70)
     ```
     After a right rotation:
     ```plaintext
       B (70)
        \
        A (50)
     ```

2. **Left Rotation**:
   - Used when the right child has a higher priority than the current node.
   - Example:
     ```plaintext
       A (50)
        \
        B (70)
     ```
     After a left rotation:
     ```plaintext
         B (70)
        /
       A (50)
     ```

---

## Complexity Analysis

- **Insertion**: \(O(\log n)\) expected time.
- **Deletion**: \(O(\log n)\) expected time.
- **Search**: \(O(\log n)\) expected time.

The expected time complexity of these operations is logarithmic because the random priorities help maintain a balanced tree structure.

---

## Example of Treap Operations

### Inserting Keys

1. **Insert (key: 20, priority: 30)**:
   ```plaintext
   20 (30)
   ```

2. **Insert (key: 10, priority: 50)**:
   - Insert as left child:
     ```plaintext
       20 (30)
       /
     10 (50)
     ```
   - Rotate right due to higher priority of 10:
     ```plaintext
     10 (50)
       \
       20 (30)
     ```

3. **Insert (key: 30, priority: 40)**:
   - Insert as right child of 20:
     ```plaintext
     10 (50)
       \
       20 (30)
         \
         30 (40)
     ```
   - Rotate left to fix the heap property:
     ```plaintext
     10 (50)
       \
       30 (40)
       /
     20 (30)
     ```

---

## Applications of Treaps

1. **Balanced Search Trees**:
   - For maintaining sets or maps where balancing is handled probabilistically.

2. **Priority Queues**:
   - Treaps can be used where elements need to be retrieved based on both priority and order.

3. **Implicit Treaps**:
   - Used for maintaining ordered sequences, such as dynamic arrays or strings.

4. **Caching Systems**:
   - For quick access to frequently queried data.

---

## Summary

A **Treap** efficiently combines the strengths of a Binary Search Tree (ordered structure) and a Heap (randomized balancing). By assigning random priorities and performing rotations, Treaps maintain a balanced structure with high probability, ensuring efficient insertion, deletion, and search operations. This makes Treaps a versatile and powerful data structure for many applications where balancing and ordered access are crucial.