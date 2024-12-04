const BinarySearchTree = require("../source/binary_search_tree"); // Import the BinarySearchTree class

// Initialize the Binary Search Tree
const bst = new BinarySearchTree();

// Insert values into the BST
const valuesToInsert = [50, 30, 70, 20, 40, 60, 80];
console.log(`Inserting values: ${valuesToInsert.join(", ")}`);
valuesToInsert.forEach(value => bst.insert(value));

// Print the tree in pre-order traversal
console.log("Pre-order traversal after insertions:");
BinarySearchTree.printTree(bst.root);

// Search for a value in the BST
const searchValue = 40;
console.log(`\nSearching for value ${searchValue} in the BST...`);
const isFound = bst.search(searchValue);
console.log(isFound ? `Value ${searchValue} found in the BST.` : `Value ${searchValue} not found in the BST.`);

// Delete a value from the BST
const deleteValue = 30;
console.log(`\nDeleting value ${deleteValue} from the BST...`);
bst.delete(deleteValue);

// Print the tree in pre-order traversal after deletion
console.log("Pre-order traversal after deletion:");
BinarySearchTree.printTree(bst.root);

// Insert additional values
const additionalValues = [25, 35];
console.log(`\nInserting additional values: ${additionalValues.join(", ")}`);
additionalValues.forEach(value => bst.insert(value));

// Print the tree in pre-order traversal after additional insertions
console.log("Pre-order traversal after additional insertions:");
BinarySearchTree.printTree(bst.root);
