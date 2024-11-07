const Node = require('../Nodes/node.js'); // Import Node class

/**
 * Class representing a Full Binary Tree, where each node has either 0 or exactly 2 children.
 */
class FullBinaryTree {
    constructor() {
        // Initialize the root node with data 1
        this.root = new Node(1);
    }

    /**
     * Adds two children to a specified parent node if it has no children,
     * enforcing the full binary tree property (only allowing 0 or 2 children).
     *
     * @param {Node} parent - The parent node to which children will be added.
     * @param {number} leftData - The data for the left child node.
     * @param {number} rightData - The data for the right child node.
     * @throws {Error} If the parent already has children or only one child data is provided.
     */
    addChildren(parent, leftData, rightData) {
        if (!parent.left && !parent.right) { // Check if the parent has no children
            if (leftData !== undefined && rightData !== undefined) {
                // Create and assign left and right children
                parent.left = new Node(leftData);
                parent.right = new Node(rightData);
            } else {
                // Throw error if both left and right data are not provided
                throw new Error("A full binary tree requires either 0 or 2 children.");
            }
        } else {
            // Throw error if the parent already has children
            throw new Error("Parent already has children.");
        }
    }

    /**
     * Searches for a target value in the tree using pre-order traversal.
     *
     * @param {Node} node - The starting node for the search (usually the root).
     * @param {number} target - The value being searched for in the tree.
     * @return {boolean} True if the target is found, false otherwise.
     */
    search(node, target) {
        if (node === null) {
            return false; // Return false if the node is null
        }
        if (node.data === target) {
            return true; // Return true if the target value is found
        }
        // Recursively search the left and right subtrees
        return this.search(node.left, target) || this.search(node.right, target);
    }

    /**
     * Prints the values of the tree nodes in a single line using pre-order traversal.
     *
     * @param {Node} node - The starting node for the traversal (usually the root).
     */
    printTree(node) {
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

module.exports = FullBinaryTree;
