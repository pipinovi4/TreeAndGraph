/**
 * @class UndirectedGraph
 * @description A class to represent an undirected graph using an adjacency list.
 *
 * The graph allows adding vertices, adding bidirectional edges, checking if an edge exists,
 * and printing the adjacency list.
 */
class UndirectedGraph {
    /**
     * @constructor
     * Initializes an empty adjacency list to store graph edges.
     */
    constructor() {
        this.adjacencyList = {}; // The adjacency list to store vertices and their neighbors.
    }

    /**
     * @method addVertex
     * Adds a vertex to the graph if it doesn't already exist.
     *
     * @param {string} vertex - The vertex to be added to the graph.
     */
    addVertex(vertex) {
        if (!this.adjacencyList[vertex]) {
            this.adjacencyList[vertex] = []; // Initialize the vertex with an empty array of neighbors.
        }
    }

    /**
     * @method addEdge
     * Adds an undirected edge between two vertices. If the vertices do not exist, they are added automatically.
     *
     * @param {string} vertex1 - The first vertex of the edge.
     * @param {string} vertex2 - The second vertex of the edge.
     */
    addEdge(vertex1, vertex2) {
        // Add vertex1 if it doesn't exist.
        if (!this.adjacencyList[vertex1]) {
            this.addVertex(vertex1);
        }
        // Add vertex2 if it doesn't exist.
        if (!this.adjacencyList[vertex2]) {
            this.addVertex(vertex2);
        }

        // Add the edge in both directions to represent a bidirectional connection.
        this.adjacencyList[vertex1].push(vertex2);
        this.adjacencyList[vertex2].push(vertex1);
    }

    /**
     * @method hasEdge
     * Checks if there is an edge between the source vertex and the target vertex.
     *
     * @param {string} source - The source vertex.
     * @param {string} target - The target vertex to check.
     * @returns {boolean} - True if an edge exists, otherwise false.
     */
    hasEdge(source, target) {
        // Check if the source vertex exists and if the target is in its neighbors list.
        return this.adjacencyList[source].includes(target) || false;
    }

    /**
     * @method print
     * Prints the adjacency list of the graph to show the vertices and their neighbors.
     */
    print() {
        // Iterate through each vertex and print its neighbors.
        for (const [vertex, neighbors] of Object.entries(this.adjacencyList)) {
            console.log(`${vertex} : ${neighbors}`);
        }
    }
}

module.exports = UndirectedGraph;