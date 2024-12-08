from Treaps.source.treap import Treap

if __name__ == "__main__":
    # Initialize a new Treap
    treap = Treap()

    # Insert elements into the Treap
    print("Inserting elements into the Treap...")
    treap.insert(10)
    treap.insert(20)
    treap.insert(5)
    treap.insert(15)

    # Perform an in-order traversal and print the result
    print("\nIn-order traversal after insertions:")
    for node in treap.inorder():
        print(f"({node[0]}, {node[1]})", end=" ")
    print()

    # Search for a value in the Treap
    search_value = 15
    print(f"\nSearch for {search_value}: {'Found' if treap.search(search_value) else 'Not Found'}")

    # Search for a non-existing value
    non_existing_value = 25
    print(f"Search for {non_existing_value}: {'Found' if treap.search(non_existing_value) else 'Not Found'}")

    # Delete a value from the Treap
    delete_value = 20
    print(f"\nDeleting {delete_value}...")
    treap.delete(delete_value)

    # Perform an in-order traversal after deletion and print the result
    print("\nIn-order traversal after deletion:")
    for node in treap.inorder():
        print(f"({node[0]}, {node[1]})", end=" ")
    print()

    # Insert more elements into the Treap
    treap.insert(25)
    treap.insert(30)

    # Perform an in-order traversal after more insertions and print the result
    print("\nIn-order traversal after more insertions:")
    for node in treap.inorder():
        print(f"({node[0]}, {node[1]})", end=" ")
    print()

    # Print the Treap structure for debugging
    print("\nTreap structure:")
    treap.print_tree()
    print(treap.inorder())
