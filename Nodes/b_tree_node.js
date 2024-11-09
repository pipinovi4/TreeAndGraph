class BTreeNode {
    constructor(t, isLeaf = true) {
        this.t = t;               // Minimum degree (defines the range for number of keys)
        this.isLeaf = isLeaf;      // True if leaf node, otherwise false
        this.keys = [];            // Array to store keys
        this.children = [];        // Array to store child nodes
    }

    insertNonFull(key) {
        let i = this.keys.length - 1;

        if (this.isLeaf) {
            // Insert the new key at the correct position in sorted order
            this.keys.push(null); // Temporary space for the new key
            while (i >= 0 && key < this.keys[i]) {
                this.keys[i + 1] = this.keys[i];
                i -= 1;
            }
            this.keys[i + 1] = key;
        } else {
            // Find the child that will receive the new key
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
            this.children[i].insertNonFull(key);
        }
    }

    splitChild(i, y) {
        const t = this.t;
        const z = new BTreeNode(t, y.isLeaf);

        // Copy the last t-1 keys from y to z
        z.keys = y.keys.slice(t);
        if (!y.isLeaf) {
            // If y is not a leaf, move the last t children to z
            z.children = y.children.slice(t);
        }

        // Keep only the first t-1 keys in y
        y.keys = y.keys.slice(0, t - 1);
        y.children = y.children.slice(0, t); // Retain only the first t children if not a leaf

        // Insert z as a child of this node and move the middle key of y to this node
        this.children.splice(i + 1, 0, z);
        const middleKey = y.keys.pop();
        this.keys.splice(i, 0, middleKey);
    }

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

    remove(key) {
        const idx = this.findKey(key);

        if (idx < this.keys.length && this.keys[idx] === key) {
            if (this.isLeaf) {
                this.removeFromLeaf(idx);
            } else {
                this.removeFromNonLeaf(idx);
            }
        } else {
            if (this.isLeaf) {
                return;
            }
            const flag = idx === this.keys.length;
            if (this.children[idx].keys.length < this.t) {
                this.fill(idx);
            }
            if (flag && idx > this.keys.length) {
                this.children[idx - 1].remove(key);
            } else {
                this.children[idx].remove(key);
            }
        }
    }

    findKey(key) {
        let idx = 0;
        while (idx < this.keys.length && this.keys[idx] < key) {
            idx += 1;
        }
        return idx;
    }

    getPred(idx) {
        let cur = this.children[idx];
        while (!cur.isLeaf) {
            cur = cur.children[cur.children.length - 1];
        }
        return cur.keys[cur.keys.length - 1];
    }

    getSucc(idx) {
        let cur = this.children[idx + 1];
        while (!cur.isLeaf) {
            cur = cur.children[0];
        }
        return cur.keys[0];
    }

    removeFromLeaf(idx) {
        this.keys.splice(idx, 1);
    }

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

    borrowFromPrev(idx) {
        const child = this.children[idx];
        const sibling = this.children[idx - 1];
        child.keys.unshift(this.keys[idx - 1]);
        if (!child.isLeaf) {
            child.children.unshift(sibling.children.pop());
        }
        this.keys[idx - 1] = sibling.keys.pop();
    }

    borrowFromNext(idx) {
        const child = this.children[idx];
        const sibling = this.children[idx + 1];
        child.keys.push(this.keys[idx]);
        if (!child.isLeaf) {
            child.children.push(sibling.children.shift());
        }
        this.keys[idx] = sibling.keys.shift();
    }

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

    printNode(level = 0) {
        console.log("Level", level, "Keys:", this.keys);
        for (let child of this.children) {
            child.printNode(level + 1);
        }
    }
}

module.exports = BTreeNode;