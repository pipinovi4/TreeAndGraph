/**
 * Class representing a B-Tree node.
 */
class BTreeNode {
    /**
     * Constructs a BTreeNode.
     * @param {number} t - The minimum degree of the B-Tree.
     * @param {boolean} isLeaf - Indicates if the node is a leaf node.
     */
    constructor(t, isLeaf = true) {
        this.t = t;               // Minimum degree (defines the range for number of keys)
        this.isLeaf = isLeaf;      // True if leaf node, otherwise false
        this.keys = [];            // Array to store keys
        this.children = [];        // Array to store child nodes
    }

    /**
     * Inserts a new key into a non-full node.
     * If the node is a leaf, inserts directly. Otherwise, descends to the appropriate child.
     * @param {any} key - The key to insert.
     */
    insertNonFull(key) {
        let i = this.keys.length - 1;

        if (this.isLeaf) {
            // For leaf node, insert the new key in sorted order
            this.keys.push(null); // Add temporary space for the new key
            while (i >= 0 && key < this.keys[i]) {
                this.keys[i + 1] = this.keys[i];
                i -= 1;
            }
            this.keys[i + 1] = key; // Insert the key at the correct position
        } else {
            // Find the child that should receive the new key
            while (i >= 0 && key < this.keys[i]) {
                i -= 1;
            }
            i += 1;

            // If the child is full, split it
            if (this.children[i].keys.length === 2 * this.t - 1) {
                this.splitChild(i, this.children[i]);
                if (key > this.keys[i]) {
                    i += 1;
                }
            }
            // Insert into the appropriate child
            this.children[i].insertNonFull(key);
        }
    }

    /**
     * Splits a full child of this node.
     * @param {number} i - Index of the child to split.
     * @param {BTreeNode} y - The child node to be split.
     */
    splitChild(i, y) {
        const t = this.t;
        const z = new BTreeNode(t, y.isLeaf);

        // Move the last t-1 keys and children of y to z
        z.keys = y.keys.slice(t);
        if (!y.isLeaf) {
            z.children = y.children.slice(t);
        }

        // Retain only the first t-1 keys in y
        y.keys = y.keys.slice(0, t - 1);
        y.children = y.children.slice(0, t); // Retain only the first t children if not a leaf

        // Insert z as a new child of this node and move the middle key to this node
        this.children.splice(i + 1, 0, z);
        const middleKey = y.keys.pop();
        this.keys.splice(i, 0, middleKey);
    }

    /**
     * Searches for a key in the B-Tree rooted at this node.
     * @param {any} key - The key to search for.
     * @returns {BTreeNode|null} - Node containing the key, or null if not found.
     */
    search(key) {
        const i = this.findKey(key);
        if (i < this.keys.length && key === this.keys[i]) {
            return this;
        }
        if (this.isLeaf) {
            return null;
        }
        return this.children[i].search(key);
    }

    /**
     * Removes a key from the subtree rooted with this node.
     * @param {any} key - The key to remove.
     */
    remove(key) {
        const idx = this.findKey(key);

        if (idx < this.keys.length && this.keys[idx] === key) {
            // Key found in this node
            if (this.isLeaf) {
                this.removeFromLeaf(idx);
            } else {
                this.removeFromNonLeaf(idx);
            }
        } else {
            // Key not found in this node
            if (this.isLeaf) {
                return;  // Key is not in the tree
            }

            const flag = idx === this.keys.length;
            if (this.children[idx].keys.length < this.t) {
                this.fill(idx);
            }

            // Adjust idx based on whether we've filled the last child
            if (flag && idx > this.keys.length) {
                this.children[idx - 1].remove(key);
            } else {
                this.children[idx].remove(key);
            }
        }
    }

    /**
     * Finds the index of the first key greater than or equal to the given key.
     * @param {any} key - The key to find.
     * @returns {number} - Index of the key or position where it should be inserted.
     */
    findKey(key) {
        let idx = 0;
        while (idx < this.keys.length && this.keys[idx] < key) {
            idx += 1;
        }
        return idx;
    }

