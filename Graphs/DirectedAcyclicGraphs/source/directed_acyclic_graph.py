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

    def dfs_iterative(self, start_vertex, visited=None, process=None, record_stack=None, detect_cycle=False):
        if visited is None:
            visited = set()
        rec_stack = set()  # Used only if detect_cycle is True
        stack = [start_vertex]

        while stack:
            vertex = stack.pop()

            if vertex not in visited:
                visited.add(vertex)  # Mark vertex as visited
                if detect_cycle:
                    rec_stack.add(vertex)

                if process:
                    process(vertex)

                # Append to record_stack for topological sort
                if record_stack is not None:
                    record_stack.appendleft(vertex)

                # Add neighbors to the stack for further traversal
                for neighbor in reversed(self.graph[vertex]):
                    if detect_cycle and neighbor in rec_stack:
                        return True
                    if neighbor not in visited:
                        stack.append(neighbor)

                if detect_cycle:
                    rec_stack.remove(vertex)  # Remove from recursion stack after processing

        if detect_cycle:
            return False

    def _has_cycle(self):
        visited = set()
        for vertex in self.vertices:
            if vertex not in visited:
                if self.dfs_iterative(vertex, visited, detect_cycle=True):
                    return True
        return False

    def topological_sort(self):
        visited = set()
        stack = deque()

        for vertex in self.vertices:
            if vertex not in visited:
                self.dfs_iterative(vertex, visited, record_stack=stack)

        return list(stack)

    def display(self):
        for vertex in self.vertices:
            print(f"{vertex} -> {self.graph[vertex]}")
