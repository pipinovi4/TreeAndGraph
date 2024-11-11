
class BPTree {
    constructor(t) {
        this.t = t;
        this.root = new BPTreeNode(t, true); // Initialize with a single leaf node
    }

    insert(key) {
        const root = this.root;
        if (root.keys.length === 2 * this.t - 1) { // Root is full
            const newRoot = new BPTreeNode(this.t, false);
            newRoot.children.push(root);
            newRoot.splitChild(0);
            this.root = newRoot; // Update root reference
        }
        this.root.insertNonFull(key);
    }

    search(key) {
        let node = this.root;
        while (!node.isLeaf) {
            let i = 0;
            while (i < node.keys.length && key >= node.keys[i]) i++;
            node = node.children[i];
        }
        return node.keys.includes(key) ? node : null;
    }

    delete(key) {
        this._deleteRecursive(this.root, key);
        if (this.root.keys.length === 0 && !this.root.isLeaf) {
            this.root = this.root.children[0]; // Update root if it becomes empty
        }
    }

    rangeQuery(startKey, endKey) {
        const result = [];
        let node = this.root;

        while (!node.isLeaf) {
            let i = 0;
            while (i < node.keys.length && startKey > node.keys[i]) i++;
            node = node.children[i];
        }

        // Collect keys within range in leaf nodes
        while (node) {
            for (const key of node.keys) {
                if (key >= startKey && key <= endKey) result.push(key);
                else if (key > endKey) return result;
            }
            node = node.next;
        }
        return result;
    }

    _deleteRecursive(node, key) {
        if (node.isLeaf) {
            const keyIndex = node.keys.indexOf(key);
            if (keyIndex !== -1) node.keys.splice(keyIndex, 1); // Remove key if found
        } else {
            let i = 0;
            while (i < node.keys.length && key > node.keys[i]) i++;
            if (i < node.keys.length && key === node.keys[i]) {
                if (node.children[i].isLeaf) {
                    node.keys[i] = node.children[i].keys[node.children[i].keys.length - 1];
                    this._deleteRecursive(node.children[i], node.keys[i]);
                } else {
                    node.keys[i] = node.children[i + 1].keys[0];
                    this._deleteRecursive(node.children[i + 1], node.keys[i]);
                }
            } else {
                if (node.children[i].keys.length < this.t) this._fixChild(node, i);
                this._deleteRecursive(node.children[i], key);
            }
        }
    }

    _fixChild(parent, index) {
        const t = this.t;
        const leftSibling = index > 0 ? parent.children[index - 1] : null;
        const rightSibling = index < parent.children.length - 1 ? parent.children[index + 1] : null;
        const currentChild = parent.children[index];

        if (leftSibling && leftSibling.keys.length >= t) {
            currentChild.keys.unshift(parent.keys[index - 1]);
            if (!leftSibling.isLeaf) currentChild.children.unshift(leftSibling.children.pop());
            parent.keys[index - 1] = leftSibling.keys.pop();
        } else if (rightSibling && rightSibling.keys.length >= t) {
            currentChild.keys.push(parent.keys[index]);
            if (!rightSibling.isLeaf) currentChild.children.push(rightSibling.children.shift());
            parent.keys[index] = rightSibling.keys.shift();
        } else {
            if (leftSibling) this._mergeNodes(parent, index - 1);
            else this._mergeNodes(parent, index);
        }
    }

    _mergeNodes(parent, index) {
        const leftChild = parent.children[index];
        const rightChild = parent.children.splice(index + 1, 1)[0];
        leftChild.keys.push(parent.keys.splice(index, 1)[0]);
        leftChild.keys = leftChild.keys.concat(rightChild.keys);

        if (!leftChild.isLeaf) leftChild.children = leftChild.children.concat(rightChild.children);
        else leftChild.next = rightChild.next;
    }

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