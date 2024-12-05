from FenwickTrees.source.fenwick_tree import FenwickTree

# Example usage of the FenwickTree class
if __name__ == "__main__":
    # Initialize data for the Fenwick Tree
    data = [3, 2, -1, 6, 5, 4, -3]  # Indexing starts at 0
    print("Initial data:", data)

    # Build a Fenwick Tree from the data
    print("\nBuilding Fenwick Tree...")
    fenwick_tree = FenwickTree.build([0] + data)  # Add dummy 0 for 1-based indexing

    # Query prefix sums
    print("\nQuerying prefix sums:")
    for i in range(1, len(data) + 1):
        print(f"Sum of first {i} elements: {fenwick_tree.query(i)}")

    # Update an element
    print("\nUpdating index 3 (1-based) by adding +4...")
    fenwick_tree.update(3, 4)

    # Query prefix sums after the update
    print("\nQuerying prefix sums after update:")
    for i in range(1, len(data) + 1):
        print(f"Sum of first {i} elements: {fenwick_tree.query(i)}")

    # Perform a range query
    left, right = 2, 5
    print(f"\nSum of elements from index {left} to {right}: {fenwick_tree.range_query(left, right)}")
