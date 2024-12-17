from collections import defaultdict


class DFSGraph:
    def __init__(self):
        """
        Initialize the graph with an empty adjacency list.

        Attributes:
            graph (defaultDict): A dictionary where each key is a vertex and the value is a list of adjacent vertices.
            vertices (set): A set containing all vertices in the graph.
        """
        self.graph = defaultdict(list)
        self.vertices = set()

    def add_vertex(self, vertex):
        """
        Add a vertex to the graph.

        Args:
            vertex (str): The vertex to be added.
        """
        self.vertices.add(vertex)

    def add_edge(self, u, v):
        """
        Add a directed edge from vertex u to vertex v. If the vertices do not exist, they are added to the graph.

        Args:
            u (str): The starting vertex of the edge.
            v (str): The ending vertex of the edge.

        Prints:
            str: Confirmation message that the edge was added successfully.
        """
        if u not in self.vertices:
            self.add_vertex(u)
        if v not in self.vertices:
            self.add_vertex(v)

        self.graph[u].append(v)
        print(f"Edge {u} -> {v} added successfully.")

    def dfs(self, start_vertex):
        """
        Perform a Depth-First Search (DFS) traversal starting from the specified vertex.

        Args:
            start_vertex (str): The vertex from which to start the DFS traversal.

        Prints:
            str: The vertices visited during the DFS traversal in the order they are visited.
        """
        visited = set()

        def dfs_recursive(vertex):
            if vertex not in visited:
                visited.add(vertex)
                print(vertex, end=" ")
                for neighbor in self.graph[vertex]:
                    dfs_recursive(neighbor)

        dfs_recursive(start_vertex)
        print()

    def display(self):
        """
        Display the graph as an adjacency list.

        Prints:
            str: Each vertex and its list of adjacent vertices.
        """
        for vertex in self.vertices:
            print(f"{vertex} -> {self.graph[vertex]}")
