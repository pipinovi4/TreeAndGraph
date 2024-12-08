from Trees.BTrees.source.b_tree import BTree

if __name__ == "__main__":
    # Initialize a B-Tree with minimum degree t = 3
    b_tree = BTree(3)

    # Insert keys into the B-Tree
    print("Inserting keys...")
    for key in [10, 20, 5, 6, 12, 30, 7, 17]:
        b_tree.insert(key)

    # Print the B-Tree structure
    print("\nB-Tree structure after insertion:")
    b_tree.print_tree()

    # Search for some keys
    print("\nSearching for keys...")
    search_keys = [6, 15, 30]
    for key in search_keys:
        result = b_tree.search(key)
        if result:
            print(f"Key {key} found in node: {result.keys}")
        else:
            print(f"Key {key} not found in the B-Tree.")

    # Delete keys from the B-Tree
    print("\nDeleting keys...")
    for key in [6, 20, 30]:
        b_tree.remove(key)
        print(f"Deleted key {key}:")
        b_tree.print_tree()

    # Range Query Example
    print("\nRange query for keys between 7 and 17:")
    print(b_tree.range_query(7, 17))
