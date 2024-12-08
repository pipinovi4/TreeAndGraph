const Node = require("../../Nodes/defaultNodes/node"); // Import the Node class to represent each node in the tree

class PerfectBinaryTree {
    constructor(depth) {
        /**
         * Initializes a PerfectBinaryTree instance with a specified depth.
         *
         * @param {number} depth - The depth of the perfect binary tree.
         * The tree will have 2^depth - 1 nodes.
         */
        this.root = this.buildPerfectTree(1, depth); // Initialize the tree with the specified depth
    }

    // Recursively builds a perfect binary tree
    buildPerfectTree(data, depth) {
        /**
         * Recursively constructs a perfect binary tree.
         *
         * @param {number} data - The value for the current node.
         * @param {number} depth - The remaining depth of the tree to be constructed.
         * @returns {Node|null} - Returns the newly created node or null if depth is zero.
         */
        if (depth === 0) {
            return null; // Return null if the depth is zero (base case)
        }

        const node = new Node(data); // Create a new node with the provided data
        // Recursively create left and right children for the current node
        node.left = this.buildPerfectTree(data * 2, depth - 1);
        node.right = this.buildPerfectTree(data * 2 + 1, depth - 1);
        return node; // Return the newly created node
    }

    // Searches for a target value in the tree using pre-order traversal
    search(node, target) {
        /**
         * Searches for a target value in the tree using pre-order traversal.
         *
         * @param {Node|null} node - The current node being examined.
         * @param {number} target - The value to search for in the tree.
         * @returns {boolean} - Returns true if the target is found, false otherwise.
         */
        if (node === null) {
            return false; // Return false if the node is null
        }
        if (node.data === target) {
            return true; // Return true if the current node's data matches the target
        }
        // Recursively search in the left and right children
        return this.search(node.left, target) || this.search(node.right, target);
    }

    printTree(node) {
        /**
         * Prints the tree using pre-order traversal.
         *
         * @param {Node|null} node - The starting node for the traversal (usually the root).
         */
        const values = []; // Array to store node values

        /**
         * Helper function to perform pre-order traversal and collect node values.
         *
         * @param {Node} currentNode - The current node being visited.
         */
        function traverse(currentNode) {
            if (currentNode !== null) {
                values.push(currentNode.data);       // Collect current node value
                traverse(currentNode.left);          // Traverse the left subtree
                traverse(currentNode.right);         // Traverse the right subtree
            }
        }

        traverse(node); // Start traversal from the specified node
        console.log(values.join(" "));  // Print all values in a single line
    }
}

module.exports = PerfectBinaryTree; // Export the PerfectBinaryTree class for use in other modules
