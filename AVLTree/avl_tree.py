from Nodes.node import Node


class AVLTree:
    def __init__(self):
        self.root = None

    # Utility function to get the height of the tree
    @staticmethod
    def _height(node):
        if not node:
            return 0
        return node.height

    def _update_height(self, node):
        node.height = 1 + max(self._height(node.left), self._height(node.right))

    def _get_balance(self, node):
        if not node:
            return 0
        return self._height(node.left) - self._height(node.right)

    def _right_rotate(self, y):
        x = y.left
        t2 = x.right

        # Perform rotation
        x.right = y
        y.left = t2

        # Update heights
        self._update_height(y)
        self._update_height(x)

        # Return new root
        return x

    def _left_rotation(self, x):
        y = x.right
        t2 = y.left

        # Perform rotation
        y.left = x
        x.right = t2

        # Update heights
        self._update_height(x)
        self._update_height(y)

        # Return new root
        return y

    def insert(self, data):
        self.root = self._insert(self.root, data)

    def _insert(self, node, data):
        if not node:
            return Node(data)
        if data < node.data:
            node.left = self._insert(node.left, data)
        elif data > node.data:
            node.right = self._insert(node.right, data)
        else:
            return node

        self._update_height(node)
        balance = self._get_balance(node)

        # Left Left Case
        if balance > 1 and data < node.left.data:
            return self._right_rotate(node)
        # Right Right Case
        if balance < -1 and data > node.right.data:
            return self._left_rotation(node)
        # Left Right Case
        if balance > 1 and data > node.left.data:
            node.left = self._left_rotation(node.left)
            return self._right_rotate(node)
        # Right Left Case
        if balance < -1 and data < node.right.data:
            node.right = self._right_rotate(node.right)
            return self._left_rotation(node)

        return node

    # Search for a value in the tree
    def search(self, target):
        return self._search(self.root, target)

    def _search(self, node, target):
        if node is None:
            return False
        if target == node.data:
            return True
        elif target < node.data:
            return self._search(node.left, target)
        else:
            return self._search(node.right, target)

    def delete(self, data):
        self.root = self._delete(self.root, data)

    def _delete(self, node, data):
        if not node:
            return node
        if data < node.data:
            node.left = self._delete(node.left, data)
        elif data > node.data:
            node.right = self._delete(node.right, data)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            # Node with two children: get the inorder successor
            temp = self._min_value_node(node.right)
            node.data = temp.data
            node.right = self._delete(node.right, temp.data)

        if not node:
            return node

        self._update_height(node)
        balance = self._get_balance(node)

        # Left Left Case
        if balance > 1 and self._get_balance(node.left) >= 0:
            return self._right_rotate(node)
        # Right Right Case
        if balance < -1 and self._get_balance(node.right <= 0):
            return self._left_rotation(node)
        # Left Right Case
        if balance > 1 and self._get_balance(node.left) < 0:
            node.left = self._left_rotation(node)
            return self._right_rotate(node)
        # Right Left case
        if balance < -1 and self._get_balance(node.right) > 0:
            node.right = self._right_rotate(node.right)
            return self._left_rotation(node)

        return node

    @staticmethod
    def _min_value_node(self, node):
        current = node
        while current.left:
            current = current.left
        return current

    def print_in_order(self):
        # Initialize an empty stack to track nodes and start from the root
        stack = []
        current = self.root

        while stack or current:
            # Reach the leftmost node of the current node
            while current:
                stack.append(current)
                current = current.left

            # Current is None at this point, so pop from the stack
            current = stack.pop()
            print(current.data, end=" ")

            # Visit the right subtree
            current = current.right
