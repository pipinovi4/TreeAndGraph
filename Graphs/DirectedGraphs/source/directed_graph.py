class DirectedGraph:
    """
    A class to represent a directed graph using an adjacency list.

    The graph allows adding vertices, adding directed edges, checking if an edge exists,
    and printing the adjacency list.
    """

    def __init__(self):
        """
        Initialize the graph with an empty adjacency list.

        The adjacency list is a dictionary where each key is a vertex,
        and the associated value is a list of neighboring vertices (outgoing edges).
        """
        self.adjacency_list = {}

    def add_vertex(self, vertex):
        """
        Add a vertex to the graph if it doesn't already exist.

        :param vertex: The vertex to be added to the graph.
        """
        if vertex not in self.adjacency_list:
            self.adjacency_list[vertex] = []  # Initialize the vertex with an empty list of neighbors

    def add_edge(self, source, target):
        """
        Add a directed edge from the source vertex to the target vertex.

        If the vertices do not exist in the graph, they are added automatically.

        :param source: The source vertex of the edge.
        :param target: The target vertex of the edge.
        """
        # If source is not present, add it to the graph
        if source not in self.adjacency_list:
            self.add_vertex(source)
        # If target is not present, add it to the graph
        if target not in self.adjacency_list:
            self.add_vertex(target)

        # Add the edge only from source to target to represent a directed connection
        self.adjacency_list[source].append(target)

    def has_edge(self, source, target):
        """
        Check if a directed edge exists from the source to the target vertex.

        :param source: The starting vertex.
        :param target: The vertex to check if it is a neighbor of the source.
        :return: True if there is a directed edge from source to target, False otherwise.
        """
        # Use get() to avoid KeyError if the source vertex is not in the graph
        return target in self.adjacency_list.get(source, [])

    def print(self):
        """
        Print the adjacency list of the graph to show the vertices and their outgoing edges.
        """
        for vertex, neighbors in self.adjacency_list.items():
            print(f"{vertex} : {neighbors}")  # Print each vertex with its list of neighbors
