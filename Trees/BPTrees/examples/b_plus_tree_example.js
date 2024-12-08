const BPTree = require('../source/b_plus_tree'); // Update this path to where BPTree is located

// Initialize a B+ Tree with a minimum degree of 3
const bpt = new BPTree(3);

// Insert keys into the B+ Tree
const keysToInsert = [10, 20, 5, 6, 12, 30, 7, 17];
console.log("Inserting keys:", keysToInsert);
keysToInsert.forEach(key => bpt.insert(key));

// Print the B+ Tree structure after insertions
console.log("\nB+ Tree structure after insertions:");
bpt.printTree();

// Search for a specific key in the B+ Tree
const keyToSearch = 12;
console.log(`\nSearching for key ${keyToSearch}...`);
const searchResult = bpt.search(keyToSearch);
if (searchResult) {
    console.log(`Key ${keyToSearch} found in the B+ Tree.`);
} else {
    console.log(`Key ${keyToSearch} not found in the B+ Tree.`);
}

// Perform a range query
const startKey = 6, endKey = 17;
console.log(`\nPerforming range query for keys between ${startKey} and ${endKey}...`);
const rangeResult = bpt.rangeQuery(startKey, endKey);
console.log(`Keys in range [${startKey}, ${endKey}]:`, rangeResult);

// Delete a key from the B+ Tree
const keyToDelete = 6;
console.log(`\nDeleting key ${keyToDelete} from the B+ Tree...`);
bpt.delete(keyToDelete);

// Print the B+ Tree structure after deletion
console.log("\nB+ Tree structure after deletion:");
bpt.printTree();
