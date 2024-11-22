/**
 * Represents a node in the Treap Tree.
 *
 * A TreapNode is a combination of a binary search tree (key ordering) and a max-heap (priority ordering).
 * Each node contains a key, a randomly assigned priority (or a provided one), and pointers to left and right children.
 *
 * @class
 */
class TreapNode {
    /**
     * Creates a TreapNode instance.
     *
     * @param {number} key - The key of the node.
     * @param {number|null} [priority=null] - The priority of the node.
     *                                        If not provided, a random priority between 1 and 100 is assigned.
     */
    constructor(key, priority = null) {
        this.key = key;
        this.priority = priority !== null ? priority : Math.floor(Math.random() * 10000000) + 1;        this.left = null;  // Pointer to the left child
        this.right = null; // Pointer to the right child
    }
}

module.exports = TreapNode;