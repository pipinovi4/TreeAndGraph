class BTreeNode {
    constructor(t, is_leaf = true) {
        this.t = t;
        this.is_leaf = is_leaf;
        this.keys = [];
        this.children = [];
    }

    _insertNonFull(key) {
        const i = this.keys.length - 1

        if
    }
}

module.exports = BTreeNode;
