const FullBinaryTree = require('../source/full_binary_tree.js'); // Import the FullBinaryTree class

// Create a FullBinaryTree instance
const tree = new FullBinaryTree();

// Add children to the root node
tree.addChildren(tree.root, 2, 3); // Adds left child (2) and right child (3)

// Add children to the left child of the root
tree.addChildren(tree.root.left, 4, 5); // Adds children 4 and 5 to node 2

// Add children to the right child of the root
tree.addChildren(tree.root.right, 6, 7); // Adds children 6 and 7 to node 3

// Print the tree in pre-order traversal
console.log("Tree in pre-order traversal:");
tree.printTree(tree.root);

// Search for a value in the tree
const target = 5;
const found = tree.search(tree.root, target);
console.log(`Value ${target} ${found ? "is found" : "is not found"} in the tree.`);

// Search for a value not in the tree
const missingTarget = 10;
const notFound = tree.search(tree.root, missingTarget);
console.log(`Value ${missingTarget} ${notFound ? "is found" : "is not found"} in the tree.`);
