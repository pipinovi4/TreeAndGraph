class SegmentTree:
    def __init__(self, data, func=min, identity=None):
        """
        Initialize the Segment Tree.

        :param data: The input array for which the segment tree is constructed.
        :param func: The function to apply to a range (e.g., min, max, sum). Must be associative.
        :param identity: The identity value for the given function. If not provided, it will be inferred for common functions.

        The segment tree will store results of `func` for overlapping ranges, allowing fast queries and updates.
        """
        self.n = len(data)  # Number of elements in the original array
        self.func = func    # Function to apply on segments

        # Determine the identity value (default neutral value for the given function)
        self.identity = identity if identity is not None else (
            float('inf') if func == min else
            float('-inf') if func == max else
            0 if func == sum else
            None
        )
        if self.identity is None:
            raise ValueError("Identity value required for custom functions")

        # The segment tree is represented as a flat array of size 2 * n
        self.tree = [self.identity] * (2 * self.n)

        # Build the segment tree from the input data
        self._build(data)

        print(self.tree)

    def _build(self, data):
        """
        Build the Segment Tree from the input data.
        The input data is stored as leaves in the tree, and internal nodes are computed based on `func`.
        """
        # Initialize the leaves (second half of the tree array)
        for i in range(self.n):
            self.tree[self.n + i] = data[i]

        # Compute internal nodes (bottom-up approach)
        for i in range(self.n - 1, 0, -1):  # Start from last internal node
            self.tree[i] = self.func(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, index, value):
        """
        Update the value at a specific index in the original array.
        Updates the leaf node and propagates changes to internal nodes.

        :param index: The index in the original array (0-based).
        :param value: The new value to set.
        """
        if not (0 <= index < self.n):
            raise IndexError("Index out of bounds")

        # Update the leaf node
        index += self.n  # Map the original index to its corresponding leaf node in the tree
        self.tree[index] = value

        # Update all affected internal nodes
        while index > 1:
            index //= 2  # Move to the parent node
            self.tree[index] = self.func(self.tree[2 * index], self.tree[2 * index + 1])

    def query(self, left, right):
        """
        Query the result of the function in the range [left, right).

        :param left: The starting index of the range (inclusive, 0-based).
        :param right: The ending index of the range (exclusive, 0-based).
        :return: The result of applying the function to the range.

        The function traverses only the segments that overlap with the given range.
        """
        if not (0 <= left < right <= self.n):
            raise IndexError("Invalid query range")

        # Map range to corresponding leaf nodes in the segment tree
        left += self.n
        right += self.n

        result = self.identity  # Start with the identity value

        # Traverse segments and combine results
        while left < right:
            if left % 2 == 1:  # If left is a right child
                result = self.func(result, self.tree[left])
                left += 1  # Move to the next segment
            if right % 2 == 1:  # If right is a right child
                right -= 1  # Move to the parent node range
                result = self.func(result, self.tree[right])

            # Move to the next level of internal nodes
            left //= 2
            right //= 2

        return result
