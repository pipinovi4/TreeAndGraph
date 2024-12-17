class DFSGraph {
    constructor() {
        this.graph = {};
        this.vertices = new Set();
    }

    addVertex(vertex) {
        this.vertices.add(vertex);
    }

    addEdge(source, target) {
        if (!this.vertices.has(source)) {
            this.addVertex(source);
        }
        if (!this.vertices.has(target)) {
            this.addVertex(target);
        }

        if (!this.graph[source]) {
            this.graph[source] = [];
        }
        this.graph[source].push(target);
    }

    dfs(startVertex) {
        const visited = new Set();
        const stack = [startVertex];
        const result = []; // Array to collect the visited vertices

        while (stack.length > 0) {
            const currentVertex = stack.pop();
            if (!visited.has(currentVertex)) {
                visited.add(currentVertex);
                result.push(currentVertex); // Collect the vertex

                for (let i = (this.graph[currentVertex] || []).length - 1; i >= 0; i--) {
                    const neighbor = this.graph[currentVertex][i];
                    if (!visited.has(neighbor)) {
                        stack.push(neighbor);
                    }
                }
            }
        }

        console.log(result.join(" "));
    }

    display() {
        for (const vertex of this.vertices) {
            console.log(`${vertex} -> ${this.graph[vertex] ? this.graph[vertex].join(", ") : ""}`);
        }
    }
}

module.exports = DFSGraph;
