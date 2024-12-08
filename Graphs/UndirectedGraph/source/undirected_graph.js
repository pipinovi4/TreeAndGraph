class UndirectedGraph {
    constructor() {
        this.adjacencyList = {};
    }

    addVertex(vertex) {
        if (!this.adjacencyList[vertex]) {
            this.adjacencyList[vertex] = [];
        }
    }

    addEdge(vertex1, vertex2) {
        if (!this.adjacencyList[vertex1]) {
            this.addVertex(vertex1);
        }
        if (!this.adjacencyList[vertex2]) {
            this.addVertex(vertex2);
        }

        this.adjacencyList[vertex1].push(vertex2);
        this.adjacencyList[vertex2].push(vertex1);
    }

    hasEdge(source, target) {
        return this.adjacencyList[source]?.includes(target) || false;
    }

    print() {
        for (const [vertex, neighbors] of Object.entries(this.adjacencyList)) {
            console.log(vertex, " : ", neighbors);
        }
    }
}