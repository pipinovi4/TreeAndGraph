from Nodes.node import Node

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        """Inserts a new node with the specified data into the BST."""
        if self.root is None:
            self.root = Node(data)  # Create the root node if the tree is empty
        else:
            self._insert_recursive(self.root, data)  # Call the recursive helper function

    def _insert_recursive(self, node, data):
        """Helper function for recursive insertion."""
        if data < node.data:  # If data is less than current node's data
            if node.left is None:  # If there is no left child
                node.left = Node(data)  # Create a new left child node
            else:
                self._insert_recursive(node.left, data)  # Recur on the left child
        elif data > node.data:  # If data is greater than current node's data
            if node.right is None:  # If there is no right child
                node.right = Node(data)  # Create a new right child node
            else:
                self._insert_recursive(node.right, data)  # Recur on the right child

    def search(self, target):
        """Searches for a node with the specified target value."""
        return self._search_recursive(self.root, target)  # Start the search from the root

    def _search_recursive(self, node, target):
        """Helper function for recursive search."""
        if node is None:  # If the current node is None, target not found
            return False
        if node.data == target:  # If the current node's data matches the target
            return True
        elif target < node.data:  # If target is less than current node's data
            return self._search_recursive(node.left, target)  # Search left
        else:  # If target is greater than current node's data
            return self._search_recursive(node.right, target)  # Search right

    def delete(self, data):
        """Deletes a node with the specified data from the BST."""
        self.root = self._delete_recursive(self.root, data)  # Update root after deletion

    def _delete_recursive(self, node, data):
        """Helper function for recursive deletion."""
        if node is None:  # Base case: if the node is None, nothing to delete
            return node

        if data < node.data:  # If data is less than current node's data, go left
            node.left = self._delete_recursive(node.left, data)  # Recur on left subtree
        elif data > node.data:  # If data is greater than current node's data, go right
            node.right = self._delete_recursive(node.right, data)  # Recur on right subtree
        else:  # Found the node to delete
            if node.left is None:  # Node with only right child or no child
                return node.right
            elif node.right is None:  # Node with only left child
                return node.left

            # Node with two children: get the inorder successor (smallest in the right subtree)
            min_larger_node = self._min_value_node(node.right)
            node.data = min_larger_node.data  # Replace data with the successor's data
            node.right = self._delete_recursive(node.right, min_larger_node.data)  # Delete the inorder successor

        return node  # Return the (potentially unchanged) node pointer

    @staticmethod
    def _min_value_node(node):
        """Returns the node with the smallest value greater than the current node."""
        current = node
        while current.left is not None:  # Go to the leftmost node
            current = current.left

        return current  # Return the node with the smallest value

    @staticmethod
    def print_tree(node):
        """Print the tree using pre-order traversal."""
        if node is not None:  # Check if the current node is not None
            print(node.data, end=' ')  # Print the value of the current node
            BinarySearchTree.print_tree(node.left)  # Recursively print the left subtree
            BinarySearchTree.print_tree(node.right)  # Recursively print the right subtree
