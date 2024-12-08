const CompleteBinaryTree = require("../source/complete_binary_tree"); // Import the CompleteBinaryTree class

// Create an instance of the Complete Binary Tree
const tree = new CompleteBinaryTree();

// Insert values into the tree
console.log("Inserting values into the Complete Binary Tree...");
tree.insert(10);
tree.insert(20);
tree.insert(30);
tree.insert(40);
tree.insert(50);
tree.insert(60);
tree.insert(70);

// Print the tree's values in level-order
console.log("\nComplete Binary Tree values (Level Order):");
tree.printTree();

// Search for values in the tree
console.log("\nSearching for values in the tree...");
const searchValues = [30, 100, 50];
for (const value of searchValues) {
    if (tree.search(value)) {
        console.log(`Value ${value} found in the tree.`);
    } else {
        console.log(`Value ${value} not found in the tree.`);
    }
}
