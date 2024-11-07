const Node = require("../Nodes/node"); // Import the Node class to represent each node in the tree

/**
 * Class representing a Complete Binary Tree.
 * A Complete Binary Tree is a binary tree where all levels are completely filled
 * except possibly for the last level, which is filled from left to right.
 */
class CompleteBinaryTree {
    constructor() {
        this.nodes = [];  // Array to store nodes in level-order, ensuring completeness
    }

    /**
     * Inserts a new node in the complete binary tree.
     * @param {any} data - The value to be stored in the new node.
     */
    insert(data) {
        const new_node = new Node(data); // Create a new Node instance
        this.nodes.push(new_node);  // Add the new node to the array

        // Calculate the parent index based on the new node's position in the array
        const index = this.nodes.length - 1;  // Index of the newly added node
        if (index > 0) {  // Check if the node is not the root
            const parentIndex = Math.floor((index - 1) / 2);  // Calculate the parent index
            const parent = this.nodes[parentIndex];  // Get the parent node

            // Assign the new node as the left or right child of its parent
            if (!parent.left) {  // If the left child is not assigned
                parent.left = new_node;  // Assign the new node as the left child
            } else {
                parent.right = new_node;  // Otherwise, assign it as the right child
            }
        }
    }

    /**
     * Searches for a target value in the tree.
     * @param {any} target - The value to search for in the tree.
     * @returns {boolean} True if the target is found, otherwise false.
     */
    search(target) {
        // Iterate through the nodes array to find the target value
        for (const node of this.nodes) {
            if (node.data === target) {  // Compare node data with the target
                return true;  // Return true if found
            }
        }
        return false;  // Return false if the target is not found
    }

    /**
     * Prints the tree in level-order.
     * Level-order traversal prints nodes from top to bottom, left to right.
     */
    printTree() {
        if (this.nodes.length === 0) return;  // If there are no nodes, do nothing

        const queue = [this.nodes[0]];  // Start with the root node in the queue
        const values = [];  // Array to collect node values for printing

        while (queue.length > 0) {  // Process nodes until the queue is empty
            const currentNode = queue.shift();  // Remove the first node from the queue
            if (currentNode) {
                values.push(currentNode.data);  // Store the current node's data

                // Queue the left and right children if they exist
                if (currentNode.left !== null) queue.push(currentNode.left);
                if (currentNode.right !== null) queue.push(currentNode.right);
            }
        }

        console.log(values.join(" "));  // Print all collected values in a single line
    }
}

module.exports = CompleteBinaryTree;  // Export the CompleteBinaryTree class for use in other modules
