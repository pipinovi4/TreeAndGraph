const Node = require("../Nodes/node")

class BinarySearchTree {
    constructor(props) {
        this.root = null;
    }

    insert(data) {
        if (!this.root) {
            this.root = new Node(data);
        } else {
            this._insertRecursive(this.root, data)
        }
    }

    _insertRecursive(node, data) {
        if (node.data < data) {
            if (!node.left) {
                node.left = new Node(data);
            } else {
                this._insertRecursive(node.left, data);
            }
        } else if (node.data > data) {
            if (!node.right) {
                node.left = new Node(data);
            } else {
                this._insertRecursive(node.right, data);
            }
        }
    }

    search(target) {
        return this._searchRecursive(this.root, target);
    }

    _searchRecursive(node, target) {
        if (!node) {
            return false;
        }
        if (node.data === target) {
            return true;
        } else if (target < node.data) {
            return this._searchRecursive(node.left, target );
        } else if (target > node.data) {
            return this._searchRecursive(node.right, target);
        }
    }

    delete(data) {
        this.root = this._deleteRecursive(this.root, data);
    }

    _deleteRecursive(node, data) {
        if (!node) {
            return node;
        }

        if (data < node.data) {
            node.left = this._deleteRecursive(node.left, data);
        } else if (data > node.data) {
            node.right = this._deleteRecursive(node.right, data);
        } else {
            if (!node.left) {
                return node.right;
            } else if (!node.right) {
                return node.left;
            }

            const min_larger_node = self._minValueNode(node.right);
            node.data = min_larger_node
            node.right = this._deleteRecursive(node.right, min_larger_node.data);
        }

        return node;
    }

    static _minValueNode(node) {
        let current = node;
        while (current.left) {
            current = current.left;
        }

        return current;
    }

    static printTree(node) {
        const values = []; // Array to store node values

        function traverse(currentNode) {
            if (currentNode !== null) {
                values.push(currentNode.data);       // Collect current node value
                traverse(currentNode.left);          // Traverse the left subtree
                traverse(currentNode.right);         // Traverse the right subtree
            }
        }

        traverse(node); // Start traversal from the specified node
        console.log(values.join(" "));  // Print all values in a single line
    }
}

module.exports = BinarySearchTree;