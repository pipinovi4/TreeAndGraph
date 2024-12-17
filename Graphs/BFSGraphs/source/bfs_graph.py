from collections import defaultdict, deque


class BFSGraph:
    """
    A class to represent a directed graph and perform Breadth-First Search (BFS) traversal.

    Attributes:
        graph (defaultdict): Stores the adjacency list of the graph.
        vertices (set): A set containing all the vertices in the graph.
    """

    def __init__(self):
        """
        Initialize the graph with an empty adjacency list and an empty set of vertices.
        """
        self.graph = defaultdict(list)  # Adjacency list to store the graph.
        self.vertices = set()            # Set to store all the vertices in the graph.

    def add_vertex(self, vertex):
        """
        Add a vertex to the graph if it doesn't already exist.

        Args:
            vertex (str): The vertex to be added.
        """
        self.vertices.add(vertex)  # Add the vertex to the set of vertices.

    def add_edge(self, source, target):
        """
        Add a directed edge from the source vertex to the target vertex.

        If the vertices do not exist, they are added to the graph automatically.

        Args:
            source (str): The starting vertex of the edge.
            target (str): The ending vertex of the edge.
        """
        # Ensure both the source and target vertices exist in the graph.
        if source not in self.vertices:
            self.add_vertex(source)
        if target not in self.vertices:
            self.add_vertex(target)

        # Add the target to the adjacency list of the source vertex.
        self.graph[source].append(target)

    def bfs(self, start_vertex):
        """
        Perform a Breadth-First Search (BFS) traversal starting from the specified vertex.

        Args:
            start_vertex (str): The vertex from which to start the BFS traversal.

        Prints:
            The vertices visited during the BFS traversal in the order they are visited.
        """
        if start_vertex not in self.vertices:
            print(f"Vertex '{start_vertex}' does not exist in the graph.")
            return

        visited = set()             # Set to keep track of visited vertices.
        queue = deque([start_vertex])  # Queue to manage the BFS traversal.

        while queue:
            # Dequeue the first vertex in the queue.
            current_vertex = queue.popleft()

            # If the vertex hasn't been visited, process it.
            if current_vertex not in visited:
                visited.add(current_vertex)  # Mark the vertex as visited.
                print(current_vertex, end=" ")  # Print the current vertex.

                # Enqueue all unvisited neighbors of the current vertex.
                for neighbor in self.graph[current_vertex]:
                    if neighbor not in visited:
                        queue.append(neighbor)

        print()  # Print a newline after traversal is complete.

    def display(self):
        """
        Display the graph as an adjacency list.

        Prints:
            Each vertex and its list of adjacent vertices.
        """
        for vertex in self.vertices:
            print(f"{vertex} -> {self.graph[vertex]}")  # Print each vertex and its neighbors.
