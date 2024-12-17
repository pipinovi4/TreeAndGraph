from collections import defaultdict, deque


class BFSGraph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.vertices = set()

    def add_vertex(self, vertex):
        self.vertices.add(vertex)

    def add_edge(self, source, target):
        if source not in self.vertices:
            self.vertices.add(source)
        if target not in self.vertices:
            self.vertices.add(target)

        self.graph[source].append(target)

    def bfs(self, start_vertex):
        if start_vertex not in self.vertices:
            print(f"Vertex '{start_vertex}' does not exist in the graph.")
            return

        visited = set()
        queue = deque([start_vertex])

        while queue:
            current_vertex = queue.popleft()

            if current_vertex not in visited:
                visited.add(current_vertex)
                print(current_vertex, end=" ")

                for neighbor in self.graph[current_vertex]:
                    if neighbor not in visited:
                        queue.append(neighbor)

        print()

    def display(self):
        for vertex in self.vertices:
            print(f"{vertex} -> {self.graph[vertex]}")
