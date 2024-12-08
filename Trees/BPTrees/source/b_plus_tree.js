const BPTreeNode = require("../../Nodes/BPTreeNodes/b_plus_tree_node");

/**
 * Class representing a B+ Tree.
 */
class BPTree {
    /**
     * Initializes a B+ Tree with a specified minimum degree.
     * @param {number} t - The minimum degree of the B+ Tree (defines the range for the number of keys).
     */
    constructor(t) {
        if (t < 2) throw new Error("B+ Tree minimum degree must be at least 2");
        this.t = t;
        this.root = new BPTreeNode(t, true); // Start with a single leaf node
    }

    /**
     * Inserts a key into the B+ Tree.
     * If the root is full, a new root is created and the tree height increases.
     * @param {number} key - The key to be inserted.
     */
    insert(key) {
        const root = this.root;
        // If the root is full, split it and increase tree height
        if (root.keys.length === 2 * this.t - 1) {
            const newRoot = new BPTreeNode(this.t, false);
            newRoot.children.push(root);
            newRoot.splitChildren(0);
            this.root = newRoot; // Update root reference
        }
        this.root.insertNonFull(key);
    }

    /**
     * Searches for a key in the B+ Tree.
     * @param {number} key - The key to search for.
     * @returns {BPTreeNode|null} - Node containing the key or null if not found.
     */
    search(key) {
        let node = this.root;
        while (!node.isLeaf) {
            let i = 0;
            while (i < node.keys.length && key >= node.keys[i]) i++;
            node = node.children[i];
        }
        return node.keys.includes(key) ? node : null;
    }

    /**
     * Deletes a key from the B+ Tree.
     * Calls the internal recursive delete function and updates the root if necessary.
     * @param {number} key - The key to be deleted.
     */
    delete(key) {
        this._deleteRecursive(this.root, key);
        // If the root is empty and has children, update the root reference
        if (this.root.keys.length === 0 && !this.root.isLeaf) {
            this.root = this.root.children[0];
        }
    }

    /**
     * Returns all keys within a specified range [startKey, endKey].
     * Uses linked leaf nodes for efficient range retrieval.
     * @param {number} startKey - The start of the range.
     * @param {number} endKey - The end of the range.
     * @returns {Array} - List of keys within the specified range.
     */
    rangeQuery(startKey, endKey) {
        const result = [];
        let node = this.root;

        // Navigate to the correct leaf node for startKey
        while (!node.isLeaf) {
            let i = 0;
            while (i < node.keys.length && startKey > node.keys[i]) i++;
            node = node.children[i];
        }

        // Collect keys within range across linked leaf nodes
        while (node) {
            for (const key of node.keys) {
                if (key >= startKey && key <= endKey) result.push(key);
                else if (key > endKey) return result;
            }
            node = node.next;
        }
        return result;
    }

    /**
     * Internal recursive function for deleting a key from a B+ Tree node.
     * @param {BPTreeNode} node - The current node to delete the key from.
     * @param {number} key - The key to be deleted.
     * @private
     */
    _deleteRecursive(node, key) {
        if (!node) return; // Return if node is undefined

        if (node.isLeaf) {
            // Remove key from leaf node if found
            const keyIndex = node.keys.indexOf(key);
            if (keyIndex !== -1) node.keys.splice(keyIndex, 1);
        } else {
            let i = 0;
            while (i < node.keys.length && key > node.keys[i]) i++;

            // Handle deletion in internal nodes
            if (i < node.keys.length && key === node.keys[i]) {
                if (node.children[i] && node.children[i].isLeaf) {
                    // Replace key with largest key in left child
                    node.keys[i] = node.children[i].keys[node.children[i].keys.length - 1];
                    this._deleteRecursive(node.children[i], node.keys[i]);
                } else if (node.children[i + 1]) {
                    // Replace key with smallest key in right child
                    node.keys[i] = node.children[i + 1].keys[0];
                    this._deleteRecursive(node.children[i + 1], node.keys[i]);
                }
            } else if (node.children[i]) {
                // Fix underflow if necessary and continue deletion
                if (node.children[i].keys.length < this.t) this._fixChild(node, i);
                this._deleteRecursive(node.children[i], key);
            }
        }
    }

    /**
     * Helper function to fix an underflowed child by borrowing from siblings or merging.
     * @param {BPTreeNode} parent - The parent node containing the underflowed child.
     * @param {number} index - The index of the child in the parent.
     * @private
     */
    _fixChild(parent, index) {
        const t = this.t;
        const leftSibling = index > 0 ? parent.children[index - 1] : null;
        const rightSibling = index < parent.children.length - 1 ? parent.children[index + 1] : null;
        const currentChild = parent.children[index];

        if (leftSibling && leftSibling.keys.length >= t) {
            // Borrow from the left sibling
            currentChild.keys.unshift(parent.keys[index - 1]);
            if (!leftSibling.isLeaf) currentChild.children.unshift(leftSibling.children.pop());
            // Update parent key
            parent.keys[index - 1] = leftSibling.keys.pop();
        } else if (rightSibling && rightSibling.keys.length >= t) {
            // Borrow from the right sibling
            currentChild.keys.push(parent.keys[index]);
            if (!rightSibling.isLeaf) currentChild.children.push(rightSibling.children.shift());
            // Update parent key
            parent.keys[index] = rightSibling.keys.shift();
        } else {
            // Merge with a sibling
            if (leftSibling) {
                this._mergeNodes(parent, index - 1);
            } else {
                this._mergeNodes(parent, index);
            }
        }
    }

    /**
     * Helper function to merge two sibling nodes and their parent key.
     * @param {BPTreeNode} parent - The parent node containing the siblings to merge.
     * @param {number} index - The index of the left child to merge with the right sibling.
     * @private
     */
    _mergeNodes(parent, index) {
        const leftChild = parent.children[index];
        const rightChild = parent.children.splice(index + 1, 1)[0];

        // Move parent key down into the left child
        leftChild.keys.push(parent.keys.splice(index, 1)[0]);
        leftChild.keys = leftChild.keys.concat(rightChild.keys);

        if (!leftChild.isLeaf) {
            leftChild.children = leftChild.children.concat(rightChild.children);
        } else {
            // Update leaf linked list for range queries
            leftChild.next = rightChild.next;
        }
    }

    /**
     * Prints the B+ Tree structure level by level.
     */
    printTree() {
        let level = [this.root];
        while (level.length > 0) {
            const nextLevel = [];
            let levelOutput = "";
            for (const node of level) {
                levelOutput += `[${node.keys.join(", ")}] `;
                if (!node.isLeaf) nextLevel.push(...node.children);
            }
            console.log(levelOutput);
            level = nextLevel;
        }
    }
}

module.exports = BPTree;
