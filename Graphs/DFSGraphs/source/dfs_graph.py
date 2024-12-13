from collections import defaultdict, deque


class DFSGraph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.vertices = set()

    def add_vertex(self, vertex):
        self.vertices.add(vertex)

    def add_edge(self, u, v):
        if u not in self.vertices:
            self.add_vertex(u)
        if v not in self.vertices:
            self.add_vertex(v)

        self.graph[u].append(v)

    def dfs(self, vertex):
        visited = set()
        stack = deque()
        stack.append(vertex)

        while len(vertex) != 0:
            current_vertex = stack.pop()
            if current_vertex not in visited:
                visited.add(current_vertex)
                for neighbor in self.graph[current_vertex]:
                    stack.append(neighbor)

    def display(self):
        for vertex in self.vertices:
            print(f"{vertex} -> {self.graph[vertex]}")
