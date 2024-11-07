from FullBinaryTrees.full_binary_tree import FullBinaryTree
from CompleteBinaryTrees.complete_binary_tree import CompleteBinaryTree
from PerfectBinaryTrees.perfect_binary_tree import PerfectBinaryTree
from BinarySearchTrees.binary_search_tree import BinarySearchTree

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

    # ---------------- Perfect Binary Tree Example ---------------- #
    print("\nPerfect Binary Tree:")
    depth = 3  # Depth of the perfect binary tree

    perfect_binary_tree = PerfectBinaryTree(depth)  # Initialize PerfectBinaryTree

    # Print the populated PerfectBinaryTree
    print("Fully populated Perfect Binary Tree:", end=" ")
    perfect_binary_tree.print_tree(perfect_binary_tree.root)  # Expected output: 1 2 3 4 5 6 7

    # Perform search operations on PerfectBinaryTree
    print("\nIs number \"5\" in Perfect Binary Tree:", perfect_binary_tree.search(perfect_binary_tree.root, 5))  # Expected output: True
    print("Is number \"8\" in Perfect Binary Tree:", perfect_binary_tree.search(perfect_binary_tree.root, 8))  # Expected output: False

    # ---------------- Binary Search Tree Example ---------------- #
    print("\nBinary Search Tree:")
    bst = BinarySearchTree()  # Initialize the Binary Search Tree

    # Insert values into the Binary Search Tree
    values_to_insert = [5, 3, 7, 2, 4, 6, 8]
    for value in values_to_insert:
        bst.insert(value)  # Insert each value

    # Print the Binary Search Tree using in-order traversal
    print("In-order traversal of the Binary Search Tree: ", end="")
    bst.print_tree(bst.root)  # Expected output: 2 3 4 5 6 7 8

    # Perform search operations on Binary Search Tree
    print("\nIs number \"4\" in Binary Search Tree:", bst.search(4))  # Expected output: True
    print("Is number \"9\" in Binary Search Tree:", bst.search(9))  # Expected output: False
