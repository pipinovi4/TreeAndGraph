from collections import defaultdict, deque

class DirectedAcyclicGraph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.vertices = set()
