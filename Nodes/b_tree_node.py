class BTreeNode:
    def __init__(self, t, is_leaf=True):
        self.t = t  # Minimum degree (defines the range for the number of keys)
        self.is_leaf = is_leaf  # True if leaf node, otherwise False
        self.keys = []  # List of keys
        self.children = []  # List of child nodes

    def insert_non_full(self, key):
        """Insert a key into a non-full node."""
        i = len(self.keys) - 1

        if self.is_leaf:
            # Insert the new key at the correct position in sorted order
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
                if key > self.keys[i]:
                    i += 1
            self.children[i].insert_non_full(key)

    def split_child(self, i, y):
        """Split the child y of this node. Node y must be full when this method is called."""
        t = self.t
        z = BTreeNode(t, y.is_leaf)

        # Copy the last t-1 keys from y to z
        z.keys = y.keys[t:]
        if not y.is_leaf:
            # If y is not a leaf, move the last t children to z
            z.children = y.children[t:]

        # Keep only the first t-1 keys in y
        y.keys = y.keys[:t - 1]
        y.children = y.children[:t]  # Retain only the first t children if not a leaf

        # Insert z as a child of this node and move the middle key of y to this node
        self.children.insert(i + 1, z)
        middle_key = y.keys.pop()  # Middle key of y after adjusting for t-1 keys
        self.keys.insert(i, middle_key)

    def search(self, key):
        """Search for a key in the B-Tree rooted at this node."""
        i = self.find_key(key)
        if i < len(self.keys) and key == self.keys[i]:
            return self
        if self.is_leaf:
            return None
        return self.children[i].search(key)

    def remove(self, key):
        """Remove key from this node. Assumes the key is present in the subtree rooted with this node."""
        idx = self.find_key(key)

        if idx < len(self.keys) and self.keys[idx] == key:
            if self.is_leaf:
                self.remove_from_leaf(idx)
            else:
                self.remove_from_non_leaf(idx)
        else:
            if self.is_leaf:
                return
            flag = idx == len(self.keys)
            if len(self.children[idx].keys) < self.t:
                self.fill(idx)
            if flag and idx > len(self.keys):
                self.children[idx - 1].remove(key)
            else:
                self.children[idx].remove(key)

    def find_key(self, key):
        """Find the first key greater than or equal to the given key in the node."""
        idx = 0
        while idx < len(self.keys) and self.keys[idx] < key:
            idx += 1
        return idx

    def get_pred(self, idx):
        """Get the predecessor of keys[idx]."""
        cur = self.children[idx]
        while not cur.is_leaf:
            cur = cur.children[-1]
        return cur.keys[-1]

    def get_succ(self, idx):
        """Get the successor of keys[idx]."""
        cur = self.children[idx + 1]
        while not cur.is_leaf:
            cur = cur.children[0]
        return cur.keys[0]

    def remove_from_leaf(self, idx):
        """Remove the key at idx from a leaf node."""
        self.keys.pop(idx)

    def remove_from_non_leaf(self, idx):
        """Remove the key at idx from a non-leaf node."""
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
        """Merge children[idx] and children[idx + 1] into a single node."""
        child = self.children[idx]
        sibling = self.children[idx + 1]
        child.keys.append(self.keys.pop(idx))
        child.keys.extend(sibling.keys)
        if not child.is_leaf:
            child.children.extend(sibling.children)
        self.children.pop(idx + 1)

    def print_node(self, level=0):
        """Prints keys at the current level."""
        print("Level", level, "Keys:", self.keys)
        for child in self.children:
            child.print_node(level + 1)