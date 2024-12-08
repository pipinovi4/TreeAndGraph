from Trees.SplayTrees.source.splay_tree import SplayTree  # Assuming the SplayTree class is saved in `splay_tree.py`

# Initialize a new Splay Tree
tree = SplayTree()

# Insert elements into the tree
tree.insert(10)
tree.insert(20)
tree.insert(5)
tree.insert(15)

# Perform an in-order traversal and print the result
print("In-order traversal after insertions:", tree.inorder())

# Search for a value
search_value = 15
found = tree.search(search_value)
print(f"Search for {search_value}: {'Found' if found else 'Not Found'}")

# Search for a non-existing value
non_existing_value = 25
not_found = tree.search(non_existing_value)
print(f"Search for {non_existing_value}: {'Found' if not_found else 'Not Found'}")

# Delete a value from the tree
delete_value = 20
print(f"Deleting {delete_value}...")
tree.delete(delete_value)

# Perform an in-order traversal after deletion and print the result
print("In-order traversal after deletion:", tree.inorder())

# Insert more elements
tree.insert(25)
tree.insert(30)

# Perform an in-order traversal and print the result
print("In-order traversal after more insertions:", tree.inorder())
