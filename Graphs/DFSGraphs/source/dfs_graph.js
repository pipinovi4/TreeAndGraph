/**
 * Class representing a directed graph with Depth-First Search (DFS) functionality.
 */
class DFSGraph {
    /**
     * Initialize the graph with an empty adjacency list and a set of vertices.
     *
     * @property {Object} graph - A dictionary where each key is a vertex, and the value is an array of adjacent vertices.
     * @property {Set} vertices - A set containing all vertices in the graph.
     */
    constructor() {
        this.graph = {};
        this.vertices = new Set();
    }

    /**
     * Add a vertex to the graph.
     *
     * @param {string} vertex - The vertex to be added.
     */
    addVertex(vertex) {
        this.vertices.add(vertex);
    }

    /**
     * Add a directed edge from the source vertex to the target vertex.
     * If the vertices do not exist, they are added to the graph.
     *
     * @param {string} source - The starting vertex of the edge.
     * @param {string} target - The ending vertex of the edge.
     */
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

    /**
     * Perform a Depth-First Search (DFS) traversal starting from the specified vertex.
     * Uses an iterative approach with a stack to avoid recursion.
     *
     * @param {string} startVertex - The vertex from which to start the DFS traversal.
     * @returns {void}
     *
     * @example
     * graph.dfs("A");
     * // Output: A B D E F C
     */
    dfs(startVertex) {
        const visited = new Set();
        const stack = [startVertex];
        const result = []; // Array to collect the visited vertices

        while (stack.length > 0) {
            const currentVertex = stack.pop();
            if (!visited.has(currentVertex)) {
                visited.add(currentVertex);
                result.push(currentVertex); // Collect the vertex

                // Add neighbors in reverse order to maintain order of traversal
                for (let i = (this.graph[currentVertex] || []).length - 1; i >= 0; i--) {
                    const neighbor = this.graph[currentVertex][i];
                    if (!visited.has(neighbor)) {
                        stack.push(neighbor);
                    }
                }
            }
        }

        // Print all the visited vertices in one row
        console.log(result.join(" "));
    }

    /**
     * Display the graph as an adjacency list.
     *
     * @returns {void}
     *
     * @example
     * graph.display();
     * // Output:
     * // A -> B, C
     * // B -> D
     * // C -> D, F
     */
    display() {
        for (const vertex of this.vertices) {
            console.log(`${vertex} -> ${this.graph[vertex] ? this.graph[vertex].join(", ") : ""}`);
        }
    }
}

module.exports = DFSGraph;
