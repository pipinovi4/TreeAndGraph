class BFSGraph {
    /**
     * Class representing a directed graph with Breadth-First Search (BFS) functionality.
     *
     * Attributes:
     *     graph (Object): Stores the adjacency list of the graph where each key is a vertex and the value is an array of adjacent vertices.
     *     vertices (Set): A set containing all the vertices in the graph to ensure uniqueness.
     */
    constructor() {
        this.graph = {};            // Initialize an empty object to store the adjacency list.
        this.vertices = new Set();  // Initialize an empty set to store the vertices.
    }

    /**
     * Add a vertex to the graph.
     *
     * @param {string} vertex - The vertex to be added.
     */
    addVertex(vertex) {
        this.vertices.add(vertex);  // Add the vertex to the set of vertices.
    }

    /**
     * Add a directed edge from the source vertex to the target vertex.
     *
     * If the vertices do not exist, they are added to the graph automatically.
     *
     * @param {string} source - The starting vertex of the edge.
     * @param {string} target - The ending vertex of the edge.
     */
    addEdge(source, target) {
        // Add the source vertex if it does not exist.
        if (!this.vertices.has(source)) {
            this.addVertex(source);
        }

        // Add the target vertex if it does not exist.
        if (!this.vertices.has(target)) {
            this.addVertex(target);
        }

        // Initialize an empty array for the source vertex if it does not have an entry in the graph.
        if (!this.graph[source]) {
            this.graph[source] = [];
        }

        // Add the target vertex to the adjacency list of the source vertex.
        this.graph[source].push(target);
    }

    /**
     * Perform a Breadth-First Search (BFS) traversal starting from the specified vertex.
     *
     * @param {string} startVertex - The vertex from which to start the BFS traversal.
     *
     * Prints:
     *     The vertices visited during the BFS traversal in the order they are visited.
     */
    bfs(startVertex) {
        // Check if the start vertex exists in the graph.
        if (!this.vertices.has(startVertex)) {
            console.log(`Vertex ${startVertex} does not exist in the graph`);
            return;
        }

        const visited = new Set();       // Set to track visited vertices.
        const queue = [startVertex];     // Queue to manage the BFS traversal.

        // Continue until the queue is empty.
        while (queue.length !== 0) {
            // Dequeue the first vertex in the queue.
            const currentVertex = queue.shift();

            // Process the vertex if it hasn't been visited yet.
            if (!visited.has(currentVertex)) {
                visited.add(currentVertex);  // Mark the vertex as visited.
                process.stdout.write(currentVertex + " ");  // Print the current vertex.

                // Ensure that the current vertex has an entry in the graph to avoid undefined errors.
                for (const neighbor of this.graph[currentVertex] || []) {
                    // Add unvisited neighbors to the queue.
                    if (!visited.has(neighbor)) {
                        queue.push(neighbor);
                    }
                }
            }
        }

        process.stdout.write("\n");  // Print a newline after traversal is complete.
    }

    /**
     * Display the graph as an adjacency list.
     *
     * Prints:
     *     Each vertex and its list of adjacent vertices.
     */
    display() {
        for (const vertex of this.vertices) {
            console.log(`${vertex} -> ${this.graph[vertex] || []}`);  // Print each vertex and its neighbors.
        }
    }
}

module.exports = BFSGraph;
