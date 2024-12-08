from Trees.Nodes.TreapNode.treap_node import TreapNode
import random


class Treap:
    """
    A Treap is a randomized binary search tree that maintains both BST and heap properties.
    Each node has a key and a priority, ensuring:
    - Binary Search Tree (BST) property: Keys in the left subtree are smaller, and keys in the right subtree are larger.
    - Max-Heap property: Each node's priority is greater than or equal to the priorities of its children.

    Treap combine the benefits of BSTs and heaps, making them useful for maintaining sorted dynamic data
    structures with randomization to ensure balanced tree properties.
    """

    priority_counter = 0  # Counter for generating unique priorities to avoid collisions

    def __init__(self):
        """
        Initialize an empty Treap with no root node.
        """
        self.root = None

    @staticmethod
    def _rotate_right(node):
        """
        Perform a right rotation on the given node to maintain the heap property.

        :param node: The node to rotate.
        :return: The new root of the subtree after rotation.
        """
        left_child = node.left
        node.left = left_child.right
        left_child.right = node
        return left_child

    @staticmethod
    def _rotate_left(node):
        """
        Perform a left rotation on the given node to maintain the heap property.

        :param node: The node to rotate.
        :return: The new root of the subtree after rotation.
        """
        right_child = node.right
        node.right = right_child.left
        right_child.left = node
        return right_child

    @staticmethod
    def _generate_unique_priority(base_priority=None):
        """
        Generate a unique priority to avoid collisions between nodes.

        :param base_priority: Optional base priority (default is a randomly generated integer).
        :return: A unique priority value.
        """
        if base_priority is None:
            base_priority = random.randint(1, 1000000)
        unique_offset = Treap.priority_counter
        Treap.priority_counter += 1
        return base_priority + unique_offset

    def insert(self, key, priority=None):
        """
        Insert a key into the Treap while maintaining both BST and heap properties.

        :param key: The key to insert.
        :param priority: Optional priority for the node (a random priority is generated if not provided).
        """
        if priority is None:
            priority = self._generate_unique_priority()

        # Create the new node to insert
        new_node = TreapNode(key, priority)
        if self.root is None:
            self.root = new_node  # If the tree is empty, the new node becomes the root
            return

        # Traverse the tree to find the correct position for the new node
        parent = None
        current = self.root
        stack = []  # Stack to keep track of the path for rotations

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
                # Key already exists; no insertion needed
                return

        # Rebalance the tree to maintain the heap property
        current = new_node
        while stack:
            parent = stack.pop()
            if parent.priority < current.priority:  # Heap violation detected
                if parent.left == current:
                    rotated = self._rotate_right(parent)
                else:
                    rotated = self._rotate_left(parent)

                # Update parent's reference in the stack
                if stack:
                    grandparent = stack[-1]
                    if grandparent.left == parent:
                        grandparent.left = rotated
                    else:
                        grandparent.right = rotated
                else:
                    self.root = rotated  # Update the root if the parent was the root
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
            # Key not found; nothing to delete
            return

        # Rotate the node until it has at most one child
        while current.left and current.right:
            if current.left.priority > current.right.priority:
                rotated = self._rotate_right(current)
            else:
                rotated = self._rotate_left(current)

            # Update parent's reference after rotation
            if parent is None:
                self.root = rotated
            elif parent.left == current:
                parent.left = rotated
            else:
                parent.right = rotated

            parent = rotated

        # Remove the node (it has at most one child at this point)
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
                return True  # Key found
            elif key < current.key:
                current = current.left
            else:
                current = current.right
        return False  # Key not found

    def inorder(self):
        """
        Perform an in-order traversal of the Treap to retrieve keys in sorted order.

        :return: List of tuples (key, priority) in sorted order.
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

    def print_tree(self):
        """
        Print the Treap structure with indentation for visual clarity.
        """
        if self.root is None:
            print("Tree is empty.")
            return

        # Stack stores tuples: (node, level, prefix)
        stack = [(self.root, 0, "Root: ")]

        while stack:
            current, level, prefix = stack.pop()

            # Print the current node with indentation
            print("    " * level + f"{prefix}({current.key}, {current.priority})")

            # Push right child first so left child is processed first
            if current.right:
                stack.append((current.right, level + 1, "R--- "))
            if current.left:
                stack.append((current.left, level + 1, "L--- "))
