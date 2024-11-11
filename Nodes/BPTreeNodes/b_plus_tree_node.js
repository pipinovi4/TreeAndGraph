class BPTreeNode {
    constructor(t, isLeaf = false) {
        this.t = t;
        this.isLeaf = isLeaf;
        this.keys = [];
        this.children = [];
        this.next = null; // Pointer to the next leaf node (used for range queries)
    }

    insertNonFull(key) {
        if (this.isLeaf) {
            // Insert key into the sorted position within the leaf node
            let i = 0;
            while (i < this.keys.length && this.keys[i] < key) {
                i++;
            }
            this.keys.splice(i, 0, key); // Insert at the correct sorted position
        } else {
            // Navigate to the correct child for insertion
            let i = this.keys.length - 1;
            while (i >= 0 && key < this.keys[i]) {
                i--;
            }
            i++;

            // Split child if it is full
            if (this.children[i].keys.length === 2 * this.t - 1) {
                this.splitChild(i);
                if (key > this.keys[i]) i++;
            }
            this.children[i].insertNonFull(key);
        }
    }

    splitChild(i) {
        const t = this.t;
        const child = this.children[i];
        const newChild = new BPTreeNode(t, child.isLeaf);

        // Split the keys and children
        newChild.keys = child.keys.slice(t);
        child.keys = child.keys.slice(0, t - 1);

        if (!child.isLeaf) {
            newChild.children = child.children.slice(t);
            child.children = child.children.slice(0, t);
        }

        // Adjust linked list pointers for leaf nodes
        if (child.isLeaf) {
            newChild.next = child.next;
            child.next = newChild;
        }

        // Insert median key into this node and adjust child pointers
        this.keys.splice(i, 0, child.keys.pop());
        this.children.splice(i + 1, 0, newChild);
    }
}