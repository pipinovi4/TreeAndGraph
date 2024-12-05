from PerfectBinaryTrees.source.perfect_binary_tree import PerfectBinaryTree  # Import the PerfectBinaryTree class

if __name__ == "__main__":
    # Create a Perfect Binary Tree of depth 3
    depth = 3  # Tree will have 2^3 - 1 = 7 nodes
    perfect_tree = PerfectBinaryTree(depth)

    # Print the tree using pre-order traversal
    print("Pre-order Traversal of Perfect Binary Tree:")
    perfect_tree.print_tree(perfect_tree.root)  # Outputs: 1 2 4 5 3 6 7

    # Search for a value in the tree
    search_value1 = 4
    print(f"\nSearching for value {search_value1} in the tree:")
    is_found1 = perfect_tree.search(perfect_tree.root, search_value1)
    print("Found!" if is_found1 else "Not found.")

    # Search for a value not present in the tree
    search_value2 = 10
    print(f"Searching for value {search_value2} in the tree:")
    is_found2 = perfect_tree.search(perfect_tree.root, search_value2)
    print("Found!" if is_found2 else "Not found.")
