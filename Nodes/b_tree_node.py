class BTreeNode:
    """
    A node in a B-Tree.

    Attributes:
        is_leaf (bool): True if the node is a leaf node.
        keys (list): List of keys in the node.
        children (list): List of child pointers (empty if leaf).
    """

    def __init__(self, is_leaf=True):
        """
        Initialize a BTreeNode.

        Args:
            is_leaf (bool): Set to True if this node is a leaf.
        """
        self.is_leaf = is_leaf  # Indicates if the node is a leaf
        self.keys = []          # List of keys in the node
        self.children = []      # List of child pointers

    def add_key(self, key):
        """
        Add a key to the node and keep the keys sorted.

        Args:
            key: The key to add.
        """
        self.keys.append(key)
        self.keys.sort()  # Keep keys sorted after each insertion

    def remove_key(self, key):
        """
        Remove a key from the node, if it exists.

        Args:
            key: The key to remove.
        """
        if key in self.keys:
            self.keys.remove(key)

    def is_full(self, max_keys):
        """
        Check if the node is full based on the maximum number of keys allowed.

        Args:
            max_keys (int): The maximum number of keys allowed in the node.

        Returns:
            bool: True if the node has max_keys keys, False otherwise.
        """
        return len(self.keys) == max_keys
