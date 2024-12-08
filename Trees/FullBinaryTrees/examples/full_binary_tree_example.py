from Trees.FullBinaryTrees.source.full_binary_tree import FullBinaryTree  # Import the FullBinaryTree class


if __name__ == "__main__":
    # Create a FullBinaryTree instance
    tree = FullBinaryTree()

    # Add children to the root node
    FullBinaryTree.add_children(tree.root, 2, 3)  # Add left child (2) and right child (3)

    # Add children to the left child of the root
    FullBinaryTree.add_children(tree.root.left, 4, 5)  # Add children 4 and 5 to node 2

    # Add children to the right child of the root
    FullBinaryTree.add_children(tree.root.right, 6, 7)  # Add children 6 and 7 to node 3

    # Print the tree in pre-order traversal
    print("Tree in pre-order traversal:")
    tree.print_tree(tree.root)  # Output: 1 2 4 5 3 6 7
    print()

    # Search for a value in the tree
    target = 5
    found = tree.search(tree.root, target)
    print(f"Value {target} {'is found' if found else 'is not found'} in the tree.")

    # Search for a value not in the tree
    missing_target = 10
    not_found = tree.search(tree.root, missing_target)
    print(f"Value {missing_target} {'is found' if not_found else 'is not found'} in the tree.")
