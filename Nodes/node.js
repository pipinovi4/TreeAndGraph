class Node {
    /**
     * Creates a new node with the specified data.
     * @param {any} data - The value to be stored in the node.
     */
    constructor(data) {
        this.data = data; // Store the value of the node

        // Initialize left child as null
        // This will later hold a reference to the left child node, if it exists.
        this.left = null;

        // Initialize right child as null
        // This will later hold a reference to the right child node, if it exists.
        this.right = null;
    }
}
