const Treap = require("../source/treap");

// Main Execution
const treap = new Treap();

// Insert elements into the Treap
console.log("Inserting elements into the Treap...");
treap.insert(10);
treap.insert(20);
treap.insert(5);
treap.insert(15);

// Perform an in-order traversal and print the result
console.log("\nIn-order traversal after insertions:");
console.log(treap.inorder());

// Search for a value in the Treap
const searchValue = 15;
console.log(`\nSearch for ${searchValue}: ${treap.search(searchValue) ? "Found" : "Not Found"}`);

// Search for a non-existing value
const nonExistingValue = 25;
console.log(`Search for ${nonExistingValue}: ${treap.search(nonExistingValue) ? "Found" : "Not Found"}`);

// Print the Treap structure for debugging
console.log("\nTreap structure:");
treap.printTree();