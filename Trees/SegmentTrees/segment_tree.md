# Segment Tree

A **Segment Tree** is a hierarchical data structure used for efficient handling of range queries and updates on an array. It is ideal for operations that involve calculating a result (such as sum, minimum, or maximum) over a range of elements, while allowing modifications to the underlying data.

---

## Key Features

- **Range Queries**: Quickly compute a result over a range of elements, such as the sum, minimum, or maximum.
- **Point Updates**: Modify individual elements in the array and propagate the changes efficiently throughout the tree.
- **Customizable Operations**: Works with any associative operation (e.g., addition, minimum, maximum) combined with an appropriate identity value.
- **Dynamic Data Handling**: Supports fast updates and queries on changing data.

---

## Overview of Core Operations

### Construction

**Purpose**: Build a segment tree from an input array.

**Process**:
1. Divide the array into smaller segments or intervals.
2. Store results (e.g., sum, minimum, or maximum) for each segment in a hierarchical structure.
3. Leaf nodes represent individual elements, while internal nodes represent results for combined segments.

---

### Range Query

**Purpose**: Compute the result of a specific operation (e.g., sum, minimum, maximum) over a range of indices in the array.

**Process**:
1. Identify the segments that overlap with the query range.
2. Combine the results of these overlapping segments using the specified operation.

---

### Point Update

**Purpose**: Update the value of an element in the array.

**Process**:
1. Locate the corresponding segment in the tree for the updated element.
2. Update the value at that segment.
3. Propagate the changes upwards to ensure all affected segments are updated.

---

## Complexity Analysis

The Segment Tree provides efficient time complexity for its operations:

- **Construction**: Linear time, \(O(n)\), where \(n\) is the size of the array.
- **Range Query**: Logarithmic time, \(O(\log n)\).
- **Point Update**: Logarithmic time, \(O(\log n)\).

---

## Example of Operations

### Input Data

**Array**: [2, 4, 5, 7, 8, 9, 1, 6]

### Building the Tree

1. Divide the array into segments, such as:
   - Segment 1: [2, 4]
   - Segment 2: [5, 7]
   - Segment 3: [8, 9]
   - Segment 4: [1, 6]

2. Combine these segments hierarchically:
   - Combine Segment 1 and Segment 2 to get [2, 4, 5, 7].
   - Combine Segment 3 and Segment 4 to get [8, 9, 1, 6].
   - Combine the results of these two groups to represent the full array.

---

### Example Query

**Task**: Find the minimum value in the range \([2, 5)\).

**Steps**:
1. Identify the segments that overlap with \([2, 5)\), e.g., [5, 7, 8].
2. Combine their values using the minimum operation: \( \min(5, 7, 8) = 5\).

---

### Example Update

**Task**: Update the value at index 3 to \(3\).

**Steps**:
1. Locate the segment containing index 3, e.g., [5, 7].
2. Update the segment to reflect the new value, resulting in [5, 3].
3. Recalculate all parent nodes affected by this change.

---

## Applications

Segment Trees are widely used in scenarios that require efficient handling of range-based queries and updates:

1. **Range Sum/Minimum/Maximum Queries**:
   - Useful in problems requiring frequent range calculations, such as cumulative totals or finding extrema in datasets.

2. **Dynamic Arrays**:
   - Suitable for scenarios where the array is modified frequently, and results need to stay consistent.

3. **Competitive Programming**:
   - Ideal for solving problems with constraints involving high-frequency queries and updates on large datasets.

4. **Interval Problems**:
   - Common in computational geometry, scheduling, and resource allocation.

---

## Visualization

### Input Array: [2, 4, 5, 7, 8, 9, 1, 6]

- **Leaf Nodes**: Represent individual elements.
- **Internal Nodes**: Represent the result of the operation over a segment of the array.

```plaintext
          [Overall Range]
          [2, 4, 5, 7, 8, 9, 1, 6]
            /           \
   [Left Half]        [Right Half]
   [2, 4, 5, 7]      [8, 9, 1, 6]
    /     \            /     \
[2, 4]  [5, 7]     [8, 9]  [1, 6]
 / \     / \         / \     / \
2   4   5   7       8   9   1   6
```

---

## Conclusion

A **Segment Tree** is a highly efficient and flexible data structure for handling range queries and updates. By breaking the problem into segments and storing results hierarchically, it optimizes operations involving intervals, making it a powerful tool for dynamic datasets and algorithmic challenges.