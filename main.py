from FullBinaryTrees.full_binary_tree import FullBinaryTree
from CompleteBinaryTrees.complete_binary_tree import CompleteBinaryTree
from PerfectBinaryTrees.perfect_binary_tree import PerfectBinaryTree
from BinarySearchTrees.binary_search_tree import BinarySearchTree
from AVLTree.avl_tree import AVLTree
from BTrees.b_tree import BTree
from BPTrees.b_plus_tree import BPTree

if __name__ == "__main__":
    # ---------------- Full Binary Tree Example ---------------- #
    print("Full Binary Tree:")
    full_binary_tree = FullBinaryTree()
    print("Initialized Full Binary Tree:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)
    full_binary_tree.add_children(full_binary_tree.root, 2, 3)
    print("\nAdded children for the root node:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)
    full_binary_tree.add_children(full_binary_tree.root.left, 4, 5)
    full_binary_tree.add_children(full_binary_tree.root.right, 6, 7)
    print("\nFully populated Full Binary Tree:", end=" ")
    full_binary_tree.print_tree(full_binary_tree.root)

    # ---------------- Complete Binary Tree Example ---------------- #
    print("\nComplete Binary Tree:")
    complete_binary_tree = CompleteBinaryTree()
    for i in range(1, 7):
        complete_binary_tree.insert(i)
    print("Fully populated Complete Binary Tree:", end=" ")
    complete_binary_tree.print_tree()

    # ---------------- Perfect Binary Tree Example ---------------- #
    print("\nPerfect Binary Tree:")
    perfect_binary_tree = PerfectBinaryTree(depth=3)
    print("Fully populated Perfect Binary Tree:", end=" ")
    perfect_binary_tree.print_tree(perfect_binary_tree.root)

    # ---------------- Binary Search Tree Example ---------------- #
    print("\nBinary Search Tree:")
    bst = BinarySearchTree()
    for value in [5, 3, 7, 2, 4, 6, 8]:
        bst.insert(value)
    print("In-order traversal of the Binary Search Tree: ", end="")
    bst.print_tree(bst.root)

    # ---------------- AVL Tree Example ---------------- #
    print("\nAVL Tree:")
    avl_tree = AVLTree()
    for value in [10, 20, 5, 6, 15, 30, 25, 16]:
        avl_tree.insert(value)
    print("In-order traversal of the AVL Tree (balanced): ", end="")
    avl_tree.print_in_order()

    # ---------------- B-Tree Example ---------------- #
    print("\n\nB-Tree:")
    t = 3
    b_tree = BTree(t)
    b_tree_values = [10, 20, 5, 6, 15, 30, 25, 16, 2, 12, 28, 35]
    for value in b_tree_values:
        b_tree.insert(value)
    print("Level-order traversal of the B-Tree after insertions:")
    b_tree.print_tree()

    print("\nIs number \"15\" in B-Tree:", b_tree.search(15))  # Expected output: Node containing 15
    print("Is number \"40\" in B-Tree:", b_tree.search(40))    # Expected output: None (not found)

    b_tree.remove(15)
    print("\nLevel-order traversal after deleting 15:")
    b_tree.print_tree()
    b_tree.remove(10)
    print("\nLevel-order traversal after deleting 10:")
    b_tree.print_tree()
    b_tree.remove(5)
    print("\nLevel-order traversal after deleting 5:")
    b_tree.print_tree()

    # ---------------- B+ Tree Example ---------------- #
    print("\n\nB+ Tree:\n")
    b_plus_tree = BPTree(t)
    for value in b_tree_values:
        b_plus_tree.insert(value)
    print("Level-order traversal of the B+ Tree after insertions:")
    b_plus_tree.print_tree()

    print("\nIs number \"15\" in B+ Tree:", True if b_plus_tree.search(15) else False)  # Expected output: Node containing 15
    print("Is number \"40\" in B+ Tree:", True if b_plus_tree.search(40) else False)    # Expected output: None (not found)

    print("\nRange Query for values between 10 and 30:")
    print(b_plus_tree.range_query(10, 30))  # Expected output: values in range 10 to 30

    b_plus_tree.delete(15)
    print("\nLevel-order traversal after deleting 15:")
    b_plus_tree.print_tree()
    b_plus_tree.delete(10)
    print("\nLevel-order traversal after deleting 10:")
    b_plus_tree.print_tree()
    b_plus_tree.delete(5)
    print("\nLevel-order traversal after deleting 5:")
    b_plus_tree.print_tree()

    print("\nRange Query for values between 10 and 30 after deletions:")
    print(b_plus_tree.range_query(10, 30))  # Expected output: updated values in range 10 to 30
#[20, 25, 16, 30, 12, 28]
