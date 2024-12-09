from Graphs.DirectedGraphs.source.directed_graph import DirectedGraph

if __name__ == "__main__":
    # Create a directed graph
    graph = DirectedGraph()

    # Add vertices to the graph
    graph.add_vertex('A')
    graph.add_vertex('B')
    graph.add_vertex('C')
    graph.add_vertex('D')

    # Add directed edges between vertices
    graph.add_edge('A', 'B')  # A -> B
    graph.add_edge('A', 'C')  # A -> C
    graph.add_edge('B', 'D')  # B -> D
    graph.add_edge('C', 'D')  # C -> D

    # Print the graph's adjacency list
    print("Graph Adjacency List:")
    graph.print()

    # Check if specific edges exist
    print("\nChecking if edges exist:")
    print(f"Does an edge exist from A to B? {'Yes' if graph.has_edge('A', 'B') else 'No'}")
    print(f"Does an edge exist from A to D? {'Yes' if graph.has_edge('A', 'D') else 'No'}")
    print(f"Does an edge exist from B to D? {'Yes' if graph.has_edge('B', 'D') else 'No'}")
    print(f"Does an edge exist from C to D? {'Yes' if graph.has_edge('C', 'D') else 'No'}")
