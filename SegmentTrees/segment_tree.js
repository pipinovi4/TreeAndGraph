/**
 * SegmentTree class for efficient range queries and updates.
 *
 * @param {Array} data - Input array to build the segment tree.
 * @param {Function} func - Associative function (e.g., Math.min, Math.max, sum).
 * @param {*} identity - Identity value for the associative function.
 *                       For Math.min: Infinity, Math.max: -Infinity, sum: 0.
 */
class SegmentTree {
    constructor(data, func = Math.min, identity = null) {
        this.n = data.length; // Length of the input array
        this.func = func; // Associative function (e.g., min, max, sum)

        // Determine the identity value based on the function or use a custom one
        this.identity = identity !== undefined && identity !== null ? identity :
            (func === Math.min ? Infinity :
                func === Math.max ? -Infinity :
                    func === ((a, b) => a + b) ? 0 : null);

        // Throw an error if no valid identity value is provided for custom functions
        if (this.identity === null) {
            throw new Error("Invalid arguments: identity is required for custom functions or unrecognized func.");
        }

        // Create a flat array to represent the segment tree with a size of 2 * n
        this.tree = new Array(this.n * 2);
        this.tree.fill(this.identity); // Initialize with the identity value

        // Build the segment tree from the input data
        this._build(data);
    }

    /**
     * Internal method to build the segment tree from the input array.
     *
     * @param {Array} data - The input array.
     */
    _build(data) {
        // Initialize the leaves (second half of the tree array)
        for (let i = 0; i < this.n; i++) {
            this.tree[this.n + i] = data[i]; // Store data elements as leaves
        }

        // Compute internal nodes (bottom-up approach)
        for (let i = this.n - 1; i > 0; i--) {
            this.tree[i] = this.func(this.tree[2 * i], this.tree[2 * i + 1]); // Combine child nodes
        }
    }

    /**
     * Update the value at a specific index in the original array.
     *
     * @param {number} index - The index in the original array (0-based).
     * @param {*} value - The new value to set.
     */
    update(index, value) {
        // Ensure the index is within valid bounds
        if (index < 0 || index >= this.n) {
            throw new Error("Index out of bounds");
        }

        // Update the corresponding leaf node
        index += this.n; // Map the original index to its corresponding leaf node
        this.tree[index] = value;

        // Propagate changes up the tree to update internal nodes
        while (index > 1) {
            index = Math.floor(index / 2); // Move to the parent node
            this.tree[index] = this.func(this.tree[2 * index], this.tree[2 * index + 1]); // Update the parent
        }
    }

    /**
     * Query the result of the function over a range [left, right).
     *
     * @param {number} left - Start of the range (inclusive, 0-based).
     * @param {number} right - End of the range (exclusive, 0-based).
     * @return {*} - The result of the associative function over the range.
     */
    query(left, right) {
        // Ensure the range is valid
        if (left < 0 || right > this.n || left >= right) {
            throw new Error("IndexError: Invalid query range.");
        }

        // Map the range to corresponding leaf nodes
        left += this.n;
        right += this.n;

        let result = this.identity; // Start with the identity value

        // Traverse and combine results for overlapping segments
        while (left < right) {
            if (left % 2 === 1) { // If left is a right child
                result = this.func(result, this.tree[left]); // Include this segment
                left++; // Move to the next segment
            }
            if (right % 2 === 1) { // If right is a right child
                right--; // Move to the previous segment
                result = this.func(result, this.tree[right]); // Include this segment
            }

            // Move to the parent level
            left = Math.floor(left / 2);
            right = Math.floor(right / 2);
        }

        return result; // Return the combined result
    }
}

// Export the SegmentTree class for use in other files
module.exports = SegmentTree;
