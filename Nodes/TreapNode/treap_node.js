/**
 * Generates a random integer between two inclusive bounds.
 *
 * @param {number} min - The minimum value (inclusive).
 * @param {number} max - The maximum value (inclusive).
 * @returns {number} A random integer between min and max (inclusive).
 */
function getRandomInt(min, max) {
    min = Math.ceil(min);  // Round up min to the nearest integer
    max = Math.floor(max); // Round down max to the nearest integer
    return Math.floor(Math.random() * (max - min + 1)) + min; // Random integer
}

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
        this.priority = priority ? priority : getRandomInt(1, 100); // Assign random priority if not provided
        this.left = null;  // Pointer to the left child
        this.right = null; // Pointer to the right child
    }
}
