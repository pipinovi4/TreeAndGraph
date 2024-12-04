from CompleteBinaryTrees.source.complete_binary_tree import CompleteBinaryTree  # Import the CompleteBinaryTree class

if __name__ == "__main__":
    # Create a new instance of the Complete Binary Tree
    tree = CompleteBinaryTree()

    # Insert values into the tree
    print("Inserting values into the Complete Binary Tree...")
    tree.insert(10)
    tree.insert(20)
    tree.insert(30)
    tree.insert(40)
    tree.insert(50)
    tree.insert(60)
    tree.insert(70)

    # Print the tree's values in level order
    print("\nComplete Binary Tree values (Level Order):")
    tree.print_tree()

    # Search for values in the tree
    print("\n\nSearching for values in the tree...")
    search_values = [30, 100, 50]
    for value in search_values:
        if tree.search(value):
            print(f"Value {value} found in the tree.")
        else:
            print(f"Value {value} not found in the tree.")
