from Graphs.DirectedAcyclicGraphs.source.directed_acyclic_graph import DirectedAcyclicGraph

if __name__ == "__main__":
    # Create an instance of DirectedAcyclicGraph
    dag = DirectedAcyclicGraph()

    try:
        # Add edges to the DAG
        dag.add_edge("A", "B")
        dag.add_edge("A", "C")
        dag.add_edge("B", "D")
        dag.add_edge("C", "D")
        dag.add_edge("D", "E")
        dag.add_edge("E", "F")

        # Attempt to add an edge that would introduce a cycle
        # Uncommenting the line below will raise a ValueError
        # dag.add_edge("F", "A")

    except ValueError as e:
        print(e)

    # Display the adjacency list of the graph
    print("\nDAG Adjacency List:")
    dag.display()

    # Perform topological sorting
    print("\nTopological Sort:")
    print(dag.topological_sort())

    # Perform iterative DFS traversal starting from vertex 'A'
    print("\nDFS Traversal Starting from Vertex A:")
    dag.dfs_iterative("A", process=lambda v: print(v, end=" "))
    print()

    # Perform iterative DFS traversal starting from vertex 'C'
    print("\nDFS Traversal Starting from Vertex C:")
    dag.dfs_iterative("C", process=lambda v: print(v, end=" "))
    print()
