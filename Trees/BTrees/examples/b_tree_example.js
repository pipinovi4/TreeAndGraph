const BTree = require('../source/b_tree'); // Adjust the path if needed

// Initialize a B-Tree with a minimum degree of 3
const bTree = new BTree(3);

console.log("Inserting keys into the B-Tree...");
[10, 20, 5, 6, 12, 30, 7, 17].forEach((key) => {
    bTree.insert(key);
    console.log(`Inserted key: ${key}`);
});

// Print the B-Tree structure after insertions
console.log("\nB-Tree structure after insertions:");
bTree.printTree();

// Search for keys in the B-Tree
console.log("\nSearching for keys in the B-Tree...");
[6, 15, 30].forEach((key) => {
    const result = bTree.search(key);
    if (result) {
        console.log(`Key ${key} found in node: ${result.keys}`);
    } else {
        console.log(`Key ${key} not found in the B-Tree.`);
    }
});

// Remove keys from the B-Tree
console.log("\nDeleting keys from the B-Tree...");
[6, 20, 30].forEach((key) => {
    bTree.remove(key);
    console.log(`Deleted key: ${key}`);
    console.log("Updated B-Tree structure:");
    bTree.printTree();
});
