from Trees.Nodes.BTreeNodes.b_tree_node import BTreeNode


class BTree:
    def __init__(self, t):
        """
        Initializes a B-Tree with a minimum degree `t`.
        Minimum degree `t` defines the allowed range for keys in each node.
        """
        self.root = BTreeNode(t)
        self.t = t  # Minimum degree

    def insert(self, key):
        """
        Inserts a key into the B-Tree.
        If the root is full, splits the root and creates a new root.
        """
        root = self.root
        # Check if root is full before insertion
        if len(root.keys) == 2 * self.t - 1:
            # Create new root and split the current root
            new_root = BTreeNode(self.t, is_leaf=False)
            new_root.children.append(self.root)
            new_root.split_child(0, root)

            # Determine the child to insert into based on the key
            idx = 0 if key < new_root.keys[0] else 1
            new_root.children[idx].insert_non_full(key)
            self.root = new_root  # Update the root reference
        else:
            root.insert_non_full(key)

    def search(self, key):
        """
        Searches for a key in the B-Tree.
        Returns the node containing the key, or None if not found.
        """
        return self.root.search(key) if self.root else None

    def remove(self, key):
        """
        Removes a key from the B-Tree and adjusts the structure.
        If the root becomes empty and has children, the root is updated.
        """
        if not self.root:
            return  # Tree is empty

        self.root.remove(key)

        # Adjust the root if it has no keys and is not a leaf
        if not self.root.keys:
            # Update root if it has children, otherwise set to None
            self.root = self.root.children[0] if not self.root.is_leaf else None

    def print_tree(self):
        """
        Prints the structure of the B-Tree level by level, omitting empty nodes.
        This function provides an overview of each level’s keys for clarity.
        """
        if self.root:
            self._print_tree_recursive(self.root, 0)

    def _print_tree_recursive(self, node, level):
        """
        Helper function to print B-Tree nodes level by level.
        Empty nodes are skipped, and non-leaf levels include their children.
        """
        # Print current level's keys
        if node.keys:
            print(f"Level {level}: {node.keys}", end=" | ")

        # Recur for child nodes at the next level, skipping empty child nodes
        if not node.is_leaf:
            for child in node.children:
                if child.keys:  # Avoid printing empty child nodes
                    self._print_tree_recursive(child, level + 1)
