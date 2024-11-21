from Nodes.defaultNodes.node import Node


class SplayTree:
    """
    SplayTree is a self-adjusting binary search tree with the additional property that
    recently accessed elements are quick to access again. It supports standard operations
    like search, insert, delete, and in-order traversal.
    """

    def __init__(self):
        """
        Initialize an empty Splay Tree with no root node.
        """
        self.root = None

    def search(self, data):
        """
        Search for a data in the tree and splay the node containing the data to the root.

        :param data: The data to search for.
        :return: True if the data exists, False otherwise.
        """
        self.root = self._splay(self.root, data)
        return self.root and self.root.data == data

    def insert(self, data):
        """
        Insert a data into the Splay Tree. If the data already exists, no changes are made.

        :param data: The data to insert.
        """
        if not self.root:
            self.root = Node(data)  # Create root if tree is empty
            return

        # Splay the tree to bring the closest match (or exact data) to the root
        self.root = self._splay(self.root, data)

        if self.root.data == data:
            return  # Data already exists; no insertion needed

        # Create a new node for the data
        new_node = Node(data)

        if data < self.root.data:
            # Insert as the new root with the current root as its right subtree
            new_node.right = self.root
            new_node.left = self.root.left
            self.root.left = None
        else:
            # Insert as the new root with the current root as its left subtree
            new_node.left = self.root
            new_node.right = self.root.right
            self.root.right = None

        self.root = new_node  # Update the root to the new node

    def delete(self, data):
        """
        Delete a data from the Splay Tree. If the data does not exist, the tree remains unchanged.

        :param data: The data to delete.
        """
        if not self.root:
            return  # Tree is empty, nothing to delete

        # Splay the tree to bring the data to the root
        self.root = self._splay(self.root, data)

        if self.root.data != data:
            return  # Data not found, nothing to delete

        if not self.root.left:
            # If there is no left subtree, promote the right subtree as the root
            self.root = self.root.right
        elif not self.root.right:
            # If there is no right subtree, promote the left subtree as the root
            self.root = self.root.left
        else:
            # Both left and right subtrees exist
            left_subtree = self.root.left
            right_subtree = self.root.right

            # Splay the largest data in the left subtree to the root
            self.root = self._splay(left_subtree, data)

            # Attach the right subtree to the new root's right
            self.root.right = right_subtree

    def inorder(self, node=None, result=None):
        """
        Perform an in-order traversal of the tree, returning the data in sorted order.

        :param node: The starting node for the traversal (default is the root).
        :param result: A list to accumulate the traversal result (default is a new list).
        :return: A list of data in in-order.
        """
        if result is None:
            result = []
        if node is None:
            node = self.root

        if node:
            # Traverse the left subtree
            if node.left:
                self.inorder(node.left, result)

            # Append the current node's data to the result
            result.append(node.data)

            # Traverse the right subtree
            if node.right:
                self.inorder(node.right, result)
        return result

    def _splay(self, node, data):
        """
        Splay the tree to bring the node with the specified data to the root.

        :param node: The root of the current subtree.
        :param data: The data to splay to the root.
        :return: The new root of the subtree.
        """
        if not node or node.data == data:
            return node  # Base case: tree is empty or data is at the root

        # Data lies in the left subtree
        if data < node.data:
            if not node.left:
                return node  # Data not in tree

            # Zig-zag (Left-Left)
            if data < node.left.data:
                node.left.left = self._splay(node.left.left, data)
                node = self._right_rotate(node)

            # Zig-zag (Left-Right)
            elif data > node.left.data:
                node.left.right = self._splay(node.left.right, data)
                if node.left.right:
                    node.left = self._left_rotation(node.left)

            return self._right_rotate(node) if node.left else node

        # Data lies in the right subtree
        else:
            if not node.right:
                return node  # Data not in tree

            # Zig-zag (Right-Right)
            if data > node.right.data:
                node.right.right = self._splay(node.right.right, data)
                node = self._left_rotation(node)

            # Zig-zag (Right-Left)
            elif data < node.right.data:
                node.right.left = self._splay(node.right.left, data)
                if node.right.left:
                    node.right = self._right_rotate(node.right)

            return self._left_rotation(node) if node.right else node

    @staticmethod
    def _right_rotate(node):
        """
        Perform a right rotation on the given node.

        :param node: The node to rotate.
        :return: The new root after rotation.
        """
        new_root = node.left
        node.left = new_root.right
        new_root.right = node
        return new_root

    @staticmethod
    def _left_rotation(node):
        """
        Perform a left rotation on the given node.

        :param node: The node to rotate.
        :return: The new root after rotation.
        """
        new_root = node.right
        node.right = new_root.left
        new_root.left = node
        return new_root
