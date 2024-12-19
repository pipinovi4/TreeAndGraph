const DirectedAcyclicGraph = require('../source/directed_acyclic_graph');

const dag = new DirectedAcyclicGraph();

try {
    // Add edges to the graph
    dag.addEdge("A", "B");
    dag.addEdge("A", "C");
    dag.addEdge("B", "D");
    dag.addEdge("C", "D");
    dag.addEdge("D", "E");
    dag.addEdge("E", "F");

    // Uncommenting the line below will raise an error due to cycle detection
    // dag.addEdge("F", "A");

} catch (error) {
    console.error(error.message);
}

// Display the adjacency list of the graph
console.log("\nDAG Adjacency List:");
dag.display();

// Perform iterative DFS starting from vertex 'A'
console.log("\nDFS Traversal Starting from Vertex A:");
dag.dfsIterative("A", null, (vertex) => process.stdout.write(vertex + " "));
console.log();

// Perform iterative DFS starting from vertex 'C'
console.log("\nDFS Traversal Starting from Vertex C:");
dag.dfsIterative("C", null, (vertex) => process.stdout.write(vertex + " "));
console.log();
