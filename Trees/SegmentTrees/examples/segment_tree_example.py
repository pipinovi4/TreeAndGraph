# Import the SegmentTree class
from Trees.SegmentTrees.source.segment_tree import SegmentTree

# Example usage
if __name__ == "__main__":
    # Sample data array
    data = [1, 3, 5, 7, 9, 11]

    # Initialize the Segment Tree for range sum queries
    seg_tree_sum = SegmentTree(data, func=sum, identity=0)

    # Perform range queries
    print("Sum of range [1, 4):", seg_tree_sum.query(1, 4))  # Query sum from index 1 to 3
    print("Sum of range [0, 6):", seg_tree_sum.query(0, 6))  # Query sum for the entire array

    # Update an element
    seg_tree_sum.update(2, 10)  # Update index 2 to the value 10

    # Perform range queries after update
    print("Sum of range [1, 4) after update:", seg_tree_sum.query(1, 4))
    print("Sum of range [0, 6) after update:", seg_tree_sum.query(0, 6))

    # Example with min query
    seg_tree_min = SegmentTree(data, func=min, identity=float('inf'))
    print("Minimum in range [1, 4):", seg_tree_min.query(1, 4))  # Query minimum from index 1 to 3

    # Example with max query
    seg_tree_max = SegmentTree(data, func=max, identity=float('-inf'))
    print("Maximum in range [1, 4):", seg_tree_max.query(1, 4))  # Query maximum from index 1 to 3
