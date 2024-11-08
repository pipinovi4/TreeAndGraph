const Node = require("../Nodes/node"); // Import the Node class to represent each node in the tree

/**
 * Class representing a Binary Search Tree (BST).
 * A BST is a tree data structure in which each node has at most two children,
 * where the left child contains values less than the parent node,
 * and the right child contains values greater than the parent node.
 */
class BinarySearchTree {
    constructor() {
        this.root = null; // Initialize the root of the BST as null
    }

    /**
     * Inserts a new node with the specified data into the BST.
     * @param {number} data - The value to be inserted.
     */
    insert(data) {
        if (!this.root) {
            this.root = new Node(data); // Create the root node if the tree is empty
        } else {
            this._insertRecursive(this.root, data); // Call the recursive helper function to insert
        }
    }

    /**
     * Helper function for recursive insertion of a new node.
     * @param {Node} node - The current node in the BST.
     * @param {number} data - The value to be inserted.
     */
    _insertRecursive(node, data) {
        if (node.data < data) { // If the data is greater than the current node's data
            if (!node.right) { // If there is no right child
                node.right = new Node(data); // Create a new right child node
            } else {
                this._insertRecursive(node.right, data); // Recur on the right subtree
            }
        } else if (node.data > data) { // If the data is less than the current node's data
            if (!node.left) { // If there is no left child
                node.left = new Node(data); // Create a new left child node
            } else {
                this._insertRecursive(node.left, data); // Recur on the left subtree
            }
        }
    }

    /**
     * Searches for a node with the specified target value.
     * @param {number} target - The value to search for.
     * @returns {boolean} - True if the target is found, false otherwise.
     */
    search(target) {
        return this._searchRecursive(this.root, target); // Start the search from the root
    }

    /**
     * Helper function for recursive search.
     * @param {Node} node - The current node in the BST.
     * @param {number} target - The value to search for.
     * @returns {boolean} - True if the target is found, false otherwise.
     */
    _searchRecursive(node, target) {
        if (!node) { // Base case: if the current node is null
            return false; // Target not found
        }
        if (node.data === target) { // If the current node's data matches the target
            return true; // Return true
        } else if (target < node.data) { // If the target is less than the current node's data
            return this._searchRecursive(node.left, target); // Search left
        } else { // If the target is greater than the current node's data
            return this._searchRecursive(node.right, target); // Search right
        }
    }

    /**
     * Deletes a node with the specified data from the BST.
     * @param {number} data - The value to be deleted.
     */
    delete(data) {
        this.root = this._deleteRecursive(this.root, data); // Update the root after deletion
    }

    /**
     * Helper function for recursive deletion of a node.
     * @param {Node} node - The current node in the BST.
     * @param {number} data - The value to be deleted.
     * @returns {Node} - The updated node after deletion.
     */
    _deleteRecursive(node, data) {
        if (!node) { // Base case: if the node is null
            return node; // Nothing to delete
        }

        if (data < node.data) { // If data is less than the current node's data
            node.left = this._deleteRecursive(node.left, data); // Recur on the left subtree
        } else if (data > node.data) { // If data is greater than the current node's data
            node.right = this._deleteRecursive(node.right, data); // Recur on the right subtree
        } else { // Node with the data found
            if (!node.left) { // Node with only right child or no child
                return node.right; // Return the right child
            } else if (!node.right) { // Node with only left child
                return node.left; // Return the left child
            }

            // Node with two children: get the inorder successor (smallest in the right subtree)
            const minLargerNode = this._minValueNode(node.right);
            node.data = minLargerNode.data; // Replace data with the successor's data
            node.right = this._deleteRecursive(node.right, minLargerNode.data); // Delete the inorder successor
        }

        return node; // Return the (potentially unchanged) node pointer
    }

    /**
     * Returns the node with the smallest value greater than the current node.
     * @param {Node} node - The current node in the BST.
     * @returns {Node} - The node with the smallest value.
     */
    static _minValueNode(node) {
        let current = node; // Start with the given node
        while (current.left) { // Go to the leftmost node
            current = current.left; // Move to the left child
        }

        return current; // Return the node with the smallest value
    }

    /**
     * Prints the tree using pre-order traversal.
     * @param {Node} node - The root node of the BST.
     */
    static printTree(node) {
        const values = []; // Array to store node values

        function traverse(currentNode) { // Helper function for tree traversal
            if (currentNode !== null) { // If the current node is not null
                values.push(currentNode.data); // Collect current node value
                traverse(currentNode.left); // Traverse the left subtree
                traverse(currentNode.right); // Traverse the right subtree
            }
        }

        traverse(node); // Start traversal from the specified node
        console.log(values.join(" ")); // Print all values in a single line
    }
}

module.exports = BinarySearchTree; // Export the BinarySearchTree class for use in other modules
