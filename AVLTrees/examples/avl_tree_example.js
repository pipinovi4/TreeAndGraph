const AVLTree = require('../source/avl_tree'); // Adjust the path based on your project structure

// Initialize the AVL Tree
const tree = new AVLTree();

// Insert values into the AVL Tree
const valuesToInsert = [10, 20, 5, 15, 30, 25, 35, 16];
console.log('Inserting values:', valuesToInsert);
valuesToInsert.forEach(value => tree.insert(value));

// Print the tree in in-order traversal (should be sorted)
console.log('In-order traversal after insertions:');
tree.printInOrder();

// Search for a value in the tree
const searchValue = 15;
console.log(`Searching for value ${searchValue} in the tree...`);
if (tree.search(searchValue)) {
    console.log(`Value ${searchValue} found in the tree.`);
} else {
    console.log(`Value ${searchValue} not found in the tree.`);
}

// Delete a value from the AVL Tree
const deleteValue = 20;
console.log(`Deleting value ${deleteValue} from the tree...`);
tree.delete(deleteValue);

// Print the tree in in-order traversal after deletion
console.log('In-order traversal after deletion:');
tree.printInOrder();

// Insert additional values to test rebalancing
const additionalValues = [18, 3, 40];
console.log('Inserting additional values:', additionalValues);
additionalValues.forEach(value => tree.insert(value));

// Print the tree in in-order traversal after additional insertions
console.log('In-order traversal after additional insertions:');
tree.printInOrder();
