const PerfectBinaryTree = require('../source/perfect_binary_tree');

// Create a Perfect Binary Tree with depth 3
const depth = 3; // Depth 3 means the tree will have 2^3 - 1 = 7 nodes
const perfectTree = new PerfectBinaryTree(depth);

// Print the tree using pre-order traversal
console.log("Pre-order Traversal of Perfect Binary Tree:");
perfectTree.printTree(perfectTree.root);

// Search for a value in the tree
const searchValue1 = 4;
console.log(`Searching for value ${searchValue1} in the tree:`);
const isFound1 = perfectTree.search(perfectTree.root, searchValue1);
console.log(isFound1 ? "Found!" : "Not found.");

// Search for a value not present in the tree
const searchValue2 = 10;
console.log(`Searching for value ${searchValue2} in the tree:`);
const isFound2 = perfectTree.search(perfectTree.root, searchValue2);
console.log(isFound2 ? "Found!" : "Not found.");
