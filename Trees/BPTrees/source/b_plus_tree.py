from Trees.Nodes.BPTreeNodes.b_plus_tree_node import BPTreeNode


class BPTree:
    def __init__(self, t):
        """
        Initializes a B+ Tree.
        :param t: Minimum degree of the tree.
        """
        self.t = t
        self.root = BPTreeNode(t, is_leaf=True)

    def insert(self, key):
        """
        Inserts a key into the B+ Tree.
        :param key: Key to be inserted.
        """
        root = self.root  # [10, 20, 30]
        if len(root.keys) == 2 * self.t - 1:  # Root is full
            new_root = BPTreeNode(self.t, is_leaf=False)  # []
            new_root.children.append(root)  # [] -> [10, 20, 30]
            new_root.split_children(0)
            self.root = new_root  # Update root reference
        self.root.insert_non_full(key)

    def search(self, key):
        """
        Searches for a key in the B+ Tree.
        :param key: Key to search for.
        :return: Node containing the key or None if not found.
        """
        node = self.root
        while not node.is_leaf:
            i = 0
            while i < len(node.keys) and key >= node.keys[i]:
                i += 1
            node = node.children[i]
        return node if key in node.keys else None

    def delete(self, key):
        """
        Deletes a key from the B+ Tree.
        :param key: Key to be deleted.
        """
        self._delete_recursive(self.root, key)
        if len(self.root.keys) == 0 and not self.root.is_leaf:
            self.root = self.root.children[0]  # Update root if it becomes empty

    def range_query(self, start_key, end_key):
        """
        Returns all keys within the specified range [start_key, end_key].
        :param start_key: Start of the range.
        :param end_key: End of the range.
        :return: List of keys within the range.
        """
        result = []
        node = self.root
        while not node.is_leaf:
            i = 0
            while i < len(node.keys) and start_key > node.keys[i]:
                i += 1
            node = node.children[i]

        # Collect keys within range in leaf nodes
        while node:
            for key in node.keys:
                if start_key <= key <= end_key:
                    result.append(key)
                elif key > end_key:
                    return result
            node = node.next  # Move to the next leaf node
        return result

    def _delete_recursive(self, node, key):
        """
        Recursively deletes a key from the tree.
        :param node: Current node.
        :param key: Key to be deleted.
        """
        if node.is_leaf:
            if key in node.keys:
                node.keys.remove(key)
        else:
            i = 0
            while i < len(node.keys) and key > node.keys[i]:
                i += 1
            if i < len(node.keys) and key == node.keys[i]:
                if node.children[i].is_leaf:
                    node.keys[i] = node.children[i].keys[-1]
                    self._delete_recursive(node.children[i], node.keys[i])
                else:
                    node.keys[i] = node.children[i + 1].keys[0]
                    self._delete_recursive(node.children[i + 1], node.keys[i])
            else:
                if len(node.children[i].keys) < self.t:
                    self._fix_child(node, i)
                self._delete_recursive(node.children[i], key)

    def _fix_child(self, parent, index):
        """
        Fixes a child node with fewer than t keys by borrowing or merging.
        :param parent: Parent node of the child.
        :param index: Index of the child.
        """
        if index > 0 and len(parent.children[index - 1].keys) >= self.t:
            left_sibling = parent.children[index - 1]
            current_child = parent.children[index]
            current_child.keys.insert(0, parent.keys[index - 1])
            if not left_sibling.is_leaf:
                current_child.children.insert(0, left_sibling.children.pop())
            parent.keys[index - 1] = left_sibling.keys.pop()
        elif index < len(parent.children) - 1 and len(parent.children[index + 1].keys) >= self.t:
            right_sibling = parent.children[index + 1]
            current_child = parent.children[index]
            current_child.keys.append(parent.keys[index])
            if not right_sibling.is_leaf:
                current_child.children.append(right_sibling.children.pop(0))
            parent.keys[index] = right_sibling.keys.pop(0)
        else:
            if index > 0:
                self._merge_nodes(parent, index - 1)
            else:
                self._merge_nodes(parent, index)

    @staticmethod
    def _merge_nodes(parent, index):
        """
        Merges two sibling nodes into one.
        :param parent: Parent node containing the children to merge.
        :param index: Index of the left child.
        """
        left_child = parent.children[index]
        right_child = parent.children.pop(index + 1)
        left_child.keys.append(parent.keys.pop(index))
        left_child.keys.extend(right_child.keys)
        if not left_child.is_leaf:
            left_child.children.extend(right_child.children)
        else:
            left_child.next = right_child.next

    def print_tree(self):
        """
        Prints the B+ Tree level by level.
        """
        level = [self.root]
        while level:
            next_level = []
            for node in level:
                print(f"[{', '.join(map(str, node.keys))}] ", end='')
                if not node.is_leaf:
                    next_level.extend(node.children)
            print()
            level = next_level
