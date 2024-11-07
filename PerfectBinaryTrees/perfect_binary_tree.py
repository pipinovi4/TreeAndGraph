from Nodes.node import Node


class PerfectBinaryTree:
    def __init__(self, depth):
        self.root = self._build_perfect_tree(1, depth)

    def _build_perfect_tree(self, data, depth):
        if depth == 0:
            return None
        node = Node(data)
        node.left = self._build_perfect_tree(data * 2, depth - 1)
        node.right = self._build_perfect_tree(data * 2 + 1, depth - 1)
        return node

    def search(self, node, target):
        """Searches for a target value in the tree using pre-order traversal."""
        if node is None:
            return False
        if node.data == target:
            return True
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

