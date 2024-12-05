const SplayTree = require('../source/splay_tree'); // Import the SplayTree class

// Create a new Splay Tree instance
const tree = new SplayTree();

// Insert elements into the Splay Tree
tree.insert(10);
tree.insert(20);
tree.insert(5);
tree.insert(15);

// Display the in-order traversal of the tree
console.log("In-order traversal after insertions:", tree.inorder());

// Search for an element
const searchValue = 15;
const found = tree.search(searchValue);
console.log(`Search for ${searchValue}:`, found ? "Found" : "Not Found");

// Try to search for a non-existing value
const nonExistingValue = 25;
const notFound = tree.search(nonExistingValue);
console.log(`Search for ${nonExistingValue}:`, notFound ? "Found" : "Not Found");

// Delete an element
const deleteValue = 20;
console.log(`Deleting ${deleteValue}...`);
tree.delete(deleteValue);

// Display the in-order traversal after deletion
console.log("In-order traversal after deletion:", tree.inorder());
