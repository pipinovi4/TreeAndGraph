const FenwickTree = require('../source/fenwick_tree'); // Replace with the correct path to your FenwickTree module

// Data for initializing the Fenwick Tree
const data = [3, 2, -1, 6, 5, 4, -3];
console.log("Initial data:", data);

// Build a Fenwick Tree from the data
console.log("\nBuilding Fenwick Tree...");
const fenwickTree = FenwickTree.build(data);

// Query prefix sums
console.log("\nQuerying prefix sums:");
for (let i = 1; i <= data.length; i++) {
    console.log(`Sum of first ${i} elements: ${fenwickTree.query(i)}`);
}

// Update an element in the Fenwick Tree
console.log("\nUpdating index 3 (1-based) by adding +4...");
fenwickTree.update(3, 4);

// Query prefix sums after the update
console.log("\nQuerying prefix sums after update:");
for (let i = 1; i <= data.length; i++) {
    console.log(`Sum of first ${i} elements: ${fenwickTree.query(i)}`);
}

// Perform a range query
const left = 2, right = 5;
console.log(`\nSum of elements from index ${left} to ${right}: ${fenwickTree.rangeQuery(left, right)}`);
