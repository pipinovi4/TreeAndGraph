from Nodes.node import Node  # Import the Node class to represent each node in the tree

class CompleteBinaryTree:
    def __init__(self):
        """Initializes a CompleteBinaryTree instance.

        The tree is represented using a list to store nodes in level order.
        """
        self.nodes = []  # Using a list to store nodes in level order

    def insert(self, data):
        """Inserts a new node into the Complete Binary Tree while maintaining the complete tree property.

        Nodes are added from left to right.

        Args:
            data (any): The value to be stored in the new node.
        """
        new_node = Node(data)  # Create a new Node instance with the provided data
        self.nodes.append(new_node)  # Add the new node to the list

        # If not the root, determine the parent and add the new node as a child
        idx = len(self.nodes) - 1  # Get the index of the newly added node
        if idx > 0:  # Check if the node is not the root
            parent_idx = (idx - 1) // 2  # Calculate the parent index
            # Assign the new node as the left or right child of its parent
            if not self.nodes[parent_idx].left:  # If the left child is not assigned
                self.nodes[parent_idx].left = new_node  # Assign as left child
            else:
                self.nodes[parent_idx].right = new_node  # Otherwise, assign as right child

    def search(self, target):
        """Searches for a target value in the Complete Binary Tree.

        Args:
            target (any): The value to search for in the tree.

        Returns:
            bool: True if the target is found; otherwise, False.
        """
        for node in self.nodes:  # Iterate through the list of nodes
            if node.data == target:  # Compare the current node's data with the target
                return True  # Return True if found
        return False  # Return False if the target is not found

    def print_tree(self):
        """Prints the values of the Complete Binary Tree in level order."""
        for node in self.nodes:  # Iterate through the list of nodes
            print(node.data, end=" ")  # Print each node's data in a single line
