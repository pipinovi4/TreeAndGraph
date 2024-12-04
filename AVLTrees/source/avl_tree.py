from Nodes.defaultNodes.node import Node


class AVLTree:
    """A class representing an AVL Tree, a self-balancing binary search tree.

    The AVL Tree ensures that the height difference between left and right subtrees
    for each node is no more than one, keeping operations efficient with a time complexity
    of O(log n) for insertion, deletion, and search.
    """

    def __init__(self):
        """Initialize the AVL tree with an empty root."""
        self.root = None

    # Utility function to get the height of the tree
    @staticmethod
    def _height(node):
        """Get the height of a node.

        Args:
            node (Node): The node whose height is to be retrieved.

        Returns:
            int: The height of the node; returns 0 if node is None.
        """
        if not node:
            return 0  # Height of a non-existent node is 0
        return node.height

    def _update_height(self, node):
        """Update the height of a node based on the height of its children.

        Args:
            node (Node): The node whose height is to be updated.
        """
        # Height is 1 plus the height of the taller child
        node.height = 1 + max(self._height(node.left), self._height(node.right))

    def _get_balance(self, node):
        """Get the balance factor of a node.

        Args:
            node (Node): The node for which the balance factor is computed.

        Returns:
            int: The balance factor (difference in height between left and right subtrees).
        """
        if not node:
            return 0  # A non-existent node is perfectly balanced
        return self._height(node.left) - self._height(node.right)  # Positive for left-heavy, negative for right-heavy

    def _right_rotate(self, y):
        """Perform a right rotation on the subtree rooted at y.

        Args:
            y (Node): The root of the subtree to rotate.

        Returns:
            Node: The new root after rotation.
        """
        x = y.left  # Set x to be the left child of y
        t2 = x.right  # Save the right subtree of x

        # Perform rotation
        x.right = y  # Make y the right child of x
        y.left = t2  # Attach the saved subtree as the left child of y

        # Update heights after rotation
        self._update_height(y)
        self._update_height(x)

        # Return new root of this subtree
        return x

    def _left_rotation(self, x):
        """Perform a left rotation on the subtree rooted at x.

        Args:
            x (Node): The root of the subtree to rotate.

        Returns:
            Node: The new root after rotation.
        """
        y = x.right  # Set y to be the right child of x
        t2 = y.left  # Save the left subtree of y

        # Perform rotation
        y.left = x  # Make x the left child of y
        x.right = t2  # Attach the saved subtree as the right child of x

        # Update heights after rotation
        self._update_height(x)
        self._update_height(y)

        # Return new root of this subtree
        return y

    def insert(self, data):
        """Insert a new value into the AVL tree and maintain balance.

        Args:
            data (int): The value to insert.
        """
        self.root = self._insert(self.root, data)

    def _insert(self, node, data):
        """Recursive helper function to insert a new value in the AVL tree.

        Args:
            node (Node): The current root of the subtree.
            data (int): The value to insert.

        Returns:
            Node: The new root of the subtree after insertion and rebalancing.
        """
        if not node:
            return Node(data)  # Insert the new node here if the subtree is empty

        # Insert data into the left or right subtree based on value
        if data < node.data:
            node.left = self._insert(node.left, data)
        elif data > node.data:
            node.right = self._insert(node.right, data)
        else:
            return node  # Duplicate values are not allowed, return the unchanged node

        # Update height and check balance factor
        self._update_height(node)
        balance = self._get_balance(node)

        # Perform rotations if the node becomes unbalanced
        # Left Left Case (left-heavy and the new data is in the left subtree)
        if balance > 1 and data < node.left.data:
            return self._right_rotate(node)

        # Right Right Case (right-heavy and the new data is in the right subtree)
        if balance < -1 and data > node.right.data:
            return self._left_rotation(node)

        # Left Right Case (left-heavy, but the new data is in the right subtree of the left child)
        if balance > 1 and data > node.left.data:
            node.left = self._left_rotation(node.left)  # Perform left rotation on left child
            return self._right_rotate(node)  # Then perform right rotation on node

        # Right Left Case (right-heavy, but the new data is in the left subtree of the right child)
        if balance < -1 and data < node.right.data:
            node.right = self._right_rotate(node.right)  # Perform right rotation on right child
            return self._left_rotation(node)  # Then perform left rotation on node

        return node  # Return the unchanged node if it's balanced

    def search(self, target):
        """Search for a value in the AVL tree.

        Args:
            target (int): The value to search for.

        Returns:
            bool: True if the value is found, False otherwise.
        """
        return self._search(self.root, target)

    def _search(self, node, target):
        """Recursive helper function to search for a value in the AVL tree.

        Args:
            node (Node): The current root of the subtree.
            target (int): The value to search for.

        Returns:
            bool: True if the value is found, False otherwise.
        """
        if node is None:
            return False  # Value not found
        if target == node.data:
            return True  # Value found
        elif target < node.data:
            return self._search(node.left, target)  # Search in the left subtree
        else:
            return self._search(node.right, target)  # Search in the right subtree

    def delete(self, data):
        """Delete a value from the AVL tree and maintain balance.

        Args:
            data (int): The value to delete.
        """
        self.root = self._delete(self.root, data)

    def _delete(self, node, data):
        """Recursive helper function to delete a value from the AVL tree.

        Args:
            node (Node): The current root of the subtree.
            data (int): The value to delete.

        Returns:
            Node: The new root of the subtree after deletion and rebalancing.
        """
        if not node:
            return node  # Node not found, nothing to delete

        # Traverse to the node to be deleted
        if data < node.data:
            node.left = self._delete(node.left, data)
        elif data > node.data:
            node.right = self._delete(node.right, data)
        else:
            # Node with only one child or no child
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left

            # Node with two children, replace with inorder successor
            temp = self._min_value_node(node.right)
            node.data = temp.data
            node.right = self._delete(node.right, temp.data)

        # Update height and check balance factor after deletion
        self._update_height(node)
        balance = self._get_balance(node)

        # Perform rotations if the node becomes unbalanced
        if balance > 1 and self._get_balance(node.left) >= 0:
            return self._right_rotate(node)
        if balance < -1 and self._get_balance(node.right) <= 0:
            return self._left_rotation(node)
        if balance > 1 and self._get_balance(node.left) < 0:
            node.left = self._left_rotation(node.left)
            return self._right_rotate(node)
        if balance < -1 and self._get_balance(node.right) > 0:
            node.right = self._right_rotate(node.right)
            return self._left_rotation(node)

        return node

    @staticmethod
    def _min_value_node(node):
        """Find the node with the smallest value in a subtree.

        Args:
            node (Node): The root of the subtree.

        Returns:
            Node: The node with the smallest value.
        """
        current = node
        while current.left:
            current = current.left  # Move to the leftmost leaf
        return current

    def print_in_order(self):
        """Perform an in-order traversal of the AVL tree and print each value."""
        stack = []
        current = self.root

        while stack or current:
            # Traverse to the leftmost node
            while current:
                stack.append(current)
                current = current.left

            # Process the node
            current = stack.pop()
            print(current.data, end=" ")

            # Traverse the right subtree
            current = current.right
