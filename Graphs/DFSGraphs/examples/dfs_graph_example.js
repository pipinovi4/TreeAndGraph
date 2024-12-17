const DFSGraph = require('../source/dfs_graph');

const graph = new DFSGraph();

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

// Perform DFS starting from vertex 'A'
console.log("\nDFS Traversal Starting from Vertex A:");
graph.dfs("A");

// Perform DFS starting from vertex 'C'
console.log("\nDFS Traversal Starting from Vertex C:");
graph.dfs("C");

// Perform DFS starting from vertex 'D'
console.log("\nDFS Traversal Starting from Vertex D:");
graph.dfs("D");
