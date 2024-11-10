/**
 * Class representing a node in a binary tree.
 * Each node stores a data value and has references to left and right child nodes.
 */
class Node {
    /**
     * Creates a new node with the specified data.
     *
     * @param {any} data - The value to be stored in the node. Can be any data type.
     */
    constructor(data) {
        this.data = data; // Store the value in the node

        // Initialize left child as null (no left child initially)
        // This will hold a reference to the left child node, if assigned later.
        this.left = null;

        // Initialize right child as null (no right child initially)
        // This will hold a reference to the right child node, if assigned later.
        this.right = null;

        // Initialized counter height of the node
        this.height = 1;
    }
}

module.exports = Node;
