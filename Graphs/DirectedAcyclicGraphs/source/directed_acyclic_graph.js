class DirectedAcyclicGraph {
    constructor() {
        this.graph = {};
        this.vertices = new Set();
    }

    addVertex(vertex) {
        this.vertices.add(vertex);
        if (!this.graph[vertex]) {
            this.graph[vertex] = [];  // Initialize an empty array for the vertex
        }
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
        if (this._hasCycle()) {
            this.graph[source].pop();
            throw Error(`Adding edge ${source} -> ${target} introduces a cycle!`);
        }
    }

    dfsIterative(start_vertex, visited = null, process = null, record_stack = null, detect_cycle = false) {
        if (!visited) {
            visited = new Set();
        }
        const rec_stack = new Set();
        const stack = [start_vertex];

        while (stack.length > 0) {
            const vertex = stack.pop();

            if (!visited.has(vertex)) {
                visited.add(vertex);
                if (detect_cycle) {
                    rec_stack.add(vertex);
                }

                if (process) {
                    process(vertex);
                }

                if (record_stack !== null) {
                    record_stack.unshift(vertex);
                }

                for (const neighbor of (this.graph[vertex] || []).reverse()) {
                    if (detect_cycle && rec_stack.has(neighbor)) {
                        return true;
                    }
                    if (!visited.has(neighbor)) {
                        stack.push(neighbor);
                    }
                }

                if (detect_cycle) {
                    rec_stack.delete(vertex);
                }
            }
        }

        if (detect_cycle) {
            return false;
        }
    }

    _hasCycle() {
        const visited = new Set();
        for (const vertex of this.vertices) {
            if (!visited.has(vertex)) {
                if (this.dfsIterative(vertex, visited, null, null, true)) {
                    return true;
                }
            }
        }
        return false;
    }

    display() {
        for (const vertex of this.vertices) {
            console.log(`${vertex} -> ${this.graph[vertex]}`);
        }
    }
}

module.exports = DirectedAcyclicGraph;
