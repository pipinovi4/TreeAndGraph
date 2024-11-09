const FullBinaryTree = require('./FullBinaryTrees/full_binary_tree');
const CompleteBinaryTree = require('./CompleteBinaryTrees/complete_binary_tree');
const PerfectBinaryTree = require('./PerfectBinaryTrees/perfect_binary_tree');
const BinarySearchTree = require("./BinarySearchTrees/binary_search_tree")
const AVLTree = require("./AVLTree/avl_tree");
const BTree = require("./BTrees/b_tree");

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

console.log("\nBinary Search Tree:");

// ---------------- Binary Search Tree Example ---------------- //

// Initialize the Binary Search Tree
const bst = new BinarySearchTree();  // Create a new Binary Search Tree

// Insert values into the Binary Search Tree
const valuesToInsert = [5, 3, 7, 2, 4, 6, 8];  // Example values to insert into the BST
valuesToInsert.forEach(value => bst.insert(value));  // Insert each value into the BST

// Print the Binary Search Tree using in-order traversal
console.log("In-order traversal of the Binary Search Tree: ", end="");
BinarySearchTree.printTree(bst.root);  // Expected output: 2 3 4 5 6 7 8

// Perform search operations on Binary Search Tree
console.log(`\nDoes number "4" exist in the Binary Search Tree? ${bst.search(4)}`);  // Expected output: true
console.log(`Does number "9" exist in the Binary Search Tree? ${bst.search(9)}`);  // Expected output: false

console.log("\nAVL Tree:");

// ---------------- AVL Tree Example ---------------- //

// Initialize the AVL Tree
const avlTree = new AVLTree();

// Insert values into the AVL Tree
const avlValuesToInsert = [15, 10, 20, 5, 12, 16, 25, 30, 6];  // Example values to insert into the AVL tree
avlValuesToInsert.forEach(value => avlTree.insert(value));  // Insert each value into the AVL tree

// Print the AVL Tree using in-order traversal (should be sorted due to AVL properties)
console.log("In-order traversal of the AVL Tree (balanced):");
avlTree.printInOrder();  // Expected output: 5 6 10 12 15 16 20 25 30

// Perform search operations on AVL Tree
console.log(`\nDoes number "15" exist in the AVL Tree? ${avlTree.search(15)}`);  // Expected output: true
console.log(`Does number "40" exist in the AVL Tree? ${avlTree.search(40)}`);  // Expected output: false

// Perform delete operation on AVL Tree
avlTree.delete(15);
console.log("\nIn-order traversal after deleting 15:");
avlTree.printInOrder();  // Expected output: 5 6 10 12 16 20 25 30 (15 should be removed)

// ---------------- B-Tree Example ---------------- //
console.log("\nB-Tree:");

// Initialize the B-Tree with a minimum degree t = 2
const bTree = new BTree(2);

// Insert values into the B-Tree
const bTreeValuesToInsert = [10, 20, 5, 6, 15, 30, 25, 16, 2, 12];
bTreeValuesToInsert.forEach(value => bTree.insert(value));

// Print the B-Tree structure
console.log("B-Tree structure after insertions:");
bTree.printTree();  // This should show the B-Tree level-by-level

// Perform search operations in the B-Tree
console.log(`\nDoes number "15" exist in the B-Tree? ${bTree.search(15) ? "Yes" : "No"}`);  // Expected output: Yes
console.log(`Does number "40" exist in the B-Tree? ${bTree.search(40) ? "Yes" : "No"}`);  // Expected output: No

// Perform delete operations in the B-Tree
bTree.remove(15);
console.log("\nB-Tree structure after deleting 15:");
bTree.printTree();  // Should no longer contain 15

bTree.remove(10);
console.log("\nB-Tree structure after deleting 10:");
bTree.printTree();  // Should no longer contain 10

bTree.remove(5);
console.log("\nB-Tree structure after deleting 5:");
bTree.printTree();  // Should no longer contain 5