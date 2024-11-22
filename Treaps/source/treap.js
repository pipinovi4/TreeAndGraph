const TreapNode = require("../../Nodes/TreapNode/treap_node.js");

/**
 * Treap class: A randomized binary search tree that maintains both BST (key ordering)
 * and max-heap (priority ordering) properties.
 */
class Treap {
    constructor() {
        /**
         * Initialize the Treap with no root.
         */
        this.root = null;
    }

    /**
     * Perform a right rotation to maintain the heap property.
     *
     * @param {TreapNode} node - The node to rotate.
     * @returns {TreapNode} The new root of the rotated subtree.
     */
    static _rotateRight(node) {
        const leftChild = node.left;
        node.left = leftChild.right; // Move left child's right subtree to current node's left
        leftChild.right = node; // Make the current node the right child of its left child
        return leftChild; // Return the new root
    }

    /**
     * Perform a left rotation to maintain the heap property.
     *
     * @param {TreapNode} node - The node to rotate.
     * @returns {TreapNode} The new root of the rotated subtree.
     */
    static _rotateLeft(node) {
        const rightChild = node.right;
        node.right = rightChild.left; // Move right child's left subtree to current node's right
        rightChild.left = node; // Make the current node the left child of its right child
        return rightChild; // Return the new root
    }

    /**
     * Generate a unique priority for a node.
     *
     * @param {number|null} basePriority - Optional base priority (randomly generated if null).
     * @returns {number} A unique priority value.
     */
    static _generateUniquePriority(basePriority = null) {
        return basePriority !== null ? basePriority : Math.floor(Math.random() * 1000000) + 1;
    }

    /**
     * Insert a key into the Treap while maintaining BST and heap properties.
     *
     * @param {number} key - The key to insert.
     * @param {number|null} priority - Optional priority (randomly generated if null).
     */
    insert(key, priority = null) {
        // Generate priority if not provided
        priority = priority !== null ? priority : Treap._generateUniquePriority();

        // Create the new node to insert
        const newNode = new TreapNode(key, priority);
        if (this.root === null) {
            this.root = newNode; // If the tree is empty, the new node becomes the root
            return;
        }

        // Traverse the tree to find the correct position for the new node
        let parent = null;
        let current = this.root;
        const stack = []; // Stack to keep track of the path for rebalancing

        while (current) {
            parent = current;
            stack.push(current); // Push current node to the stack for rotation tracking
            if (key < current.key) {
                if (current.left === null) {
                    current.left = newNode; // Insert as left child if empty
                    break;
                }
                current = current.left; // Traverse left subtree
            } else if (key > current.key) {
                if (current.right === null) {
                    current.right = newNode; // Insert as right child if empty
                    break;
                }
                current = current.right; // Traverse right subtree
            } else {
                // Key already exists; no insertion needed
                return;
            }
        }

        // Rebalance the tree to maintain the heap property
        current = newNode; // Start from the inserted node
        while (stack.length > 0) {
            parent = stack.pop(); // Get the parent node from the stack
            if (parent.priority < current.priority) {
                // Heap violation detected
                let rotated;
                if (parent.left === current) {
                    rotated = Treap._rotateRight(parent); // Perform right rotation
                } else {
                    rotated = Treap._rotateLeft(parent); // Perform left rotation
                }

                // Update the parent's reference in the grandparent
                if (stack.length > 0) {
                    const grandparent = stack[stack.length - 1];
                    if (grandparent.left === parent) {
                        grandparent.left = rotated;
                    } else {
                        grandparent.right = rotated;
                    }
                } else {
                    this.root = rotated; // Update the root if no grandparent exists
                }
            } else {
                break; // Stop rebalancing if heap property is satisfied
            }
        }
    }

    /**
     * Delete a key from the Treap while maintaining BST and heap properties.
     *
     * @param {number} key - The key to delete.
     */
    delete(key) {
        let parent = null;
        let current = this.root;

        // Locate the node to delete
        while (current && current.key !== key) {
            parent = current;
            if (key < current.key) {
                current = current.left; // Traverse left subtree
            } else {
                current = current.right; // Traverse right subtree
            }
        }

        if (current === null) {
            // Key not found; nothing to delete
            return;
        }

        // Rotate the node until it has at most one child
        while (current.left && current.right) {
            let rotated;
            if (current.left.priority > current.right.priority) {
                rotated = Treap._rotateRight(current); // Rotate right
            } else {
                rotated = Treap._rotateLeft(current); // Rotate left
            }

            // Update the parent's reference after rotation
            if (parent === null) {
                this.root = rotated;
            } else if (parent.left === current) {
                parent.left = rotated;
            } else {
                parent.right = rotated;
            }
            parent = rotated;
        }

        // Remove the node (it has at most one child at this point)
        if (parent === null) {
            this.root = current.left || current.right;
        } else if (parent.left === current) {
            parent.left = current.left || current.right;
        } else {
            parent.right = current.left || current.right;
        }
    }

    /**
     * Search for a key in the Treap.
     *
     * @param {number} key - The key to search for.
     * @returns {boolean} True if the key exists, False otherwise.
     */
    search(key) {
        let current = this.root;
        while (current) {
            if (key === current.key) {
                return true; // Key found
            } else if (key < current.key) {
                current = current.left; // Traverse left subtree
            } else {
                current = current.right; // Traverse right subtree
            }
        }
        return false; // Key not found
    }

    /**
     * Perform an in-order traversal of the Treap to retrieve keys in sorted order.
     *
     * @param {TreapNode|null} node - The current node to traverse (default is the root).
     * @param {Array} result - Array to collect traversal results.
     * @returns {Array} List of objects with keys and priorities in sorted order.
     */
    inorder(node = this.root, result = []) {
        if (node !== null) {
            this.inorder(node.left, result); // Traverse left subtree
            result.push({ key: node.key, priority: node.priority }); // Process current node
            this.inorder(node.right, result); // Traverse right subtree
        }
        return result;
    }

    /**
     * Print the structure of the Treap for debugging purposes.
     *
     * @param {TreapNode|null} node - The current node to print (default is the root).
     * @param {number} level - The current level in the tree.
     * @param {string} prefix - Prefix string to indicate the node's position.
     */
    printTree(node = this.root, level = 0, prefix = "Root: ") {
        if (node === null) return;
        if (node.right !== null) {
            this.printTree(node.right, level + 1, "R--- ");
        }
        console.log("    ".repeat(level) + `${prefix}(${node.key}, ${node.priority})`);
        if (node.left !== null) {
            this.printTree(node.left, level + 1, "L--- ");
        }
    }
}

module.exports = Treap;
