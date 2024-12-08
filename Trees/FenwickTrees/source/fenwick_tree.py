class FenwickTree:
    """
    Fenwick Tree (Binary Indexed Tree) implementation.
    """

    def __init__(self, size):
        """
        Initialize the Fenwick Tree with a given size.

        Args:
            size (int): Number of elements in the Fenwick Tree.
        """
        self.size = size
        # The internal `tree` is initialized to zeros.
        # We use `size + 1` because the Fenwick Tree uses 1-based indexing.
        self.tree = [0] * (size + 1)

    def update(self, index, delta):
        """
        Update the Fenwick Tree by adding `delta` to the element at `index`.

        Args:
            index (int): 1-based index to update.
            delta (int): Value to add to the index.
        """
        # Loop until we exceed the size of the Fenwick Tree.
        while index <= self.size:
            # Add `delta` to the current index of the tree.
            self.tree[index] += delta
            # Move to the next index affected by this update.
            # This is determined by the least significant bit (LSB).
            index += index & -index  # Add the LSB to move up.

    def query(self, index):
        """
        Get the prefix sum from index 1 to `index`.

        Args:
            index (int): 1-based index up to which to calculate the sum.

        Returns:
            int: The prefix sum from 1 to `index`.
        """
        sum_ = 0
        # Traverse the tree by moving "up" using the LSB.
        while index > 0:
            # Add the value stored at the current index.
            sum_ += self.tree[index]
            # Move to the parent index by subtracting the LSB.
            index -= index & -index
        return sum_

    def range_query(self, left, right):
        """
        Get the sum of elements in the range [left, right].

        Args:
            left (int): Starting 1-based index of the range.
            right (int): Ending 1-based index of the range.

        Returns:
            int: The sum of elements in the range.
        """
        # To get the sum of [left, right], subtract the sum of [1, left-1]
        # from the sum of [1, right].
        return self.query(right) - self.query(left - 1)

    @classmethod
    def build(cls, data):
        """
        Build a Fenwick Tree from a list of data.

        Args:
            data (list[int]): List of integers to initialize the tree.

        Returns:
            FenwickTree: A Fenwick Tree built from the input data.
        """
        # Get the size of the data.
        n = len(data)
        # Initialize a Fenwick Tree with the same size as the data.
        fenwick = cls(n)
        # Populate the Fenwick Tree by updating each index with the data's values.
        for i, value in enumerate(data, start=1):  # Use 1-based indexing.
            fenwick.update(i, value)
        return fenwick
