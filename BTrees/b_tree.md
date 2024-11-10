---

# B-Tree

A B-Tree is a self-balancing tree data structure that maintains sorted data and allows for efficient insertion, deletion, and search operations. B-Trees are optimized for systems that read and write large blocks of data, making them ideal for databases and file systems. In a B-Tree, nodes can have multiple children, and each node stores a range of keys, allowing the tree to remain shallow and balanced.

## Key Features

- **Self-Balancing**: The B-Tree maintains balance, ensuring logarithmic height and efficient operations.
- **Variable Node Size**: Each node can store multiple keys (up to `2t - 1` keys, where `t` is the minimum degree), making it suitable for disk-based storage.
- **Efficient for Large Datasets**: B-Trees reduce the need for re-balancing and keep the tree shallow, improving performance for large datasets.

## Overview of Core Operations

The B-Tree supports several fundamental operations, including insertion, deletion, search, and traversal. Each operation is structured to keep the tree balanced and efficient.

### Insertion

**Purpose**: Insert a new key while maintaining the B-Tree properties.

**Process**:
1. Traverse the tree from the root to find the correct leaf node for insertion.
2. If the leaf node is not full, insert the key directly.
3. If the leaf node is full, split the node into two and promote the middle key to the parent node.
4. If the root node becomes full, create a new root and split the existing root, ensuring the tree grows in height only when necessary.

### Deletion

**Purpose**: Remove a specified key from the tree while preserving B-Tree properties.

**Process**:
1. Locate the node containing the key.
2. Handle different deletion cases:
   - **Leaf Node**: Directly remove the key.
   - **Internal Node**: Replace the key with either its predecessor or successor and remove the replacement key from its original location.
3. If a node has fewer than `t - 1` keys, borrow a key from a sibling or merge nodes to ensure the minimum key count is maintained.

### Searching

**Purpose**: Check if a specific key exists within the B-Tree.

**Process**:
1. Start from the root and compare the target key to each key in the current node.
2. Traverse left or right based on the key comparison until the target is found or reach a leaf without finding it.

### Traversal

**Purpose**: Traverse the keys in the B-Tree in a specific order.

**Process**:
- **In-Order Traversal**: Visit each node’s keys in ascending order, starting from the smallest key to the largest key in each subtree.
- This traversal method provides sorted data output.

## Node Splitting

Node splitting is central to maintaining the B-Tree structure. When a node overflows, it is split into two nodes, and the middle key is moved up to the parent. This process ensures that nodes stay within the permissible range of keys, keeping the tree balanced.

### Split Mechanism:

- When a node reaches `2t - 1` keys, split it into two nodes with `t - 1` keys each.
- Move the middle key up to the parent node, creating space for new keys.
- If the root node splits, a new root is created, increasing the tree’s height by one.

## Complexity Analysis

The B-Tree provides efficient operations due to its balanced nature and shallow height:

- **Insertion**: \( O(\log n) \)
- **Deletion**: \( O(\log n) \)
- **Search**: \( O(\log n) \)

These complexities are achieved because each node can hold multiple keys, reducing the overall height of the tree and minimizing the number of node accesses required.

---

## Example Visualization

Below is an example visualization of a B-Tree after performing several insertions and deletions, showing how nodes split and balance themselves.

### Insertions: 10, 20, 5, 6, 12, 30, 7, 17

```plaintext
Insert 10
    [10]

Insert 20
    [10, 20]

Insert 5
    [5, 10, 20]

Insert 6 (causes split of root)
       [10]
      /    \
   [5, 6]  [20]

Insert 12
       [10]
      /    \
   [5, 6]  [12, 20]

Insert 30
       [10]
      /    \
   [5, 6]  [12, 20, 30]

Insert 7 (causes split in the right subtree)
       [10, 20]
      /   |    \
   [5, 6] [7, 12] [30]

Insert 17
       [10, 20]
      /   |    \
   [5, 6] [7, 12, 17] [30]
```

### Deletions: 6, 7, 10

```plaintext
Delete 6
       [10, 20]
      /   |    \
   [5]   [7, 12, 17] [30]

Delete 7
       [10, 20]
      /   |    \
   [5]   [12, 17] [30]

Delete 10 (causes restructuring)
       [20]
      /    \
   [5, 12] [30]
```

This example illustrates the insertion and deletion process, showing node splits and restructuring. The B-Tree balances itself to keep operations efficient.

---

## Conclusion

The B-Tree is a highly efficient data structure for scenarios where large datasets require sorted data with quick insertion, deletion, and search capabilities. Its design allows for shallow trees that handle multiple keys per node, making it suitable for databases and file systems where access times are critical.