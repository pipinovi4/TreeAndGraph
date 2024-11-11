class BPTreeNode {
    /**
     * Initializes a B+ Tree node.
     * @param {number} t - Minimum degree (defines range for number of keys).
     * @param {boolean} isLeaf - Indicates if the node is a leaf.
     */
    constructor(t, isLeaf = false) {
        this.t = t;
        this.isLeaf = isLeaf;
        this.keys = [];        // Stores keys in the node
        this.children = [];    // Stores child pointers for internal nodes
        this.next = null;      // Pointer to the next leaf node (used for range queries)
    }

    /**
     * Inserts a key into a non-full node.
     * If the node is a leaf, the key is inserted directly in sorted order.
     * If the node is an internal node, it finds the correct child to descend.
     * @param {number} key - The key to insert.
     */
    insertNonFull(key) {
        if (this.isLeaf) {
            // Find the correct position for the key and insert it in sorted order
            let i = 0;
            while (i < this.keys.length && this.keys[i] < key) {
                i++;
            }
            this.keys.splice(i, 0, key); // Insert key at the correct position
        } else {
            // Navigate to the correct child for insertion
            let i = this.keys.length - 1;
            while (i >= 0 && key < this.keys[i]) {
                i--;
            }
            i++;

            // Split child if it is full
            if (this.children[i].keys.length === 2 * this.t - 1) {
                this.splitChildren(i);
                if (key > this.keys[i]) i++;
            }
            this.children[i].insertNonFull(key);
        }
    }

    /**
     * Splits a full child of this node.
     * After splitting, the median key from the child is moved up to the parent node,
     * and the child is split into two nodes.
     * @param {number} i - The index of the child to split.
     */
    splitChildren(i) {
        const t = this.t;
        const child = this.children[i];
        const newChild = new BPTreeNode(t, child.isLeaf);

        // Divide keys and children between the two nodes
        newChild.keys = child.keys.slice(t); // Right half goes to newChild
        child.keys = child.keys.slice(0, t - 1); // Left half stays in child

        // If the node is not a leaf, also divide the children
        if (!child.isLeaf) {
            newChild.children = child.children.slice(t);
            child.children = child.children.slice(0, t);
        }

        // Adjust linked list pointers for leaf nodes
        if (child.isLeaf) {
            newChild.next = child.next; // Link newChild to the next leaf
            child.next = newChild;      // Link current child to newChild
        }

        // Insert median key into this node and add newChild as a child
        this.keys.splice(i, 0, child.keys.pop()); // Move median key up
        this.children.splice(i + 1, 0, newChild); // Insert newChild as a sibling
    }
}

module.exports = BPTreeNode;
