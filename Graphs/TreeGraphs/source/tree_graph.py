from collections import deque


class TreeNode:
    """
    A class representing a node in a tree.

    Attributes:
        value (any): The value stored in the node.
        children (list): A list of children TreeNode instances.

    Methods:
        add_child(node): Adds a child node to the current node.
        __repr__(): Returns a string representation of the TreeNode instance.
    """
    def __init__(self, value):
        """
        Initializes a TreeNode with the given value and an empty list of children.

        Args:
            value (any): The value to store in the node.
        """
        self.value = value
        self.children = []

    def add_child(self, node):
        """
        Adds a child node to the current node.

        Args:
            node (TreeNode): The child node to add.
        """
        self.children.append(node)

    def __repr__(self):
        """
        Returns a string representation of the TreeNode instance.

        Returns:
            str: A string representing the TreeNode.
        """
        return f"TreeNode({self.value})"


class TreeGraph:
    """
    A class representing a tree graph.

    Attributes:
        root (TreeNode): The root node of the tree.

    Methods:
        add_node(parent_value, child_value): Adds a child node to the tree.
        _find_node(current_node, value): Helper method to find a node by its value.
        traversal_in_order(node=None): Performs an in-order traversal of the tree.
        traversal_pre_order(node=None): Performs a pre-order traversal of the tree.
        traverse_post_order(node=None): Performs a post-order traversal of the tree.
        display(node=None, level=0): Displays the tree structure in a hierarchical format.
    """

    def __init__(self, root_value):
        """
        Initializes a TreeGraph with a root node.

        Args:
            root_value (any): The value to assign to the root node.
        """
        self.root = TreeNode(root_value)

    def add_node(self, parent_value, child_value):
        """
        Adds a child node to a parent node identified by parent_value.

        If the parent node is found, a new child node is created and added to it.
        If the parent node is not found, an error message is printed.

        Args:
            parent_value (any): The value of the parent node.
            child_value (any): The value of the child node to be added.
        """
        parent_node = self._find_node(self.root, parent_value)
        if parent_node:
            child_node = TreeNode(child_value)
            parent_node.add_child(child_node)
        else:
            print(f"Parent node with value {parent_value} not found.")

    @staticmethod
    def _find_node(current_node, value):
        """
        Searches for a node in the tree using breadth-first search (BFS).

        Args:
            current_node (TreeNode): The node to start searching from.
            value (any): The value of the node to find.

        Returns:
            TreeNode: The node with the given value, or None if not found.
        """
        queue = deque([current_node])

        while queue:
            current_node = queue.popleft()
            if current_node.value == value:
                return current_node
            for child in current_node.children:
                queue.append(child)

        return None

    def traversal_in_order(self, node=None):
        """
        Performs an in-order traversal of the tree. This traversal visits:
        Left child -> Root -> Right child.
        The traversal uses a queue to simulate the left, root, right order.

        Args:
            node (TreeNode, optional): The starting node for traversal. Defaults to the root.
        """
        if node is None:
            node = self.root

        # Use a queue to simulate the traversal
        queue = deque()
        current_node = node

        while current_node or queue:
            # Traverse the left children (go to the farthest left node)
            while current_node:
                queue.append(current_node)
                current_node = current_node.children[0] if current_node.children else None

            # Process the node (visit it)
            current_node = queue.pop()  # Visit the node (pop the most recent node)
            print(current_node.value, end=" ")

            # Now process the right children (if any)
            if current_node.children:
                current_node = current_node.children[1] if len(current_node.children) > 1 else None
            else:
                current_node = None

    def traversal_pre_order(self, node=None):
        """
        Performs a pre-order traversal of the tree. This traversal visits:
        Root -> Left child -> Right child.

        Args:
            node (TreeNode, optional): The starting node for traversal.
        """
        if node is None:
            node = self.root

        stack = [node]  # Initialize the stack with the root node

        while stack:
            current_node = stack.pop()  # Pop the last node added to the stack

            # Process the current node
            print(current_node.value, end=" ")

            # Push children to the stack in reverse order
            # This ensures left child is processed before the right child
            for child in reversed(current_node.children):
                stack.append(child)

    def traverse_post_order(self, node=None):
        """
        Performs a post-order traversal of the tree. This traversal visits:
        Left child -> Right child -> Root.

        Args:
            node (TreeNode, optional): The starting node for traversal. Defaults to the root.
        """
        if node is None:
            node = self.root

        # Initialize a stack for post-order traversal
        stack = []
        visited = set()  # Set to keep track of visited nodes

        stack.append(node)

        while stack:
            current_node = stack[-1]  # Look at the top node
            if current_node.children and current_node not in visited:
                # If the node has children and has not been visited, push its children
                for child in current_node.children:
                    stack.append(child)
                visited.add(current_node)  # Mark the node as visited
            else:
                # If no children or already visited, pop and process the node
                print(current_node.value, end=" ")
                stack.pop()

    def display(self, node=None, level=0):
        """
        Displays the tree structure in a hierarchical format.

        Args:
            node (TreeNode, optional): The starting node for displaying the tree. Defaults to the root.
            level (int, optional): The current level of indentation. Defaults to 0.
        """
        if node is None:
            node = self.root

        # Print the current node with appropriate indentation
        print(" " * level * 4 + node.__repr__())
        # Recursively display each child node, increasing the indentation level
        for child in node.children:
            self.display(child, level + 1)
