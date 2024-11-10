class BTreeNode:
    def __init__(self, t, is_leaf=True):
        """
        Initialize a B-Tree node.

        Parameters:
            t (int): Minimum degree of the B-Tree. Determines the range of keys.
            is_leaf (bool): True if the node is a leaf, False otherwise.

        Attributes:
            keys (list): Holds the keys in the node.
            children (list): Holds references to the child nodes.
        """
        self.t = t  # Minimum degree (defines the range for the number of keys)
        self.is_leaf = is_leaf  # True if leaf node, otherwise False
        self.keys = []  # List of keys in the node
        self.children = []  # List of child nodes

    def insert_non_full(self, key):
        """
        Insert a key into a node that is not full.

        Parameters:
            key: The key to insert.

        This method handles both leaf and internal nodes. In a leaf node,
        the key is added directly. For internal nodes, it finds the correct
        child node and delegates the insertion, splitting the child if necessary.
        """
        i = len(self.keys) - 1

        if self.is_leaf:
            # Insert the new key in the correct position in sorted order
            self.keys.append(None)  # Temporary space for the new key
            while i >= 0 and key < self.keys[i]:
                self.keys[i + 1] = self.keys[i]
                i -= 1
            self.keys[i + 1] = key
        else:
            # Find the child that will receive the new key
            while i >= 0 and key < self.keys[i]:
                i -= 1
            i += 1

            # If the child is full, split it
            if len(self.children[i].keys) == 2 * self.t - 1:
                self.split_child(i, self.children[i])
                # After split, check which of the two new nodes should get the new key
                if key > self.keys[i]:
                    i += 1
            self.children[i].insert_non_full(key)

    def split_child(self, i, y):
        """
        Split the full child node `y` of this node at index `i`.

        Parameters:
            i (int): Index of the child in the children list.
            y (BTreeNode): The child node to be split.

        This method creates a new node `z` that takes half of the keys and children
        from `y`. The middle key from `y` is moved up into this node, and `z` is
        added as a new child of this node.
        """
        t = self.t
        z = BTreeNode(t, y.is_leaf)  # New node to hold t-1 keys of y

        # Copy the last t-1 keys and children from y to z
        z.keys = y.keys[t:]
        if not y.is_leaf:
            z.children = y.children[t:]

        # Reduce the number of keys in y
        y.keys = y.keys[:t - 1]
        y.children = y.children[:t]

        # Insert z as a new child of this node and move the middle key up
        self.children.insert(i + 1, z)
        middle_key = y.keys.pop()
        self.keys.insert(i, middle_key)

    def search(self, key):
        """
        Search for a key in the subtree rooted at this node.

        Parameters:
            key: The key to search for.

        Returns:
            BTreeNode: The node where the key is found, or None if not found.
        """
        i = self.find_key(key)
        if i < len(self.keys) and self.keys[i] == key:
            return self
        if self.is_leaf:
            return None
        return self.children[i].search(key)

    def remove(self, key):
        """
        Remove a key from the subtree rooted at this node.

        Parameters:
            key: The key to be removed.

        Assumes the key exists in the B-Tree rooted at this node.
        """
        idx = self.find_key(key)

        # Key is present in this node
        if idx < len(self.keys) and self.keys[idx] == key:
            if self.is_leaf:
                self.remove_from_leaf(idx)
            else:
                self.remove_from_non_leaf(idx)
        else:
            # Key is not present in this node
            if self.is_leaf:
                return  # Key not found in the tree
            flag = idx == len(self.keys)
            if len(self.children[idx].keys) < self.t:
                self.fill(idx)
            if flag and idx > len(self.keys):
                self.children[idx - 1].remove(key)
            else:
                self.children[idx].remove(key)

    def find_key(self, key):
        """
        Find the first key greater than or equal to the given key.

        Parameters:
            key: The key to locate.

        Returns:
            int: Index of the key in the node's keys list if it exists, or
            the index where it should be.
        """
        idx = 0
        while idx < len(self.keys) and self.keys[idx] < key:
            idx += 1
        return idx

    def get_pred(self, idx):
        """
        Get the predecessor of keys[idx].

        Parameters:
            idx (int): Index of the key in the node.

        Returns:
            Predecessor key.
        """
        cur = self.children[idx]
        while not cur.is_leaf:
            cur = cur.children[-1]
        return cur.keys[-1]

    def get_succ(self, idx):
        """
        Get the successor of keys[idx].

        Parameters:
            idx (int): Index of the key in the node.

        Returns:
            Successor key.
        """
        cur = self.children[idx + 1]
        while not cur.is_leaf:
            cur = cur.children[0]
        return cur.keys[0]

    def remove_from_leaf(self, idx):
        """Remove the key at idx from a leaf node."""
        self.keys.pop(idx)

    def remove_from_non_leaf(self, idx):
        """
        Remove the key at idx from a non-leaf node.

        Parameters:
            idx (int): Index of the key to remove.

        Replaces the key with its predecessor or successor based on availability,
        or merges children if necessary.
        """
        key = self.keys[idx]
        if len(self.children[idx].keys) >= self.t:
            pred = self.get_pred(idx)
            self.keys[idx] = pred
            self.children[idx].remove(pred)
        elif len(self.children[idx + 1].keys) >= self.t:
            succ = self.get_succ(idx)
            self.keys[idx] = succ
            self.children[idx + 1].remove(succ)
        else:
            self.merge(idx)
            self.children[idx].remove(key)

    def fill(self, idx):
        """Ensure that the child node at index idx has at least t keys."""
        if idx != 0 and len(self.children[idx - 1].keys) >= self.t:
            self.borrow_from_prev(idx)
        elif idx != len(self.keys) and len(self.children[idx + 1].keys) >= self.t:
            self.borrow_from_next(idx)
        else:
            if idx != len(self.keys):
                self.merge(idx)
            else:
                self.merge(idx - 1)

    def borrow_from_prev(self, idx):
        """Borrow a key from the previous child."""
        child = self.children[idx]
        sibling = self.children[idx - 1]
        child.keys.insert(0, self.keys[idx - 1])
        if not child.is_leaf:
            child.children.insert(0, sibling.children.pop())
        self.keys[idx - 1] = sibling.keys.pop()

    def borrow_from_next(self, idx):
        """Borrow a key from the next child."""
        child = self.children[idx]
        sibling = self.children[idx + 1]
        child.keys.append(self.keys[idx])
        if not child.is_leaf:
            child.children.append(sibling.children.pop(0))
        self.keys[idx] = sibling.keys.pop(0)

    def merge(self, idx):
        """
        Merge children[idx] and children[idx + 1] into a single node.

        Parameters:
            idx (int): Index of the key and child to merge.
        """
        child = self.children[idx]
        sibling = self.children[idx + 1]
        child.keys.append(self.keys.pop(idx))
        child.keys.extend(sibling.keys)
        if not child.is_leaf:
            child.children.extend(sibling.children)
        self.children.pop(idx + 1)

    def print_node(self, level=0):
        """
        Print the keys at the current level.

        Parameters:
            level (int): The current depth of the node in the tree.
        """
        print("Level", level, "Keys:", self.keys)
        for child in self.children:
            child.print_node(level + 1)
