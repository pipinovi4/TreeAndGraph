const UndirectedGraph = require('../source/undirected_graph');

// Create an undirected graph
const graph = new UndirectedGraph();

// Add vertices to the graph
graph.addVertex('A');
graph.addVertex('B');
graph.addVertex('C');
graph.addVertex('D');

// Add edges between vertices
graph.addEdge('A', 'B');  // A -- B
graph.addEdge('A', 'C');  // A -- C
graph.addEdge('B', 'D');  // B -- D
graph.addEdge('C', 'D');  // C -- D

// Print the graph's adjacency list
console.log('Graph Adjacency List:');
graph.print();

// Check if specific edges exist
console.log('\nChecking if edges exist:');
console.log(`Does an edge exist between A and B? ${graph.hasEdge('A', 'B') ? 'Yes' : 'No'}`);
console.log(`Does an edge exist between A and D? ${graph.hasEdge('A', 'D') ? 'Yes' : 'No'}`);
