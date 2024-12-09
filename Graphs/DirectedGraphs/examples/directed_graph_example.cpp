#include "../include/directed_graph.h"
#include <iostream>

int main() {
    // Create some vertices
    Vertex<std::string> v1("A");
    Vertex<std::string> v2("B");
    Vertex<std::string> v3("C");
    Vertex<std::string> v4("D");

    // Create a directed graph
    DirectedGraph<std::string> graph;

    // Add vertices to the graph
    graph.addVertex(&v1);
    graph.addVertex(&v2);
    graph.addVertex(&v3);
    graph.addVertex(&v4);

    // Add edges between vertices (directed edges)
    graph.addEdge(&v1, &v2); // A -> B
    graph.addEdge(&v1, &v3); // A -> C
    graph.addEdge(&v2, &v4); // B -> D
    graph.addEdge(&v3, &v4); // C -> D

    // Print the graph's adjacency list
    std::cout << "Graph Adjacency List:" << std::endl;
    graph.print();

    // Check if specific edges exist
    std::cout << "\nChecking if edges exist:" << std::endl;
    std::cout << "Does an edge exist from A to B? "
              << (graph.hasEdge(&v1, &v2) ? "Yes" : "No") << std::endl;

    std::cout << "Does an edge exist from A to D? "
              << (graph.hasEdge(&v1, &v4) ? "Yes" : "No") << std::endl;

    std::cout << "Does an edge exist from B to D? "
              << (graph.hasEdge(&v2, &v4) ? "Yes" : "No") << std::endl;

    return 0;
}
