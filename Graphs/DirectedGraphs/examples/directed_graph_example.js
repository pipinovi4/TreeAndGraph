const DirectedGraph = require('../source/directed_graph');

// Create a directed graph
const graph = new DirectedGraph();

// Add vertices to the graph
graph.addVertex('A');
graph.addVertex('B');
graph.addVertex('C');
graph.addVertex('D');

// Add directed edges between vertices
graph.addEdge('A', 'B'); // A -> B
graph.addEdge('A', 'C'); // A -> C
graph.addEdge('B', 'D'); // B -> D
graph.addEdge('C', 'D'); // C -> D

// Print the graph's adjacency list
console.log('Graph Adjacency List:');
graph.print();

// Check if specific edges exist
console.log('\nChecking if edges exist:');
console.log(`Does an edge exist from A to B? ${graph.hasEdge('A', 'B') ? 'Yes' : 'No'}`);
console.log(`Does an edge exist from A to D? ${graph.hasEdge('A', 'D') ? 'Yes' : 'No'}`);
console.log(`Does an edge exist from B to D? ${graph.hasEdge('B', 'D') ? 'Yes' : 'No'}`);
