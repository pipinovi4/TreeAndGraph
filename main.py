from FullBinaryTrees.full_binary_tree import FullBinaryTree
from CompleteBinaryTrees.complete_binary_tree import CompleteBinaryTree

if __name__ == "__main__":
    # ---------------- Full Binary Tree Example ---------------- #
    print("Full Binary Tree:")
    full_binary_tree = FullBinaryTree()  # Initialize FullBinaryTree with root set to Node(1)

    # Print the initial state of the FullBinaryTree (only the root node)
    print("Initialized Full Binary Tree:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)  # Expected output: 1

    # Add children to the root node
    full_binary_tree.add_children(full_binary_tree.root, 2, 3)
    print("\nAdded children for the root node:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)  # Expected output: 1 2 3

    # Add more children to the existing nodes
    full_binary_tree.add_children(full_binary_tree.root.left, 4, 5)  # Adds Node(4) and Node(5) as children of Node(2)
    full_binary_tree.add_children(full_binary_tree.root.right, 6, 7) # Adds Node(6) and Node(7) as children of Node(3)

    # Print the fully populated FullBinaryTree
    print("\nFully populated Full Binary Tree:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)  # Expected output: 1 2 4 5 3 6 7

    # Perform search operations on FullBinaryTree
    print("\nIs number \"5\" in Full Binary Tree:", full_binary_tree.search(full_binary_tree.root, 5))  # Expected output: True
    print("Is number \"8\" in Full Binary Tree:", full_binary_tree.search(full_binary_tree.root, 8))  # Expected output: False

    # ---------------- Complete Binary Tree Example ---------------- #
    print("\nComplete Binary Tree:")
    complete_binary_tree = CompleteBinaryTree()  # Initialize CompleteBinaryTree with root set to Node(1)

    # Insert nodes level-by-level to maintain complete binary tree properties
    complete_binary_tree.insert(1)  # Insert root node
    complete_binary_tree.insert(2)  # Inserts as left child of root
    complete_binary_tree.insert(3)  # Inserts as right child of root
    complete_binary_tree.insert(4)  # Inserts as left child of node 2
    complete_binary_tree.insert(5)  # Inserts as right child of node 2
    complete_binary_tree.insert(6)  # Inserts as left child of node 3

    # Print the populated CompleteBinaryTree
    print("Fully populated Complete Binary Tree:", end=" ")
    complete_binary_tree.print_tree()  # Expected output: 1 2 3 4 5 6

    # Perform search operations on CompleteBinaryTree
    print("\nIs number \"5\" in Complete Binary Tree:", complete_binary_tree.search(5))  # Expected output: True
    print("Is number \"7\" in Complete Binary Tree:", complete_binary_tree.search(7))  # Expected output: False
