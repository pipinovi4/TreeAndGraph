from collections import deque


class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, node):
        self.children.append(node)

    def __repr__(self):
        return f"TreeNode({self.value})"


class TreeGraph:
    def __init__(self, root_value):
        self.root = TreeNode(root_value)

    def add_node(self, parent_value, child_value):
        parent_node = self._find_node(self.root, parent_value)
        if parent_node:
            child_node = TreeNode(child_value)
            parent_node.add_child(child_node)
        else:
            print(f"Parent node with value {parent_value} not found.")

    @staticmethod
    def _find_node(current_node, value):
        queue = deque()
        queue.append(current_node)

        while queue:
            current_node = queue.popleft()
            if current_node.value == value:
                return current_node
            if current_node.children:
                for child in current_node.children:
                    queue.append(child)

        return None

    def traversal_in_order(self, node=None):
        if node is None:
            node = self.root

        # Use a queue to simulate the traversal
        queue = deque()
        current_node = node

        # Start with the leftmost child and go until no more nodes are left
        while current_node or queue:
            # Traverse the left children (go to the farthest left node)
            while current_node:
                queue.append(current_node)
                current_node = current_node.children[0] if current_node.children else None

            # Process the node
            current_node = queue.pop()  # Visit the node (pop the most recent node)
            print(current_node.value, end=" ")

            # Now process the right children (if any)
            if current_node.children:
                current_node = current_node.children[1] if len(current_node.children) > 1 else None
            else:
                current_node = None

    def traversal_pre_order(self, node=None):
        queue = deque()
        queue.append(node)

        while queue:
            current_node = queue.popleft()

            if current_node is None:
                current_node = self.root
            if current_node:
                print(current_node.value, end=" ")
                for child in current_node.children:
                    queue.append(child)

    def traverse_post_order(self, node=None):
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
        if node is None:
            node = self.root

        print(" " * level * 4 + node.__repr__())
        for child in node.children:
            self.display(child, level + 1)
