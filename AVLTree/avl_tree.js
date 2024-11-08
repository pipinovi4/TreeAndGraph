const Node = require("../Nodes/node")

class AVLTree {
    constructor() {
        this.root = null;
    }

    _height(node) {
        if (!node) {
            return 0;
        }
        return node.height;
    }

    _updateHeight(node) {
        if (!node) return;
        node.height = 1 + Math.max(this._height(node.left), this._height(node.right));
    }

    _getBalance(node) {
        if (!node) {
            return 0;
        }
        return this._height(node.left) - this._height(node.right);
    }

    _rightRotate(y) {
        const x = y.left;
        const t2 = x.right;

        // Perform rotation
        x.right = y;
        y.left = t2;

        // Update heights after rotation
        this._updateHeight(y);
        this._updateHeight(x);

        // Return new root of the subtree
        return x;
    }

    _leftRotation(x) {
        let y = x.right;
        let t2 = y.left;

        y.left = x;
        x.right = t2;

        this._updateHeight(x);
        this._updateHeight(y);

        return y;
    }

    insert(data) {
        this.root = this._insert(this.root, data);
    }

    _insert(node, data) {
        if (!node) {
            return new Node(data);
        }

        if (data < node.data) {
            node.left = this._insert(node.left, data);
        } else if (data > node.data) {
            node.right = this._insert(node.right, data);
        } else {
            return node;
        }

        this._updateHeight(node);
        const balance = this._getBalance(node);

        if (balance > 1 && data < node.left.data) {
            return this._rightRotate(node);
        }
        if (balance < -1 && data > node.right.data) {
            return this._leftRotation(node);
        }
        if (balance > 1 && data > node.left.data) {
            node.left = this._leftRotation(node.left);
            return this._rightRotate(node);
        }
        if (balance < -1 && data < node.right.data) {
            node.right = this._rightRotate(node.right);
            return this._leftRotation(node);
        }

        return node;
    }

    search(target) {
        return this._search(this.root, target);
    }

    _search(node, target) {
        if (!target) {
            return false;
        }
        if (target === node.data) {
            return true;
        } else if (target < node.data) {
            return this._search(node.left, target);
        } else {
            return this._search(node.right, target)
        }
    }

    delete(data) {
        this.root = this._delete(this.root, data);
    }

    _delete(node, data) {
        if (!data) {
            return node;
        }

        if (data < node.data) {
            node.left = this._delete(node.left, data);
        } else if (data > node.data) {
            node.right = this._delete(node.right, data);
        } else {
            if (!node.left) {
                return node.left;
            } else if (!node.right) {
                return node.right;
            }

            const temp = this._minValueNode(node.right);
            node.data = temp.data;
            node.right = this._delete(node.right, temp.data);
        }

        this._updateHeight(node);
        const balance = this._getBalance(node);

        if (balance > 1 && data < node.left.data) {
            return this._rightRotate(node);
        }
        if (balance < -1 && data > node.right.data) {
            return this._leftRotation(node);
        }
        if (balance > 1 && data > node.left.data) {
            node.left = this._leftRotation(node.left);
            return this._rightRotate(node);
        }
        if (balance < -1 && data < node.right.data) {
            node.right = this._rightRotate(node.right);
            return this._leftRotation(node);
        }

        return node;
    }

    _minValueNode(node) {
        let current = node;
        while (current.left) {
            current = current.left;
        }
        return current;
    }

    printInOrder() {
        const stack = [];
        let current = this.root;

        while (stack.length > 0 || current !== null) {
            // Traverse to the leftmost node
            while (current !== null) {
                stack.push(current);
                current = current.left;
            }

            // Process the node
            current = stack.pop();
            process.stdout.write(`${current.data} `);

            // Traverse the right subtree
            current = current.right;
        }
    }
}