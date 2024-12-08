# B+ Tree

A B+ Tree is an advanced self-balancing tree data structure that extends the functionality of a B-Tree by maintaining all keys in its leaf nodes, with internal nodes used only for navigation. This structure provides efficient sequential access and is particularly optimized for database indexing and file systems, where range queries and sorted data traversal are common requirements.

## Key Features

- **Leaf Node Linking**: Leaf nodes are linked, enabling fast sequential and range queries.
- **Efficient Range Queries**: Traversing linked leaf nodes ensures rapid access to a range of keys.
- **Balanced Structure**: Like the B-Tree, the B+ Tree remains balanced to ensure logarithmic height and efficiency.
- **Separation of Keys and Data**: Internal nodes store only keys, while leaf nodes hold all the actual keys/data.

## Overview of Core Operations

The B+ Tree supports efficient operations, including insertion, deletion, search, and range queries, while maintaining balance and structure.

### Insertion

**Purpose**: Add a new key to the B+ Tree while maintaining its properties.

**Process**:
1. Traverse from the root to the appropriate leaf node.
2. Insert the key into the leaf node in sorted order.
3. If the leaf node overflows:
   - Split the node into two.
   - Move the middle key up to the parent node.
   - Propagate splitting upward if necessary, potentially increasing the tree's height.

### Deletion

**Purpose**: Remove a key from the B+ Tree while preserving its structure.

**Process**:
1. Locate the leaf node containing the key.
2. Remove the key from the node.
3. If the node underflows:
   - Borrow a key from a sibling if possible.
   - Otherwise, merge the underflowed node with a sibling.
   - Propagate merging upward if necessary.

### Searching

**Purpose**: Determine if a specific key exists within the B+ Tree.

**Process**:
1. Start at the root and traverse down, comparing the target key to keys in internal nodes.
2. Reach the appropriate leaf node and check for the target key.
3. Return the node if the key exists; otherwise, return `nullptr`.

### Range Queries

**Purpose**: Retrieve all keys within a specific range.

**Process**:
1. Begin at the leaf node containing the smallest key in the range.
2. Traverse linked leaf nodes, collecting keys in the specified range.
3. Stop when all keys in the range are gathered or the end of the tree is reached.

## Node Splitting

Node splitting is critical to maintaining the balance of the B+ Tree. When a node exceeds its key capacity, it is split into two nodes, and the middle key is moved to the parent.

### Split Mechanism:

- **Leaf Nodes**:
  - Move half the keys to a new leaf node.
  - Update the parent with the smallest key in the new node.
  - Adjust `next` pointers to maintain sequential access.
- **Internal Nodes**:
  - Move half the keys to a new internal node.
  - Promote the middle key to the parent node.

## Complexity Analysis

The B+ Tree's balanced structure and linked leaf nodes enable efficient operations:

- **Insertion**: \( O(\log n) \)
- **Deletion**: \( O(\log n) \)
- **Search**: \( O(\log n) \)
- **Range Queries**: \( O(\log n + k) \), where \( k \) is the number of keys in the range.

These complexities are achieved by minimizing the tree's height and leveraging node splitting.

---

## Example Visualization

Below is an example of a B+ Tree undergoing insertions and deletions.

### Insertions: 10, 20, 5, 6, 12, 30, 7, 17

```plaintext
Insert 10
    [10]

Insert 20
    [10, 20]

Insert 5
    [5, 10, 20]

Insert 6 (causes root split)
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

Insert 7 (causes split in right subtree)
       [10, 20]
      /   |    \
   [5, 6] [7, 12] [30]

Insert 17
       [10, 20]
      /   |    \
   [5, 6] [7, 12, 17] [30]

### Deletions: 6, 7, 10

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

This example illustrates the insertion and deletion process, showing node splits and restructuring. The B+-Tree balances itself to keep operations efficient.

---

### Conclusion
The B+ Tree is an ideal data structure for applications requiring sorted data access and efficient range queries. Its unique design separates navigation keys from data storage, ensuring optimal performance for database indexing and file systems. By maintaining linked leaf nodes and a balanced structure, the B+ Tree provides consistent efficiency across insertion, deletion, search, and traversal operations.
