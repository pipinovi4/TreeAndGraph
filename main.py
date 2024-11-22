from FullBinaryTrees.source.full_binary_tree import FullBinaryTree
from CompleteBinaryTrees.source.complete_binary_tree import CompleteBinaryTree
from PerfectBinaryTrees.source.perfect_binary_tree import PerfectBinaryTree
from BinarySearchTrees.source.binary_search_tree import BinarySearchTree
from AVLTree.source.avl_tree import AVLTree
from BTrees.source.b_tree import BTree
from BPTrees.source.b_plus_tree import BPTree
from FenwickTrees.source.fenwick_tree import FenwickTree
from SegmentTrees.source.segment_tree import SegmentTree
from SplayTrees.source.splay_tree import SplayTree
from Treaps.source.treap import Treap

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

    # ---------------- Fenwick Tree Example ---------------- #
    print("\n\nFenwick Tree (Binary Indexed Tree):")
    # Data for the Fenwick Tree
    fenwick_data = [3, 2, -1, 6, 5, 4, -3, 3, 7, 2]

    # Build the Fenwick Tree from the data
    fenwick_tree = FenwickTree.build(fenwick_data)
    print("Original data:", fenwick_data)

    # Query the prefix sum up to index 5
    prefix_sum_5 = fenwick_tree.query(5)
    print("Prefix sum up to index 5:", prefix_sum_5)  # Expected: 3 + 2 + -1 + 6 + 5 = 15

    # Range sum query from index 3 to 7
    range_sum_3_to_7 = fenwick_tree.range_query(3, 7)
    print("Range sum from index 3 to 7:", range_sum_3_to_7)  # Expected: -1 + 6 + 5 + 4 + -3 = 11

    # Update the value at index 3 by adding 4
    fenwick_tree.update(3, 4)
    print("Updated data (value at index 3 increased by 4).")

    # Query the prefix sum again after update
    updated_prefix_sum_5 = fenwick_tree.query(5)
    print("Prefix sum up to index 5 after update:", updated_prefix_sum_5)  # Expected: 3 + 2 + 3 + 6 + 5 = 19

    # Range sum query again after update
    updated_range_sum_3_to_7 = fenwick_tree.range_query(3, 7)
    print("Range sum from index 3 to 7 after update:", updated_range_sum_3_to_7)  # Expected: 3 + 6 + 5 + 4 + -3 = 15

    # ---------------- Segment Tree Example ---------------- #
    print("\n\nSegment Tree:")

    # Data for the Segment Tree
    segment_data = [2, 4, 5, 7, 8, 9, 1, 6]
    print("Original data:", segment_data)

    # Segment Tree for range minimum query
    st_min = SegmentTree(segment_data, func=min)
    print("\nSegment Tree (Range Minimum Query):")
    print("Minimum value in range [2, 5):", st_min.query(2, 5))  # Query minimum in the range [2, 5)

    # Update the value at index 3 to 3
    st_min.update(3, 3)
    print("Updated data (value at index 3 changed to 3).")
    print("Minimum value in range [2, 5) after update:", st_min.query(2, 5))

    # Segment Tree for range sum query
    st_sum = SegmentTree(segment_data, func=lambda x, y: x + y, identity=0)
    print("\nSegment Tree (Range Sum Query):")
    print("Sum of values in range [1, 4):", st_sum.query(1, 4))  # Query sum in the range [1, 4)

    # Update the value at index 2 to 10
    st_sum.update(2, 10)
    print("Updated data (value at index 2 changed to 10).")
    print("Sum of values in range [1, 4) after update:", st_sum.query(1, 4))

    # Segment Tree for range maximum query
    st_max = SegmentTree(segment_data, func=max)
    print("\nSegment Tree (Range Maximum Query):")
    print("Maximum value in range [3, 7):", st_max.query(3, 7))  # Query maximum in the range [3, 7)

    # Update the value at index 6 to 20
    st_max.update(6, 20)
    print("Updated data (value at index 6 changed to 20).")
    print("Maximum value in range [3, 7) after update:", st_max.query(3, 7))

    # ---------------- Splay Tree Example ---------------- #
    print("\n\nSplay Tree:")

    # Initialize the Splay Tree
    splay_tree = SplayTree()

    # Insert values into the Splay Tree
    for value in [10, 20, 30, 40, 50, 25, 35]:
        splay_tree.insert(value)
    print("Inserted values into Splay Tree.")

    # Perform an in-order traversal of the Splay Tree (should return a sorted order of elements)
    print("In-order traversal of the Splay Tree: ", splay_tree.inorder())

    # Search for a value in the Splay Tree
    search_value = 25
    print(f"\nSearching for value {search_value} in Splay Tree...")
    if splay_tree.search(search_value):
        print(f"Value {search_value} found and splayed to root.")
    else:
        print(f"Value {search_value} not found.")

    # Perform an in-order traversal after splaying
    print("In-order traversal after search: ", splay_tree.inorder())

    # Delete a value from the Splay Tree
    delete_value = 40
    print(f"\nDeleting value {delete_value} from Splay Tree...")
    splay_tree.delete(delete_value)
    print(f"Value {delete_value} deleted.")

    # Perform an in-order traversal after deletion
    print("In-order traversal after deletion: ", splay_tree.inorder())

    # Insert additional values to test tree restructuring
    print("\nInserting additional values [15, 5, 35] into Splay Tree...")
    for value in [15, 5, 35]:
        splay_tree.insert(value)
    print("In-order traversal after additional insertions: ", splay_tree.inorder())

    # ---------------- Treap Example ---------------- #
    print("\n\nTreap Tree:")

    # Initialize the Treap
    treap_tree = Treap()

    # Insert values into the Treap
    for value in [10, 20, 5, 15, 30, 25, 35, 16]:
        treap_tree.insert(value)
    print("Inserted values into Treap.")

    # Perform an in-order traversal of the Treap (should return a sorted order of elements with priorities)
    print("In-order traversal of the Treap (key, priority):")
    print(treap_tree.inorder())

    # Search for a value in the Treap
    search_value = 15
    print(f"\nSearching for value {search_value} in Treap...")
    if treap_tree.search(search_value):
        print(f"Value {search_value} found.")
    else:
        print(f"Value {search_value} not found.")

    # Delete a value from the Treap
    delete_value = 20
    print(f"\nDeleting value {delete_value} from Treap...")
    treap_tree.delete(delete_value)
    print(f"Value {delete_value} deleted.")

    # Perform an in-order traversal after deletion
    print("In-order traversal after deletion:")
    print(treap_tree.inorder())

    # Insert additional values to test tree restructuring
    print("\nInserting additional values [18, 3, 40] into Treap...")
    for value in [18, 3, 40]:
        treap_tree.insert(value)
    print("In-order traversal after additional insertions (key, priority):")
    print(treap_tree.inorder())
