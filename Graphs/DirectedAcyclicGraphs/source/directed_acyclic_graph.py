from collections import defaultdict, deque


class DirectedAcyclicGraph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.vertices = set()

    def add_vertex(self, vertex):
        self.vertices.add(vertex)

    def add_edge(self, source, target):
        if source not in self.vertices:
            self.add_vertex(source)
        if target not in self.vertices:
            self.add_vertex(target)

        self.graph[source].append(target)
        if self._has_cycle():
            self.graph[source].pop()
            raise ValueError(f"Adding edge {source} -> {target} introduces a cycle!")

    def dfs_iterative(self, start_vertex, process=None, record_stack=None, detect_cycle=False):
        visited = set()
        rec_stack = set()
        stack = [(start_vertex, 0)]

        while stack:
            vertex, neighbor_index = stack[-1]

            if vertex not in visited:
                visited.add(vertex)
                if detect_cycle:
                    rec_stack.add(vertex)
                if process:
                    process(vertex)

            neighbors = self.graph[vertex]

            if neighbor_index >= len(neighbors):
                if record_stack:
                    record_stack.appendleft(vertex)
                if detect_cycle:
                    rec_stack.remove(vertex)
                stack.pop()
                continue

            neighbor = neighbors[neighbor_index]
            stack[-1] = (vertex, neighbor_index + 1)

            if detect_cycle and neighbor in rec_stack:
                return True

            if neighbor not in visited:
                stack.append((neighbor, 0))

        if detect_cycle:
            return False

    def _has_cycle(self):
        for vertex in self.vertices:
            if self.dfs_iterative(vertex, detect_cycle=True):
                return True
        return False

    def topological_sort(self):
        visited = set()
        stack = deque()

        for vertex in self.vertices:
            if vertex not in visited:
                self.dfs_iterative(vertex, record_stack=stack)

        return list(stack)

    def display(self):
        for vertex in self.vertices:
            print(f"{vertex} -> {self.graph[vertex]}")