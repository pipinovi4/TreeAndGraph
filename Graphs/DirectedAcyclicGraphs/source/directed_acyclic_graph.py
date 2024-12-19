from collections import defaultdict, deque


class DirectedAcyclicGraph:
    """
    A class to represent a Directed Acyclic Graph (DAG) and perform operations like adding edges,
    detecting cycles, performing iterative DFS traversal, and topological sorting.
    """

    def __init__(self):
        """
        Initialize the DAG with an empty adjacency list and a set of vertices.

        Attributes:
            graph (defaultdict): A dictionary where each key is a vertex, and the value is a list of adjacent vertices.
            vertices (set): A set containing all vertices in the graph.
        """
        self.graph = defaultdict(list)  # Adjacency list to store the graph
        self.vertices = set()            # Set to store all unique vertices

    def add_vertex(self, vertex):
        """
        Add a vertex to the DAG.

        Args:
            vertex (str): The vertex to be added.
        """
        self.vertices.add(vertex)

    def add_edge(self, source, target):
        """
        Add a directed edge from the source vertex to the target vertex.

        Ensures that adding the edge does not introduce a cycle. If a cycle is detected,
        the edge is not added, and a ValueError is raised.

        Args:
            source (str): The starting vertex of the edge.
            target (str): The ending vertex of the edge.

        Raises:
            ValueError: If adding the edge introduces a cycle.
        """
        if source not in self.vertices:
            self.add_vertex(source)
        if target not in self.vertices:
            self.add_vertex(target)

        # Temporarily add the edge to check for a cycle
        self.graph[source].append(target)
        if self._has_cycle():
            self.graph[source].pop()  # Remove the edge if a cycle is detected
            raise ValueError(f"Adding edge {source} -> {target} introduces a cycle!")

    def dfs_iterative(self, start_vertex, visited=None, process=None, record_stack=None, detect_cycle=False):
        """
        Perform an iterative Depth-First Search (DFS) traversal starting from the specified vertex.

        This method can be customized to process vertices, record traversal for topological sorting,
        or detect cycles.

        Args:
            start_vertex (str): The vertex from which to start the DFS traversal.
            visited (set, optional): A set to keep track of visited vertices.
            process (function, optional): A function to process each vertex during traversal.
            record_stack (deque, optional): A deque to record vertices for topological sorting.
            detect_cycle (bool, optional): If True, checks for cycles during traversal.

        Returns:
            bool: Returns True if a cycle is detected (when detect_cycle is True), otherwise None.
        """
        if visited is None:
            visited = set()
        rec_stack = set()  # Used only if detect_cycle is True
        stack = [start_vertex]  # Stack to manage DFS traversal

        while stack:
            vertex = stack.pop()

            # Process the vertex if it hasn't been visited
            if vertex not in visited:
                visited.add(vertex)  # Mark the vertex as visited
                if detect_cycle:
                    rec_stack.add(vertex)  # Add to recursion stack for cycle detection

                if process:
                    process(vertex)  # Process the vertex (e.g., print)

                # Append to record_stack for topological sorting
                if record_stack is not None:
                    record_stack.appendleft(vertex)  # Record the vertex in stack

                # Add neighbors to the stack for further traversal
                for neighbor in reversed(self.graph[vertex]):
                    if detect_cycle and neighbor in rec_stack:
                        return True  # Cycle detected
                    if neighbor not in visited:
                        stack.append(neighbor)

                # Remove from recursion stack after processing (for cycle detection)
                if detect_cycle:
                    rec_stack.remove(vertex)

        if detect_cycle:
            return False  # No cycle detected

    def _has_cycle(self):
        """
        Check if the graph contains a cycle using iterative DFS traversal.

        Returns:
            bool: True if a cycle is detected, False otherwise.
        """
        visited = set()
        for vertex in self.vertices:
            if vertex not in visited:
                if self.dfs_iterative(vertex, visited, detect_cycle=True):
                    return True  # Cycle detected
        return False  # No cycle found

    def topological_sort(self):
        """
        Perform a topological sort on the DAG.

        Returns:
            list: A list of vertices in topologically sorted order.
        """
        visited = set()
        stack = deque()  # Stack to store the topological order

        for vertex in self.vertices:
            if vertex not in visited:
                self.dfs_iterative(vertex, visited, record_stack=stack)

        return list(stack)  # Convert the deque to a list and return

    def display(self):
        """
        Display the DAG as an adjacency list.
        """
        for vertex in self.vertices:
            print(f"{vertex} -> {self.graph[vertex]}")
