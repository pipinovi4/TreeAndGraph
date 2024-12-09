/**
 * @class DirectedGraph
 * @description A class to represent a directed graph using an adjacency list.
 *
 * The graph allows adding vertices, adding directed edges, checking if an edge exists,
 * and printing the adjacency list.
 */
class DirectedGraph {
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
     * Adds a directed edge from the source vertex to the target vertex.
     * If the vertices do not exist, they are added automatically.
     *
     * @param {string} source - The source vertex of the edge.
     * @param {string} target - The target vertex of the edge.
     */
    addEdge(source, target) {
        // Add source if it doesn't exist.
        if (!this.adjacencyList[source]) {
            this.addVertex(source);
        }
        // Add target if it doesn't exist.
        if (!this.adjacencyList[target]) {
            this.addVertex(target);
        }

        // Add the edge in one direction (from source to target).
        this.adjacencyList[source].push(target);
    }

    /**
     * @method hasEdge
     * Checks if there is a directed edge from the source vertex to the target vertex.
     *
     * @param {string} source - The source vertex.
     * @param {string} target - The target vertex to check.
     * @returns {boolean} - True if a directed edge exists, otherwise false.
     */
    hasEdge(source, target) {
        // Check if the source vertex exists and if the target is in its neighbors list.
        return this.adjacencyList[source]?.includes(target) || false;
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

module.exports = DirectedGraph;