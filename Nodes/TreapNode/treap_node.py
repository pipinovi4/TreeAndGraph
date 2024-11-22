import random


class TreapNode:
    """
    A node in the Treap Tree.

    A TreapNode combines properties of both a binary search tree and a heap:
    - The key maintains the binary search tree property (keys in the left subtree are smaller, and keys in the right subtree are larger).
    - The priority maintains the heap property (a parent's priority is higher than its children).

    Attributes:
        key (int): The key value of the node.
        priority (int): The priority of the node, used to maintain the heap property.
                        If not provided, a random priority is assigned.
        left (TreapNode or None): Pointer to the left child.
        right (TreapNode or None): Pointer to the right child.
    """

    def __init__(self, key, priority=None):
        """
        Initialize a TreapNode with a given key and optional priority.

        If the priority is not provided, a random priority is generated between 1 and 100.

        Args:
            key (int): The key value for the node.
            priority (int, optional): The priority value for the node. Defaults to a random value.

        Example:
            >>> node = TreapNode(10)
            >>> print(node.key, node.priority)  # Key is 10, priority is a random value
        """
        self.key = key
        self.priority = priority if priority is not None else random.randint(1, 100)
        self.left = None
        self.right = None
