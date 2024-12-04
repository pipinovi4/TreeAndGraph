from BinarySearchTrees.source.binary_search_tree import BinarySearchTree  # Import the BinarySearchTree class

# Initialize the Binary Search Tree
bst = BinarySearchTree()

# Insert values into the BST
values_to_insert = [50, 30, 70, 20, 40, 60, 80]
print(f"Inserting values: {values_to_insert}")
for value in values_to_insert:
    bst.insert(value)

# Print the BST using pre-order traversal
print("\nPre-order traversal after insertions:")
BinarySearchTree.print_tree(bst.root)

# Search for a value in the BST
search_value = 40
print(f"\n\nSearching for value {search_value} in the BST...")
if bst.search(search_value):
    print(f"Value {search_value} found in the BST.")
else:
    print(f"Value {search_value} not found in the BST.")

# Delete a value from the BST
delete_value = 30
print(f"\nDeleting value {delete_value} from the BST...")
bst.delete(delete_value)

# Print the BST using pre-order traversal after deletion
print("\nPre-order traversal after deletion:")
BinarySearchTree.print_tree(bst.root)

# Insert additional values to test further operations
additional_values = [25, 35]
print(f"\nInserting additional values: {additional_values}")
for value in additional_values:
    bst.insert(value)

# Print the BST using pre-order traversal after additional insertions
print("\nPre-order traversal after additional insertions:")
BinarySearchTree.print_tree(bst.root)
