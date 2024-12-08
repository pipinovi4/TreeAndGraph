class BPTreeNode:
    def __init__(self, t, is_leaf=False):
        """
        Initializes a B+ Tree node.
        :param t: Minimum degree (defines range for number of keys).
        :param is_leaf: Boolean indicating if the node is a leaf.
        """
        self.t = t
        self.is_leaf = is_leaf
        self.keys = []
        self.children = []
        self.next = None  # Pointer to the next leaf node (used for range queries)

    def insert_non_full(self, key):
        """
        Inserts a key into a non-full node.
        :param key: Key to be inserted.
        """
        if self.is_leaf:
            # Insert key into the sorted position within the leaf node
            i = 0
            while i < len(self.keys) and self.keys[i] < key:
                i += 1
            self.keys.insert(i, key)
        else:
            # Navigate to the correct child for insertion
            i = len(self.keys) - 1
            while i >= 0 and key < self.keys[i]:
                i -= 1
            i += 1

            # Split child if it is full
            if len(self.children[i].keys) == 2 * self.t - 1:
                self.split_children(i)
                if key > self.keys[i]:
                    i += 1
            self.children[i].insert_non_full(key)

    def split_children(self, i):
        """
        Splits a full child of this node.
        :param i: Index of the child to be split.
        """
        t = self.t
        child = self.children[i]  # [] -> [10, 20, 30] index i is 10. child = 10
        new_child = BPTreeNode(t, child.is_leaf)  # []

        # Split the keys and children
        new_child.keys = child.keys[t:]  # []
        child.keys = child.keys[:t - 1]

        if not child.is_leaf:
            new_child.children = child.children[t:]
            child.children = child.children[:t]

        # Adjust linked list pointers for leaf nodes
        if child.is_leaf:
            new_child.next = child.next
            child.next = new_child

        # Insert median key into this node and adjust child pointers
        self.keys.insert(i, child.keys.pop())
        self.children.insert(i + 1, new_child)
