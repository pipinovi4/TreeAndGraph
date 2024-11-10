from Nodes.defaultNodes.node import Node  # Import Node class for representing nodes in the tree


class FullBinaryTree:
    """Class representing a Full Binary Tree where each node has either 0 or exactly 2 children."""

    def __init__(self):
        # Initialize the root node with data 1
        self.root = Node(1)

    @staticmethod
    def add_children(parent, left_data=None, right_data=None):
        """
        Adds two children to the specified parent node if it has no children,
        enforcing the full binary tree property (each node has either 0 or 2 children).

        Parameters:
            parent (Node): The parent node to which children will be added.
            left_data (int): The data for the left child node.
            right_data (int): The data for the right child node.

        Raises:
            ValueError: If the parent already has children or only one child data is provided.
        """
        if not parent.left and not parent.right:  # Check if parent has no children
            if left_data is not None and right_data is not None:
                # Create and assign left and right children
                parent.left = Node(left_data)
                parent.right = Node(right_data)
            else:
                # Raise error if both left and right data are not provided
                raise ValueError("A full binary tree requires either 0 or 2 children.")
        else:
            # Raise error if parent already has children
            raise ValueError("Parent already has children.")

    def search(self, node, target):
        """
        Searches for a target value in the tree using pre-order traversal.

        Parameters:
            node (Node): The starting node for the search (usually the root).
            target (int): The value being searched for in the tree.

        Returns:
            bool: True if the target value is found, False otherwise.
        """
        if node is None:
            return False  # Return False if node is null
        if node.data == target:
            return True  # Return True if the target value is found
        # Recursively search left and right subtrees
        return self.search(node.left, target) or self.search(node.right, target)

    def print_tree(self, node):
        """
        Performs pre-order traversal of the tree and prints each node's value in a single line.

        Parameters:
            node (Node): The starting node for the traversal (usually the root).
        """
        if node is not None:
            print(node.data, end=' ')  # Print current node's data
            self.print_tree(node.left)  # Recursively print left subtree
            self.print_tree(node.right)  # Recursively print right subtree