    /**
     * Gets the predecessor of the key at index idx.
     * @param {number} idx - Index of the key.
     * @returns {any} - The predecessor key.
     */
    getPred(idx) {
        let cur = this.children[idx];
        while (!cur.isLeaf) {
            cur = cur.children[cur.children.length - 1];
        }
        return cur.keys[cur.keys.length - 1];
    }

    /**
     * Gets the successor of the key at index idx.
     * @param {number} idx - Index of the key.
     * @returns {any} - The successor key.
     */
    getSucc(idx) {
        let cur = this.children[idx + 1];
        while (!cur.isLeaf) {
            cur = cur.children[0];
        }
        return cur.keys[0];
    }

    /**
     * Removes a key from a leaf node.
     * @param {number} idx - Index of the key.
     */
    removeFromLeaf(idx) {
        this.keys.splice(idx, 1);
    }

    /**
     * Removes a key from a non-leaf node.
     * @param {number} idx - Index of the key.
     */
    removeFromNonLeaf(idx) {
        const key = this.keys[idx];
        if (this.children[idx].keys.length >= this.t) {
            const pred = this.getPred(idx);
            this.keys[idx] = pred;
            this.children[idx].remove(pred);
        } else if (this.children[idx + 1].keys.length >= this.t) {
            const succ = this.getSucc(idx);
            this.keys[idx] = succ;
            this.children[idx + 1].remove(succ);
        } else {
            this.merge(idx);
            this.children[idx].remove(key);
        }
    }

    /**
     * Ensures the child node at index idx has at least t keys.
     * @param {number} idx - Index of the child.
     */
    fill(idx) {
        if (idx !== 0 && this.children[idx - 1].keys.length >= this.t) {
            this.borrowFromPrev(idx);
        } else if (idx !== this.keys.length && this.children[idx + 1].keys.length >= this.t) {
            this.borrowFromNext(idx);
        } else {
            if (idx !== this.keys.length) {
                this.merge(idx);
            } else {
                this.merge(idx - 1);
            }
        }
    }

    /**
     * Borrows a key from the previous child.
     * @param {number} idx - Index of the child.
     */
    borrowFromPrev(idx) {
        const child = this.children[idx];
        const sibling = this.children[idx - 1];
        child.keys.unshift(this.keys[idx - 1]);
        if (!child.isLeaf) {
            child.children.unshift(sibling.children.pop());
        }
        this.keys[idx - 1] = sibling.keys.pop();
    }

    /**
     * Borrows a key from the next child.
     * @param {number} idx - Index of the child.
     */
    borrowFromNext(idx) {
        const child = this.children[idx];
        const sibling = this.children[idx + 1];
        child.keys.push(this.keys[idx]);
        if (!child.isLeaf) {
            child.children.push(sibling.children.shift());
        }
        this.keys[idx] = sibling.keys.shift();
    }

    /**
     * Merges children[idx] and children[idx + 1] into a single node.
     * @param {number} idx - Index of the child.
     */
    merge(idx) {
        const child = this.children[idx];
        const sibling = this.children[idx + 1];

        // Move the middle key down from the current node to the child
        child.keys.push(this.keys[idx]);
        this.keys.splice(idx, 1);

        // Concatenate keys and children from the sibling to the child
        child.keys = child.keys.concat(sibling.keys);
        if (!child.isLeaf) {
            child.children = child.children.concat(sibling.children);
        }

        // Remove the sibling from the children array
        this.children.splice(idx + 1, 1);
    }

    /**
     * Prints keys at the current level and recurses for child nodes.
     * @param {number} level - Current level in the tree.
     */
    printNode(level = 0) {
        console.log("Level", level, "Keys:", this.keys);
        for (let child of this.children) {
            child.printNode(level + 1);
        }
    }
}

module.exports = BTreeNode;
