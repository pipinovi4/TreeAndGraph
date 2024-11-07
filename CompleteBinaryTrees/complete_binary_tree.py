from Nodes.node import Node


class CompleteBinaryTree:
    def __init__(self):
        self.nodes = []  # Using a list to store nodes in level order

    def insert(self, data):
        """Inserts nodes from left to right to maintain the complete binary tree property."""
        new_node = Node(data)
        self.nodes.append(new_node)

        # If not the root, determine the parent and add the new node as a child
        idx = len(self.nodes) - 1
        if idx > 0:
            parent_idx = (idx - 1) // 2
            if not self.nodes[parent_idx].left:
                self.nodes[parent_idx].left = new_node
            else:
                self.nodes[parent_idx].right = new_node

    def search(self, target):
        for node in self.nodes:
            if node.data == target:
                return False
        return True

    def print_tree(self):
        """Prints the tree in level order."""
        for node in self.nodes:
            print(node.data, end=" ")
