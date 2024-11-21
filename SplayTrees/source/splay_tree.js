const Node = require("../../Nodes/defaultNodes/node");

/**
 * SplayTree implementation
 *
 * A splay tree is a self-adjusting binary search tree with the additional property that recently accessed elements
 * are quick to access again. After every access (search, insertion, or deletion), the tree rearranges itself
 * using rotations so that the accessed node becomes the root of the tree. This ensures that frequently accessed
 * elements stay near the root for efficient future accesses.
 *
 * This class implements:
 * 1. `search(data)` - Searches for a node with the given data and performs splaying to bring it to the root.
 * 2. `insert(data)` - Inserts a new node and rearranges the tree via splaying.
 * 3. `delete(data)` - Deletes a node and rearranges the tree.
 * 4. `inorder()` - Traverses the tree in order (left, root, right) and returns the sorted data.
 *
 * The splay operation reconfigures the tree using rotations:
 * 1. Zig-zig: A double rotation in the same direction.
 * 2. Zig-zag: A double rotation in opposite directions.
 * 3. Zig: A single rotation when the node is a direct child of the root.
 */
class SplayTree {
    constructor() {
        // Initializes an empty splay tree with a root node set to null.
        this.root = null;
    }

    /**
     * Search for a node in the tree and splay it to the root.
     *
     * @param {number} data - The value to search for.
     * @returns {boolean} - Returns true if the node is found, otherwise false.
     */
    search(data) {
        // Splay the tree so that the searched node (if exists) is brought to the root.
        this.root = this._splay(this.root, data);
        // Return true if the root matches the data after splaying.
        return this.root && this.root.data === data;
    }

    /**
     * Insert a new node into the splay tree.
     *
     * @param {number} data - The value to insert.
     */
    insert(data) {
        if (!this.root) {
            // If the tree is empty, create a new node and set it as the root.
            this.root = new Node(data);
            return;
        }

        // Splay the tree with the given data, so the closest match becomes the root.
        this.root = this._splay(this.root, data);

        // If the data already exists in the root, return without inserting.
        if (this.root.data === data) {
            return;
        }

        // Create a new node to insert.
        const newNode = new Node(data);

        if (data < this.root.data) {
            // If the data is smaller than the root, set the new node's right child to the root.
            newNode.right = this.root;
            newNode.left = this.root.left;
            this.root.left = null;
        } else {
            // If the data is greater, set the new node's left child to the root.
            newNode.left = this.root;
            newNode.right = this.root.right;
            this.root.right = null;
        }

        // Make the new node the root of the tree.
        this.root = newNode;
    }

    /**
     * Delete a node from the splay tree.
     *
     * @param {number} data - The value to delete.
     */
    delete(data) {
        if (!this.root) return; // Tree is empty, nothing to delete.

        // Splay the tree with the given data, so the closest match becomes the root.
        this.root = this._splay(this.root, data);

        // If the root does not match the data, the node does not exist.
        if (this.root.data !== data) return;

        if (!this.root.left) {
            // If there is no left subtree, make the right subtree the new root.
            this.root = this.root.right;
        } else if (!this.root.right) {
            // If there is no right subtree, make the left subtree the new root.
            this.root = this.root.left;
        } else {
            // If both subtrees exist:
            // 1. Splay the left subtree so the largest node becomes the root.
            const leftSubtree = this.root.left;
            const rightSubtree = this.root.right;

            this.root = this._splay(leftSubtree, data);

            // 2. Attach the right subtree as the right child of the new root.
            this.root.right = rightSubtree;
        }
    }

    /**
     * Perform an inorder traversal of the tree.
     *
     * @param {Node} node - The current node (default is the root).
     * @param {Array} result - The result array to store traversal data.
     * @returns {Array} - The array containing the tree's data in sorted order.
     */
    inorder(node = null, result = null) {
        if (!result) result = []; // Initialize the result array.
        if (!node) node = this.root; // Start traversal from the root.

        if (node) {
            if (node.left) this.inorder(node.left, result); // Traverse left subtree.
            result.push(node.data); // Add root data.
            if (node.right) this.inorder(node.right, result); // Traverse right subtree.
        }

        return result;
    }

    /**
     * Splay operation to bring the node with the given data to the root.
     *
     * @param {Node} node - The current root of the tree.
     * @param {number} data - The value to splay.
     * @returns {Node} - The new root after splaying.
     */
    _splay(node, data) {
        if (!node || node.data === data) {
            return node; // Base case: if the node is null or matches the data.
        }

        if (data < node.data) {
            // Data lies in the left subtree.
            if (!node.left) return node;

            if (data < node.left.data) {
                // Zig-zig (Left-Left): Splay the left-left child and rotate right.
                node.left.left = this._splay(node.left.left, data);
                node = SplayTree._rightRotate(node);
            } else if (data > node.left.data) {
                // Zig-zag (Left-Right): Splay the left-right child and rotate left-right.
                node.left.right = this._splay(node.left.right, data);
                if (node.left.right) {
                    node.left = SplayTree._leftRotate(node.left);
                }
            }

            return node.left ? SplayTree._rightRotate(node) : node;
        } else {
            // Data lies in the right subtree.
            if (!node.right) return node;

            if (data > node.right.data) {
                // Zig-zig (Right-Right): Splay the right-right child and rotate left.
                node.right.right = this._splay(node.right.right, data);
                node = SplayTree._leftRotate(node);
            } else if (data < node.right.data) {
                // Zig-zag (Right-Left): Splay the right-left child and rotate right-left.
                node.right.left = this._splay(node.right.left, data);
                if (node.right.left) {
                    node.right = SplayTree._rightRotate(node.right);
                }
            }

            return node.right ? SplayTree._leftRotate(node) : node;
        }
    }

    /**
     * Perform a right rotation.
     *
     * @param {Node} node - The current root.
     * @returns {Node} - The new root after rotation.
     */
    static _rightRotate(node) {
        const newRoot = node.left;
        node.left = newRoot.right;
        newRoot.right = node;
        return newRoot;
    }

    /**
     * Perform a left rotation.
     *
     * @param {Node} node - The current root.
     * @returns {Node} - The new root after rotation.
     */
    static _leftRotate(node) {
        const newRoot = node.right;
        node.right = newRoot.left;
        newRoot.left = node;
        return newRoot;
    }
}

module.exports = SplayTree;
