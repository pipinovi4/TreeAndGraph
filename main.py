from FullBinaryTrees.full_binary_tree import FullBinaryTree
from CompleteBinaryTrees.complete_binary_tree import CompleteBinaryTree
from PerfectBinaryTrees.perfect_binary_tree import PerfectBinaryTree
from BinarySearchTrees.binary_search_tree import BinarySearchTree
from AVLTree.avl_tree import AVLTree

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
    full_binary_tree.add_children(full_binary_tree.root.left, 4, 5)
    full_binary_tree.add_children(full_binary_tree.root.right, 6, 7)

    print("\nFully populated Full Binary Tree:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)  # Expected output: 1 2 4 5 3 6 7

    print("\nIs number \"5\" in Full Binary Tree:", full_binary_tree.search(full_binary_tree.root, 5))
    print("Is number \"8\" in Full Binary Tree:", full_binary_tree.search(full_binary_tree.root, 8))

    # ---------------- Complete Binary Tree Example ---------------- #
    print("\nComplete Binary Tree:")
    complete_binary_tree = CompleteBinaryTree()

    complete_binary_tree.insert(1)
    complete_binary_tree.insert(2)
    complete_binary_tree.insert(3)
    complete_binary_tree.insert(4)
    complete_binary_tree.insert(5)
    complete_binary_tree.insert(6)

    print("Fully populated Complete Binary Tree:", end=" ")
    complete_binary_tree.print_tree()  # Expected output: 1 2 3 4 5 6

    print("\nIs number \"5\" in Complete Binary Tree:", complete_binary_tree.search(5))
    print("Is number \"7\" in Complete Binary Tree:", complete_binary_tree.search(7))

    # ---------------- Perfect Binary Tree Example ---------------- #
    print("\nPerfect Binary Tree:")
    depth = 3
    perfect_binary_tree = PerfectBinaryTree(depth)

    print("Fully populated Perfect Binary Tree:", end=" ")
    perfect_binary_tree.print_tree(perfect_binary_tree.root)  # Expected output: 1 2 3 4 5 6 7

    print("\nIs number \"5\" in Perfect Binary Tree:", perfect_binary_tree.search(perfect_binary_tree.root, 5))
    print("Is number \"8\" in Perfect Binary Tree:", perfect_binary_tree.search(perfect_binary_tree.root, 8))

    # ---------------- Binary Search Tree Example ---------------- #
    print("\nBinary Search Tree:")
    bst = BinarySearchTree()

    values_to_insert = [5, 3, 7, 2, 4, 6, 8]
    for value in values_to_insert:
        bst.insert(value)

    print("In-order traversal of the Binary Search Tree: ", end="")
    bst.print_tree(bst.root)  # Expected output: 2 3 4 5 6 7 8

    print("\nIs number \"4\" in Binary Search Tree:", bst.search(4))
    print("Is number \"9\" in Binary Search Tree:", bst.search(9))

    # ---------------- AVL Tree Example ---------------- #
    print("\nAVL Tree:")
    avl_tree = AVLTree()  # Initialize AVL Tree

    # Insert values into the AVL Tree and automatically balance
    avl_values = [10, 20, 5, 6, 15, 30, 25, 16]
    for value in avl_values:
        avl_tree.insert(value)

    # Print the AVL Tree using in-order traversal
    print("In-order traversal of the AVL Tree (balanced): ", end="")
    avl_tree.print_in_order()  # Expected output (sorted): 5 6 10 15 16 20 25 30

    # Perform search operations on AVL Tree
    print("\nIs number \"15\" in AVL Tree:", avl_tree.search(15))  # Expected output: True
    print("Is number \"40\" in AVL Tree:", avl_tree.search(40))  # Expected output: False

    # Delete a value from the AVL Tree and re-balance
    avl_tree.delete(15)
    print("In-order traversal after deleting 15:", end=" ")
    avl_tree.print_in_order()  # Expected output: 5 6 10 16 20 25 30
