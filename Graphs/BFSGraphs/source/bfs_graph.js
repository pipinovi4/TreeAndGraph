class BFSGraph {
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

    bfs(startVertex) {
        if (!this.vertices.has(startVertex)) {
            console.log(`Vertex ${startVertex} does not exist in the graph`);
            return;
        }

        const visited = new Set();
        const queue = [startVertex];

        while (queue.length !== 0) {
            const currenVertex = queue.shift();

            if (!visited.has(currenVertex)) {
                visited.add(currenVertex);
                process.stdout.write(currenVertex + " ");

                for (const neighbor of this.graph[currenVertex]) {
                    if (!visited.has((neighbor))) {
                        queue.push(neighbor);
                    }
                }
            }
        }
        process.stdout.write("\n");
    }

    display() {
        for (const vertex of this.vertices) {
            console.log(`${vertex} -> ${this.graph[vertex]}`)
        }
    }
}


module.exports = BFSGraph;