const BTreeNode = require("../Nodes/b_tree_node")

class BTree {
    constructor(t) {
        this.root = new BTreeNode(t);
        this.t = t;
    }

    insert(key) {
        const root = this.root;
        if (root.keys.length === 2 * this.t - 1) {
            const newRoot = new BTreeNode(this.t, false);
            newRoot.children.push(this.root);
            newRoot.splitChild(0, root);

            const idx = newRoot.keys[0] > key ? 0 : 1;
            newRoot.children[idx].insertNonFull(key);
            this.root = newRoot;
        } else {
            root.insertNonFull(key);
        }
    }

    search(key) {
        return this.root.search(key);
    }

    remove(key) {
        if (!this.root) return;
        this.root.remove(key);
        if (this.root.keys.length === 0) {
            this.root = this.root.isLeaf ? null : this.root.children[0];
        }
    }

    printTree() {
        if (this.root) {
            this.root.printNode();
        }
    }
}

module.exports = BTree;