const FullBinaryTree = require('./FullBinaryTrees/full_binary_tree');
const CompleteBinaryTree = require('./CompleteBinaryTrees/complete_binary_tree');
const PerfectBinaryTree = require('./PerfectBinaryTrees/perfect_binary_tree');

console.log("Full Binary Tree:");

// ---------------- Full Binary Tree Example ---------------- //

// Initialize FullBinaryTree with root set to Node(1)
const fullBinaryTree = new FullBinaryTree();  // Root node initialized with value 1 by default

// Print the initial state of the tree (only the root node)
console.log("Initialized Full Binary Tree:");
fullBinaryTree.printTree(fullBinaryTree.root);  // Expected output: 1

// Add children to the root node
fullBinaryTree.addChildren(fullBinaryTree.root, 2, 3);
console.log("\nAdded children for the root node:");
fullBinaryTree.printTree(fullBinaryTree.root);  // Expected output: 1 2 3

// Add more children to the existing nodes
fullBinaryTree.addChildren(fullBinaryTree.root.left, 4, 5);  // Adds Node(4) and Node(5) as children of Node(2)
fullBinaryTree.addChildren(fullBinaryTree.root.right, 6, 7); // Adds Node(6) and Node(7) as children of Node(3)

// Print the fully populated Full Binary Tree
console.log("\nFully populated Full Binary Tree:");
fullBinaryTree.printTree(fullBinaryTree.root);  // Expected output: 1 2 4 5 3 6 7

// Perform search operations on FullBinaryTree
console.log(`\nDoes number "5" exist in the Full Binary Tree? ${fullBinaryTree.search(fullBinaryTree.root, 5)}`);  // Expected output: true
console.log(`Does number "8" exist in the Full Binary Tree? ${fullBinaryTree.search(fullBinaryTree.root, 8)}`);  // Expected output: false

console.log("\nComplete Binary Tree:");

// ---------------- Complete Binary Tree Example ---------------- //

// Initialize CompleteBinaryTree
const completeBinaryTree = new CompleteBinaryTree();

// Insert nodes level-by-level to maintain complete binary tree properties
completeBinaryTree.insert(1);  // Insert root node
completeBinaryTree.insert(2);  // Inserts as left child of root
completeBinaryTree.insert(3);  // Inserts as right child of root
completeBinaryTree.insert(4);  // Inserts as left child of node 2
completeBinaryTree.insert(5);  // Inserts as right child of node 2
completeBinaryTree.insert(6);  // Inserts as left child of node 3

// Print the populated Complete Binary Tree
console.log("Fully populated Complete Binary Tree:");
completeBinaryTree.printTree();  // Expected output: 1 2 3 4 5 6

// Perform search operations on CompleteBinaryTree
console.log(`\nDoes number "5" exist in the Complete Binary Tree? ${completeBinaryTree.search(5)}`);  // Expected output: true
console.log(`Does number "7" exist in the Complete Binary Tree? ${completeBinaryTree.search(7)}`);  // Expected output: false

console.log("\nPerfect Binary Tree:");

// ---------------- Perfect Binary Tree Example ---------------- //

// Initialize PerfectBinaryTree with sample data and depth
const perfectDepth = 3;  // Depth of the perfect binary tree

const perfectBinaryTree = new PerfectBinaryTree(perfectDepth);  // Create PerfectBinaryTree instance

// Print the populated Perfect Binary Tree
console.log("Fully populated Perfect Binary Tree:", end=" ");
perfectBinaryTree.printTree(perfectBinaryTree.root);  // Expected output: 1 2 3 4 5 6 7

// Perform search operations on PerfectBinaryTree
console.log(`\nDoes number "5" exist in the Perfect Binary Tree? ${perfectBinaryTree.search(perfectBinaryTree.root, 5)}`);  // Expected output: true
console.log(`Does number "8" exist in the Perfect Binary Tree? ${perfectBinaryTree.search(perfectBinaryTree.root, 8)}`);  // Expected output: false
