from FullBinaryTrees.full_binary_tree import FullBinaryTree

if __name__ == "__main__":
    # 1. Initialize FullBinaryTree with root set to Node(1)
    print("Full Binary Tree:")
    full_binary_tree = FullBinaryTree()  # Root node is initialized with value 1

    # 2. Print the initial state of the tree (only the root node)
    print("Initialized Full Binary Tree:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)  # Expected output: 1

    # 3. Add children to the root node
    # Adds left (Node(2)) and right (Node(3)) children to the root node
    full_binary_tree.add_children(full_binary_tree.root, 2, 3)
    print("\nAdded children for the root node:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)  # Expected output: 1 2 3

    # 4. Add more children to the existing nodes
    # Adds children to Node(2) and Node(3), which are the left and right children of the root
    full_binary_tree.add_children(full_binary_tree.root.left, 4, 5)  # Adds Node(4) and Node(5) as children of Node(2)
    full_binary_tree.add_children(full_binary_tree.root.right, 6, 7) # Adds Node(6) and Node(7) as children of Node(3)

    # 5. Print the fully populated Full Binary Tree
    print("\nFully populated Full Binary Tree:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)  # Expected output: 1 2 4 5 3 6 7

    # 6. Perform search operations to check if specific values exist in the tree
    print("\nIs number \"5\" in tree:", full_binary_tree.search(full_binary_tree.root, 5))  # Expected output: True
    print("Is number \"8\" in tree:", full_binary_tree.search(full_binary_tree.root, 8))  # Expected output: False
