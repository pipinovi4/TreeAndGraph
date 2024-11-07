from Nodes.node import Node  # Importing the Node class to represent nodes in the tree


class PerfectBinaryTree:
    def __init__(self, depth):
        """
        Initializes a PerfectBinaryTree instance with a specified depth.

        Parameters:
            depth (int): The depth of the perfect binary tree.
                         The tree will have 2^depth - 1 nodes.
        """
        self.root = self._build_perfect_tree(1, depth)  # Create the perfect binary tree with root value 1

    def _build_perfect_tree(self, data, depth):
        """
        Recursively builds a perfect binary tree.

        Parameters:
            data (int): The value for the current node.
            depth (int): The remaining depth of the tree to be constructed.

        Returns:
            Node: The root node of the constructed subtree.
        """
        if depth == 0:
            return None  # Base case: if depth is 0, return None (no node)

        node = Node(data)  # Create a new node with the given data

        # Recursively build the left and right subtrees
        node.left = self._build_perfect_tree(data * 2, depth - 1)  # Left child has data value double the current node
        node.right = self._build_perfect_tree(data * 2 + 1, depth - 1)  # Right child has data value double the current node plus one

        return node  # Return the newly created node

    def search(self, node, target):
        """
        Searches for a target value in the tree using pre-order traversal.

        Parameters:
            node (Node): The current node being examined.
            target (int): The value to search for in the tree.

        Returns:
            bool: True if the target is found, False otherwise.
        """
        if node is None:
            return False  # If the current node is None, the target is not found

        if node.data == target:
            return True  # If the current node's data matches the target, return True

        # Recursively search in the left and right subtrees
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
