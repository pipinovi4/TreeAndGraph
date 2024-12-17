const BFSGraph = require('../source/bfs_graph');

const graph = new BFSGraph();

// Adding edges to the graph
graph.addEdge("A", "B");
graph.addEdge("A", "C");
graph.addEdge("B", "D");
graph.addEdge("C", "D");
graph.addEdge("D", "E");
graph.addEdge("E", "F");
graph.addEdge("C", "F");

// Display the graph structure
console.log("\nGraph Adjacency List:");
graph.display();

// Perform BFS starting from vertex 'A'
console.log("\nBFS Traversal Starting from Vertex A:");
graph.bfs("A");

// Perform BFS starting from vertex 'C'
console.log("\nBFS Traversal Starting from Vertex C:");
graph.bfs("C");

// Perform BFS starting from vertex 'D'
console.log("\nBFS Traversal Starting from Vertex D:");
graph.bfs("D");

// Perform BFS starting from a non-existent vertex 'Z'
console.log("\nBFS Traversal Starting from Vertex Z (Non-Existent):");
graph.bfs("Z");
