class UndirectedGraph:
    def __init__(self):
        self.adjacency_list = {}

    def add_vertex(self, vertex):
        if vertex not in self.adjacency_list:
            self.adjacency_list[vertex] = []

    def add_edge(self, vertex1, vertex2):
        if vertex1 not in self.adjacency_list:
            self.add_vertex(vertex1)
        if vertex2 not in self.adjacency_list:
            self.add_edge(vertex2)

        # Add the edge in both directions (bidirectional)
        self.adjacency_list[vertex1].append(vertex2)
        self.adjacency_list[vertex2].append(vertex1)

    def has_edge(self, source, target):
        return target in self.adjacency_list.get(source, [])

    def print(self):
        for vertex, neighbors in self.adjacency_list.items():
            print(f"{vertex} : {neighbors}")
