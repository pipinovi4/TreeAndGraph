# Class Node for storing a value and references to left and right child nodes in a binary tree
class Node:
    def __init__(self, data):
        """
        Initializes a Node with a given data value.

        Parameters:
            data (int): The value to store in this node.

        Attributes:
            data (int): The data value of the node.
            left (Node): A reference to the left child node (initially None).
            right (Node): A reference to the right child node (initially None).
        """
        self.data = data         # Set the node's data to the provided value
        self.left = None         # Initialize the left child as None (no child yet)
        self.right = None        # Initialize the right child as None (no child yet)
