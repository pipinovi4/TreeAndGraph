from Graphs.BFSGraphs.source.bfs_graph import BFSGraph


if __name__ == "__main__":
    # Create a graph instance
    graph = BFSGraph()

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

    # Perform BFS starting from vertex 'A'
    print("\nBFS Traversal Starting from Vertex A:")
    graph.bfs("A")

    # Perform BFS starting from vertex 'C'
    print("\nBFS Traversal Starting from Vertex C:")
    graph.bfs("C")

    # Perform BFS starting from vertex 'D'
    print("\nBFS Traversal Starting from Vertex D:")
    graph.bfs("D")

    # Perform BFS starting from a vertex that does not exist
    print("\nBFS Traversal Starting from Vertex Z (Non-Existent):")
    graph.bfs("Z")
