from Trees.AVLTrees.source.avl_tree import AVLTree
import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

if __name__ == "__main__":
    # Initialize the AVL tree
    avl_tree = AVLTree()

    # Insert values into the AVL tree
    values_to_insert = [10, 20, 5, 15, 30, 25, 35, 16]
    print("Inserting values:", values_to_insert)
    for value in values_to_insert:
        avl_tree.insert(value)

    # Print the AVL tree in-order (should be sorted)
    print("\nIn-order traversal after insertions:")
    avl_tree.print_in_order()

    # Search for a value in the tree
    search_value = 15
    print(f"\n\nSearching for value {search_value} in the tree...")
    if avl_tree.search(search_value):
        print(f"Value {search_value} found in the tree!")
    else:
        print(f"Value {search_value} not found in the tree!")

    # Delete a value from the AVL tree
    delete_value = 20
    print(f"\nDeleting value {delete_value} from the tree...")
    avl_tree.delete(delete_value)

    # Print the AVL tree in-order after deletion
    print("\nIn-order traversal after deletion:")
    avl_tree.print_in_order()

    # Insert additional values to test rebalancing
    additional_values = [18, 3, 40]
    print("\n\nInserting additional values:", additional_values)
    for value in additional_values:
        avl_tree.insert(value)

    # Print the AVL tree in-order after additional insertions
    print("\nIn-order traversal after additional insertions:")
    avl_tree.print_in_order()

    # Final tree structure (debugging/visualizing purposes)
    print("\n\nFinal AVL Tree structure:")
    avl_tree.print_in_order()