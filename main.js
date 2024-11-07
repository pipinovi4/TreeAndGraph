const FullBinaryTree = require('./FullBinaryTrees/full_binary_tree');

console.log("Full Binary Tree:");

// 1. Initialize FullBinaryTree with root set to Node(1)
const fullBinaryTree = new FullBinaryTree();  // Root node initialized with value 1 by default

// 2. Print the initial state of the tree (only the root node)
console.log("Initialized Full Binary Tree:");
fullBinaryTree.printTree(fullBinaryTree.root);  // Expected output: 1

// 3. Add children to the root node
// Adds left (Node(2)) and right (Node(3)) children to the root node
fullBinaryTree.addChildren(fullBinaryTree.root, 2, 3);
console.log("\nAdded children for the root node:");
fullBinaryTree.printTree(fullBinaryTree.root);  // Expected output: 1 2 3

// 4. Add more children to the existing nodes
// Adds children to Node(2) and Node(3), which are the left and right children of the root
fullBinaryTree.addChildren(fullBinaryTree.root.left, 4, 5);  // Adds Node(4) and Node(5) as children of Node(2)
fullBinaryTree.addChildren(fullBinaryTree.root.right, 6, 7); // Adds Node(6) and Node(7) as children of Node(3)

// 5. Print the fully populated Full Binary Tree
console.log("\nFully populated Full Binary Tree:");
fullBinaryTree.printTree(fullBinaryTree.root);  // Expected output: 1 2 4 5 3 6 7

// 6. Perform search operations
// Check if specific values (5 and 8) exist in the tree
console.log(`\nDoes number "5" exist in the tree? ${fullBinaryTree.search(fullBinaryTree.root, 5)}`);  // Expected: true
console.log(`Does number "8" exist in the tree? ${fullBinaryTree.search(fullBinaryTree.root, 8)}`);  // Expected: false
