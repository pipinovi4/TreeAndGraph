from Nodes.TreapNode.treap_node import TreapNode
import random


class Treap:
    """
    A Treap is a randomized binary search tree that maintains both BST and heap properties.
    Each node has a key and a priority, where the tree remains a valid BST by key and a max-heap by priority.
    """

    priority_counter = 0  # Counter for generating unique priorities

    def __init__(self):
        """
        Initialize an empty Treap with no root.
        """
        self.root = None

    @staticmethod
    def _rotate_right(node):
        """
        Perform a right rotation on the given node.

        :param node: The node to rotate.
        :return: The new root after rotation.
        """
        left_child = node.left
        node.left = left_child.right
        left_child.right = node
        return left_child

    @staticmethod
    def _rotate_left(node):
        """
        Perform a left rotation on the given node.

        :param node: The node to rotate.
        :return: The new root after rotation.
        """
        right_child = node.right
        node.right = right_child.left
        right_child.left = node
        return right_child

    @staticmethod
    def _generate_unique_priority(base_priority=None):
        """
        Generate a unique priority to avoid collisions.

        :param base_priority: Optional base priority (default: random integer).
        :return: A unique priority value.
        """
        if base_priority is None:
            base_priority = random.randint(1, 1000000)
        unique_offset = Treap.priority_counter
        Treap.priority_counter += 1
        return base_priority + unique_offset

    def insert(self, key, priority=None):
        """
        Insert a key into the Treap while maintaining BST and heap properties.

        :param key: The key to insert.
        :param priority: (Optional) Priority for the node (randomly generated if not provided).
        """
        if priority is None:
            priority = self._generate_unique_priority()

        # Insert the node in the BST
        new_node = TreapNode(key, priority)
        if self.root is None:
            self.root = new_node
            return

        # Locate the position to insert
        parent = None
        current = self.root
        stack = []  # Stack to keep track of the path

        while current:
            parent = current
            stack.append(current)
            if key < current.key:
                if current.left is None:
                    current.left = new_node
                    break
                current = current.left
            elif key > current.key:
                if current.right is None:
                    current.right = new_node
                    break
                current = current.right
            else:
                # Key already exists, do nothing
                return

        # Rebalanced the tree to maintain the heap property
        current = new_node
        while stack:
            parent = stack.pop()
            if parent.priority < current.priority:
                if parent.left == current:
                    rotated = self._rotate_right(parent)
                else:
                    rotated = self._rotate_left(parent)

                # Update parent references
                if stack:
                    grandparent = stack[-1]
                    if grandparent.left == parent:
                        grandparent.left = rotated
                    else:
                        grandparent.right = rotated
                else:
                    self.root = rotated
            else:
                break

    def delete(self, key):
        """
        Delete a key from the Treap while maintaining BST and heap properties.

        :param key: The key to delete.
        """
        parent = None
        current = self.root

        # Locate the node to delete
        while current and current.key != key:
            parent = current
            if key < current.key:
                current = current.left
            else:
                current = current.right

        if current is None:
            # Key not found
            return

        # Rotate the node until it has at most one child
        while current.left and current.right:
            if current.left.priority > current.right.priority:
                rotated = self._rotate_right(current)
            else:
                rotated = self._rotate_left(current)

            # Update the parent's reference
            if parent is None:
                self.root = rotated
            elif parent.left == current:
                parent.left = rotated
            else:
                parent.right = rotated

            parent = rotated

        # Remove the node
        if parent is None:
            self.root = current.left or current.right
        elif parent.left == current:
            parent.left = current.left or current.right
        else:
            parent.right = current.left or current.right

    def search(self, key):
        """
        Search for a key in the Treap.

        :param key: The key to search for.
        :return: True if the key exists, False otherwise.
        """
        current = self.root
        while current:
            if key == current.key:
                return True
            elif key < current.key:
                current = current.left
            else:
                current = current.right
        return False

    def inorder(self):
        """
        Perform an in-order traversal of the Treap.

        :return: List of (key, priority) pairs in sorted key order.
        """
        result = []
        stack = []
        current = self.root

        while stack or current:
            # Traverse to the leftmost node
            while current:
                stack.append(current)
                current = current.left

            # Process the node
            current = stack.pop()
            result.append((current.key, current.priority))

            # Move to the right subtree
            current = current.right

        return result

    def print_tree(self, node=None, level=0, prefix="Root: "):
        """
        Print the Treap structure for debugging.

        :param node: The current node (default is the root).
        :param level: The current level in the tree.
        :param prefix: The prefix string for the current node.
        """
        if node is None:
            node = self.root
        if node.right:
            self.print_tree(node.right, level + 1, "R--- ")
        print("    " * level + f"{prefix}({node.key}, {node.priority})")
        if node.left:
            self.print_tree(node.left, level + 1, "L--- ")

