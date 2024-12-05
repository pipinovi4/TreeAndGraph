const SegmentTree = require('../source/segment_tree'); // Import the SegmentTree class

// Sample data array
const data = [1, 3, 5, 7, 9, 11];

// Initialize the Segment Tree for range sum queries
const segTree = new SegmentTree(data, (a, b) => a + b, 0);

// Perform range queries
console.log("Sum of range [1, 4):", segTree.query(1, 4)); // Query sum from index 1 to 3
console.log("Sum of range [0, 6):", segTree.query(0, 6)); // Query sum for the entire array

// Update an element
segTree.update(2, 10); // Update index 2 to the value 10

// Perform range queries after update
console.log("Sum of range [1, 4) after update:", segTree.query(1, 4));
console.log("Sum of range [0, 6) after update:", segTree.query(0, 6));

// Example with min query
const segTreeMin = new SegmentTree(data, Math.min, Infinity);
console.log("Minimum in range [1, 4):", segTreeMin.query(1, 4)); // Query minimum from index 1 to 3
