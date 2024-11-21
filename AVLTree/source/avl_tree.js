const Node = require("../Nodes/defaultNodes/node");

/**
 * AVLTree class implementing a self-balancing binary search tree (AVL Tree).
 * The AVL Tree keeps the height of the tree balanced after each insertion and deletion
 * to ensure efficient `O(log n)` performance for search, insert, and delete operations.
 */
class AVLTree {
    constructor() {
        this.root = null; // Initialize the root of the AVL Tree as null
    }

    /**
     * Utility method to get the height of a node.
     * @param {Node} node - The node to get the height for.
     * @returns {number} The height of the node; 0 if the node is null.
     */
    _height(node) {
        return node ? node.height : 0;
    }

    /**
     * Update the height of a node based on the heights of its children.
     * @param {Node} node - The node whose height is to be updated.
     */
    _updateHeight(node) {
        if (node) {
            node.height = 1 + Math.max(this._height(node.left), this._height(node.right));
        }
    }

    /**
     * Calculate the balance factor of a node.
     * Balance factor is the height difference between left and right subtrees.
     * @param {Node} node - The node for which balance factor is calculated.
     * @returns {number} The balance factor (positive for left-heavy, negative for right-heavy).
     */
    _getBalance(node) {
        return node ? this._height(node.left) - this._height(node.right) : 0;
    }

    /**
     * Perform a right rotation on the subtree rooted at `y`.
     * This is used to fix left-heavy imbalance.
     * @param {Node} y - The root of the unbalanced subtree.
     * @returns {Node} The new root of the rotated subtree.
     */
    _rightRotate(y) {
        const x = y.left;
        const t2 = x.right;

        // Perform rotation
        x.right = y;
        y.left = t2;

        // Update heights
        this._updateHeight(y);
        this._updateHeight(x);

        return x; // New root of the subtree
    }

    /**
     * Perform a left rotation on the subtree rooted at `x`.
     * This is used to fix right-heavy imbalance.
     * @param {Node} x - The root of the unbalanced subtree.
     * @returns {Node} The new root of the rotated subtree.
     */
    _leftRotation(x) {
        const y = x.right;
        const t2 = y.left;

        // Perform rotation
        y.left = x;
        x.right = t2;

        // Update heights
        this._updateHeight(x);
        this._updateHeight(y);

        return y; // New root of the subtree
    }

    /**
     * Insert a new value into the AVL Tree.
     * @param {number} data - The value to be inserted.
     */
    insert(data) {
        this.root = this._insert(this.root, data);
    }

    /**
     * Recursive helper method to insert a new value into the AVL Tree.
     * Adjusts heights and balances the tree if it becomes unbalanced.
     * @param {Node} node - The current node in the recursive traversal.
     * @param {number} data - The value to be inserted.
     * @returns {Node} The new root of the subtree after insertion.
     */
    _insert(node, data) {
        if (!node) return new Node(data); // Insert the new node here if subtree is empty

        if (data < node.data) {
            node.left = this._insert(node.left, data);
        } else if (data > node.data) {
            node.right = this._insert(node.right, data);
        } else {
            return node; // Duplicate data are not allowed
        }

        // Update height and balance of this node
        this._updateHeight(node);
        const balance = this._getBalance(node);

        // Perform rotations to maintain AVL balance
        // Left Left Case
        if (balance > 1 && data < node.left.data) {
            return this._rightRotate(node);
        }
        // Right Right Case
        if (balance < -1 && data > node.right.data) {
            return this._leftRotation(node);
        }
        // Left Right Case
        if (balance > 1 && data > node.left.data) {
            node.left = this._leftRotation(node.left);
            return this._rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && data < node.right.data) {
            node.right = this._rightRotate(node.right);
            return this._leftRotation(node);
        }

        return node; // Return the (unchanged) node pointer
    }

    /**
     * Search for a target value in the AVL Tree.
     * @param {number} target - The value to search for.
     * @returns {boolean} True if the value is found, false otherwise.
     */
    search(target) {
        return this._search(this.root, target);
    }

    /**
     * Recursive helper method to search for a target value in the AVL Tree.
     * @param {Node} node - The current node in the recursive traversal.
     * @param {number} target - The value to search for.
     * @returns {boolean} True if the value is found, false otherwise.
     */
    _search(node, target) {
        if (!node) return false; // Not found
        if (target === node.data) return true; // Value found
        return target < node.data ? this._search(node.left, target) : this._search(node.right, target);
    }

    /**
     * Delete a value from the AVL Tree and maintain balance.
     * @param {number} data - The value to be deleted.
     */
    delete(data) {
        this.root = this._delete(this.root, data);
    }

    /**
     * Recursive helper method to delete a value from the AVL Tree.
     * Adjusts heights and rebalances the tree after deletion.
     * @param {Node} node - The current node in the recursive traversal.
     * @param {number} data - The value to be deleted.
     * @returns {Node} The new root of the subtree after deletion.
     */
    _delete(node, data) {
        if (!node) return node;

        if (data < node.data) {
            node.left = this._delete(node.left, data);
        } else if (data > node.data) {
            node.right = this._delete(node.right, data);
        } else {
            if (!node.left) return node.right;
            if (!node.right) return node.left;

            const temp = this._minValueNode(node.right);
            node.data = temp.data;
            node.right = this._delete(node.right, temp.data);
        }

        this._updateHeight(node);
        const balance = this._getBalance(node);

        // Perform rotations to maintain AVL balance after deletion
        if (balance > 1 && this._getBalance(node.left) >= 0) {
            return this._rightRotate(node);
        }
        if (balance < -1 && this._getBalance(node.right) <= 0) {
            return this._leftRotation(node);
        }
        if (balance > 1 && this._getBalance(node.left) < 0) {
            node.left = this._leftRotation(node.left);
            return this._rightRotate(node);
        }
        if (balance < -1 && this._getBalance(node.right) > 0) {
            node.right = this._rightRotate(node.right);
            return this._leftRotation(node);
        }

        return node;
    }

    /**
     * Find the node with the minimum value in a subtree.
     * Used in deletion to replace a node with two children.
     * @param {Node} node - The root of the subtree.
     * @returns {Node} The node with the minimum value.
     */
    _minValueNode(node) {
        let current = node;
        while (current.left) {
            current = current.left;
        }
        return current;
    }

    /**
     * Perform an in-order traversal of the AVL tree and print each value.
     * Uses an iterative approach with a stack to avoid recursion.
     */
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
        console.log(); // Print newline after traversal
    }
}

module.exports = AVLTree;
