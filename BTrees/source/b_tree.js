// Import the BTreeNode class, which represents individual nodes in the B-Tree.
const BTreeNode = require("../../Nodes/BTreeNodes/b_tree_node");

/**
 * Class representing a B-Tree.
 *
 * A B-Tree is a balanced tree data structure that maintains sorted data and allows searches,
 * sequential access, insertions, and deletions in logarithmic time.
 *
 * The `BTree` class here provides a high-level interface to perform operations like insertion,
 * searching, and deletion on a B-Tree with a specified minimum degree `t`.
 */
class BTree {
    /**
     * Constructs a BTree with a given minimum degree.
     * @param {number} t - Minimum degree of the B-Tree. Defines the range for the number of keys per node.
     */
    constructor(t) {
        this.root = new BTreeNode(t);  // Initialize the root node as a leaf node
        this.t = t;                    // Store the minimum degree
    }

    /**
     * Inserts a new key into the B-Tree.
     *
     * If the root node is full, the tree height is increased by creating a new root and splitting
     * the old root.
     *
     * @param {any} key - The key to be inserted into the B-Tree.
     */
    insert(key) {
        const root = this.root;

        // Check if the root node is full
        if (root.keys.length === 2 * this.t - 1) {
            // Create a new root node as a non-leaf node
            const newRoot = new BTreeNode(this.t, false);

            // The old root becomes the first child of the new root
            newRoot.children.push(this.root);

            // Split the old root and update the new root with the middle key
            newRoot.splitChild(0, root);

            // Determine which child to insert the key into
            const idx = newRoot.keys[0] > key ? 0 : 1;
            newRoot.children[idx].insertNonFull(key);

            // Update the root reference to point to the new root
            this.root = newRoot;
        } else {
            // If the root is not full, insert the key directly into the root
            root.insertNonFull(key);
        }
    }

    /**
     * Searches for a key in the B-Tree.
     *
     * Starts the search from the root and delegates to the BTreeNode's search method.
     * @param {any} key - The key to search for in the B-Tree.
     * @returns {BTreeNode|null} - The node containing the key, or null if not found.
     */
    search(key) {
        return this.root.search(key);
    }

    /**
     * Removes a key from the B-Tree.
     *
     * If the key exists, it is removed, and the tree structure is adjusted to maintain
     * B-Tree properties. If the root becomes empty, the root is updated.
     *
     * @param {any} key - The key to remove from the B-Tree.
     */
    remove(key) {
        if (!this.root) return;  // Return if the tree is empty

        this.root.remove(key);   // Remove the key from the root

        // If the root node has no keys after removal, update the root reference
        if (this.root.keys.length === 0) {
            // If the root has children, set the first child as the new root, else set root to null
            this.root = this.root.isLeaf ? null : this.root.children[0];
        }
    }

    /**
     * Prints the structure of the B-Tree.
     *
     * Calls the print method on the root node, which recursively prints keys at each level.
     * This method provides a visual representation of the B-Tree structure, level by level.
     */
    printTree() {
        if (this.root) {
            this.root.printNode();
        }
    }
}

module.exports = BTree;
