from Graphs.TreeGraphs.source.tree_graph import TreeGraph

if __name__ == "__main__":
    # Create a tree graph with root "A"
    tree = TreeGraph("A")

    # Add nodes to the tree
    tree.add_node("A", "B")
    tree.add_node("A", "C")
    tree.add_node("B", "D")
    tree.add_node("B", "E")
    tree.add_node("C", "F")
    tree.add_node("F", "G")

    # Display the tree structure
    print("Tree Structure:")
    tree.display()

    # Perform different tree traversals
    print("\nIn-order Traversal:")
    tree.traversal_in_order()

    print("\n\nPre-order Traversal:")
    tree.traversal_pre_order()

    print("\n\nPost-order Traversal:")
    tree.traverse_post_order()
    print("\n")
