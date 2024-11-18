class FenwickTree {
    /**
     * Initialize the Fenwick Tree with a given size.
     *
     * @param {number} size - Number of elements in the Fenwick Tree.
     */
    constructor(size) {
        this.size = size;
        // Internal tree initialized to zeros, using size + 1 for 1-based indexing.
        this.tree = new Array(size + 1).fill(0);
    }

    /**
     * Update the Fenwick Tree by adding `delta` to the element at `index`.
     *
     * @param {number} index - 1-based index to update.
     * @param {number} delta - Value to add to the index.
     */
    update(index, delta) {
        // Loop until the index exceeds the size of the tree.
        while (index <= this.size) {
            // Add `delta` to the current index in the tree.
            this.tree[index] += delta;
            // Move to the next index affected by this update.
            // Determined by the least significant bit (LSB).
            index += index & -index; // Add the LSB to move up.
        }
    }

    /**
     * Get the prefix sum from index 1 to `index`.
     *
     * @param {number} index - 1-based index up to which to calculate the sum.
     * @returns {number} - The prefix sum from 1 to `index`.
     */
    query(index) {
        let sum = 0;
        // Traverse the tree by moving "up" using the LSB.
        while (index > 0) {
            // Add the value stored at the current index.
            sum += this.tree[index];
            // Move to the parent index by subtracting the LSB.
            index -= index & -index;
        }
        return sum;
    }

    /**
     * Get the sum of elements in the range [left, right].
     *
     * @param {number} left - Starting 1-based index of the range.
     * @param {number} right - Ending 1-based index of the range.
     * @returns {number} - The sum of elements in the range.
     */
    rangeQuery(left, right) {
        // To get the sum of [left, right], subtract the sum of [1, left-1]
        // from the sum of [1, right].
        return this.query(right) - this.query(left - 1);
    }

    /**
     * Build a Fenwick Tree from an array of data.
     *
     * @param {number[]} data - List of integers to initialize the tree.
     * @returns {FenwickTree} - A Fenwick Tree built from the input data.
     */
    static build(data) {
        const n = data.length;
        const fenwick = new FenwickTree(n);
        // Populate the tree by updating each index with the data's values.
        data.forEach((value, i) => {
            fenwick.update(i + 1, value); // Use 1-based indexing.
        });
        return fenwick;
    }
}
