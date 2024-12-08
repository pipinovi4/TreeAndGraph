from Trees.BPTrees.source.b_plus_tree import BPTree

# Initialize a B+ Tree with a minimum degree of 3
bpt = BPTree(3)

# Insert keys into the B+ Tree
keys_to_insert = [10, 20, 5, 6, 12, 30, 7, 17]
print(f"Inserting keys: {keys_to_insert}")
for key in keys_to_insert:
    bpt.insert(key)

# Print the B+ Tree structure after insertions
print("\nB+ Tree structure after insertions:")
bpt.print_tree()

# Search for a specific key in the B+ Tree
key_to_search = 12
print(f"\nSearching for key {key_to_search}...")
search_result = bpt.search(key_to_search)
if search_result:
    print(f"Key {key_to_search} found in the B+ Tree.")
else:
    print(f"Key {key_to_search} not found in the B+ Tree.")

# Perform a range query
start_key = 6
end_key = 17
print(f"\nPerforming range query for keys between {start_key} and {end_key}...")
range_result = bpt.range_query(start_key, end_key)
print(f"Keys in range [{start_key}, {end_key}]: {range_result}")

# Delete a key from the B+ Tree
key_to_delete = 6
print(f"\nDeleting key {key_to_delete} from the B+ Tree...")
bpt.delete(key_to_delete)

# Print the B+ Tree structure after deletion
print("\nB+ Tree structure after deletion:")
bpt.print_tree()
