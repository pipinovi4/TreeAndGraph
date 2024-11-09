class BTreeNode {
    /**
     * Constructor for a BTree node.
     * @param {boolean} is_leaf - Indicates if the node is a leaf.
     */
    constructor(is_leaf = true) {
        this.is_leaf = is_leaf;  // true if node is a leaf, false otherwise
        this.keys = [];           // Array to store keys in the node
        this.children = [];       // Array to store child pointers (empty if leaf)
    }

    /**
     * Add a key to the node.
     * @param {any} key - The key to add.
     */
    addKey(key) {
        this.keys.push(key);
        this.keys.sort((a, b) => a - b); // Sort keys after insertion to maintain order
    }

    /**
     * Remove a key from the node.
     * @param {any} key - The key to remove.
     */
    removeKey(key) {
        const index = this.keys.indexOf(key);
        if (index !== -1) {
            this.keys.splice(index, 1);
        }
    }
}

module.exports = BTreeNode;
