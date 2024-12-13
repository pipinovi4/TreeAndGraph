from Graphs.DFSGraphs.source.dfs_graph import DFSGraph


if __name__ == "__main__":
    # Create an instance of the DFSGraph
    graph = DFSGraph()

    # Add edges to the graph
    graph.add_edge("A", "B")
    graph.add_edge("A", "C")
    graph.add_edge("B", "D")
    graph.add_edge("C", "D")
    graph.add_edge("D", "E")
    graph.add_edge("E", "F")
    graph.add_edge("C", "F")

    # Display the graph structure
    print("\nGraph Adjacency List:")
    graph.display()

    # Perform DFS starting from vertex 'A'
    print("\nDFS Traversal Starting from Vertex A:")
    graph.dfs("A")

    # Perform DFS starting from vertex 'C'
    print("\nDFS Traversal Starting from Vertex C:")
    graph.dfs("C")

    # Perform DFS starting from vertex 'D'
    print("\nDFS Traversal Starting from Vertex D:")
    graph.dfs("D")