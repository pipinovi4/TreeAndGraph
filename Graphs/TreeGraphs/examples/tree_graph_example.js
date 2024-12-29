const TreeGraph = require("../source/tree_graph");

// Create an instance of the TreeGraph with a root node
const tree = new TreeGraph("A");

// Add nodes to the tree
tree.addNode("A", "B");
tree.addNode("A", "C");
tree.addNode("B", "D");
tree.addNode("B", "E");
tree.addNode("C", "F");
tree.addNode("F", "G");

// Display the tree structure
console.log("Tree Structure:");
tree.display();

// Perform in-order traversal
console.log("\nIn-order Traversal:");
tree.traversalInOrder();

// Perform pre-order traversal
console.log("\n\nPre-order Traversal:");
tree.traversalPreOrder();

// Perform post-order traversal
console.log("\n\nPost-order Traversal:");
tree.traversalPostOrder();
