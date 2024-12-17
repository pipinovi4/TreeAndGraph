#include "../include/bfs_graph.h"
#include <iostream>

int main() {
    // Create vertex instances
    Vertex<std::string>* A = new Vertex<std::string>("A");
    Vertex<std::string>* B = new Vertex<std::string>("B");
    Vertex<std::string>* C = new Vertex<std::string>("C");
    Vertex<std::string>* D = new Vertex<std::string>("D");
    Vertex<std::string>* E = new Vertex<std::string>("E");
    Vertex<std::string>* F = new Vertex<std::string>("F");

    // Create a BFS graph instance
    BFSGraph<std::string> graph;

    // Add edges to the graph
    graph.add_edge(A, B);
    graph.add_edge(A, C);
    graph.add_edge(B, D);
    graph.add_edge(C, D);
    graph.add_edge(D, E);
    graph.add_edge(E, F);
    graph.add_edge(C, F);

    // Display the graph structure
    std::cout << "\nGraph Adjacency List:" << std::endl;
    graph.display();

    // Perform BFS starting from vertex 'A'
    std::cout << "\nBFS Traversal Starting from Vertex A:" << std::endl;
    graph.bfs(A);

    // Perform BFS starting from vertex 'C'
    std::cout << "\nBFS Traversal Starting from Vertex C:" << std::endl;
    graph.bfs(C);

    // Perform BFS starting from vertex 'D'
    std::cout << "\nBFS Traversal Starting from Vertex D:" << std::endl;
    graph.bfs(D);

    // Cleanup dynamically allocated memory
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;

    return 0;
}
