class UndirectedGraph:
    """
    A class to represent an undirected graph using an adjacency list.

    The graph allows adding vertices, adding bidirectional edges, checking if an edge exists,
    and printing the adjacency list.
    """

    def __init__(self):
        """
        Initialize the graph with an empty adjacency list.

        The adjacency list is a dictionary where each key is a vertex,
        and the associated value is a list of neighboring vertices.
        """
        self.adjacency_list = {}

    def add_vertex(self, vertex):
        """
        Add a vertex to the graph if it doesn't already exist.

        :param vertex: The vertex to be added to the graph.
        """
        if vertex not in self.adjacency_list:
            self.adjacency_list[vertex] = []  # Initialize the vertex with an empty list of neighbors

    def add_edge(self, vertex1, vertex2):
        """
        Add an undirected edge between two vertices.

        If the vertices do not exist in the graph, they are added automatically.

        :param vertex1: The first vertex of the edge.
        :param vertex2: The second vertex of the edge.
        """
        # If vertex1 is not present, add it to the graph
        if vertex1 not in self.adjacency_list:
            self.add_vertex(vertex1)
        # If vertex2 is not present, add it to the graph
        if vertex2 not in self.adjacency_list:
            self.add_vertex(vertex2)

        # Add the edge in both directions to represent a bidirectional connection
        self.adjacency_list[vertex1].append(vertex2)
        self.adjacency_list[vertex2].append(vertex1)

    def has_edge(self, source, target):
        """
        Check if an edge exists between the source and target vertices.

        :param source: The starting vertex.
        :param target: The vertex to check if it is a neighbor of the source.
        :return: True if there is an edge between source and target, False otherwise.
        """
        # Use get() to avoid KeyError if the source vertex is not in the graph
        return target in self.adjacency_list.get(source, [])

    def print(self):
        """
        Print the adjacency list of the graph to show the vertices and their neighbors.
        """
        for vertex, neighbors in self.adjacency_list.items():
            print(f"{vertex} : {neighbors}")  # Print each vertex with its list of neighbors