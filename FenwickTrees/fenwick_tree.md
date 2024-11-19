# Fenwick Tree

A **Fenwick Tree** (also known as a **Binary Indexed Tree**) is a data structure that provides efficient methods for cumulative frequency tables and range sum queries. It is commonly used when frequent updates and prefix/range queries are required, as in computational problems involving cumulative sums.

## Key Features

- **Efficient Updates**: Allows updates to elements and recalculates the cumulative sum efficiently.
- **Prefix Sum Queries**: Computes the sum of elements from the start of the array to a given index in logarithmic time.
- **Range Queries**: Supports range sum queries by leveraging prefix sums.
- **Compact Storage**: Stores cumulative data using minimal memory.

## Overview of Core Operations

The Fenwick Tree supports the following key operations efficiently:

### Update

**Purpose**: Increment a value at a specific index and update all relevant nodes in the tree.

**Process**:
1. Start at the given index.
2. Update the value at the index by adding a given delta.
3. Move to the next affected index using the least significant bit (LSB) and repeat until the end of the tree.

### Prefix Sum Query

**Purpose**: Compute the sum of elements from the start of the array to a specific index.

**Process**:
1. Start at the given index.
2. Add the value at the current index to the cumulative sum.
3. Move to the previous relevant index using the LSB and repeat until reaching index 0.

### Range Sum Query

**Purpose**: Calculate the sum of elements within a specific range `[l, r]`.

**Process**:
1. Compute the prefix sum up to index `r`.
2. Subtract the prefix sum up to index `l - 1`.

### Building a Fenwick Tree

**Purpose**: Construct a Fenwick Tree from an array of data.

**Process**:
1. Initialize an empty Fenwick Tree of the same size as the data.
2. Iterate over the array and use the `update` method to populate the tree.

---

## Complexity Analysis

The Fenwick Tree provides efficient time complexity for its operations:

- **Update**: \( O(\log n) \)
- **Prefix Sum Query**: \( O(\log n) \)
- **Range Sum Query**: \( O(\log n) \)
- **Building from Data**: \( O(n \log n) \)

These complexities arise from the logarithmic traversal of nodes due to the use of the least significant bit.

---

## Example Usage

### Initialization and Updates

```cpp
FenwickTree fenwickTree(10);  // Initialize a Fenwick Tree with size 10.

fenwickTree.update(1, 5);  // Add 5 to index 1.
fenwickTree.update(2, 3);  // Add 3 to index 2.
fenwickTree.update(3, 7);  // Add 7 to index 3.
fenwickTree.update(4, 6);  // Add 6 to index 4.
fenwickTree.update(5, 2);  // Add 2 to index 5.
```

### Prefix Sum Query

```cpp
std::cout << "Prefix sum up to index 3: " << fenwickTree.query(3) << std::endl;  // Output: 15 (5 + 3 + 7)
```

### Range Query

```cpp
std::cout << "Range sum [2, 4]: " << fenwickTree.range_query(2, 4) << std::endl;  // Output: 16 (3 + 7 + 6)
```

### Building from Data

```cpp
std::vector<int> data = {0, 5, 3, 7, 6, 2};  // 1-based indexing, index 0 is unused.
FenwickTree builtFenwickTree = FenwickTree::build(data);
std::cout << "Prefix sum up to index 5: " << builtFenwickTree.query(5) << std::endl;  // Output: 23
```

---

## Example Visualization

Below is an example of a Fenwick Tree's internal structure after several updates.

### Initial Updates: \( \text{add } 5 \text{ at index 1, } 3 \text{ at index 2, } 7 \text{ at index 3} \)

```plaintext
Array: [0, 5, 3, 7]
Tree:  [0, 5, 8, 7]  // Internal representation after updates
```

### Query: \( \text{query(3)} \)

```plaintext
Prefix Sum (index 3):
  sum = tree[3] + tree[2]
       = 7 + 8
       = 15
```

### Range Query: \( \text{range\_query(2, 4)} \)

```plaintext
Range Sum [2, 4]:
  range_sum = query(4) - query(1)
            = (5 + 3 + 7 + 6) - 5
            = 16
```

---

### Conclusion

The **Fenwick Tree** is a simple yet powerful data structure that provides efficient solutions for cumulative sum and range queries. Its compact and logarithmic operations make it ideal for scenarios where frequent updates and queries are required, such as competitive programming and computational geometry. By maintaining a balance between simplicity and efficiency, the Fenwick Tree remains a staple in algorithmic toolkits.