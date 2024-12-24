#include <iostream>
#include "../include/directed_acyclic_graph.h"

int main() {
    // Create a directed acyclic graph (DAG)
    DirectedAcyclicGraph<std::string, bool> dag;

    // Create vertices
    Vertex<std::string>* v1 = new Vertex<std::string>("A");
    Vertex<std::string>* v2 = new Vertex<std::string>("B");
    Vertex<std::string>* v3 = new Vertex<std::string>("C");
    Vertex<std::string>* v4 = new Vertex<std::string>("D");
    Vertex<std::string>* v5 = new Vertex<std::string>("E");
    Vertex<std::string>* v6 = new Vertex<std::string>("F");

    // Add vertices to the graph
    dag.addVertex(v1);
    dag.addVertex(v2);
    dag.addVertex(v3);
    dag.addVertex(v4);
    dag.addVertex(v5);
    dag.addVertex(v6);

    // Add edges to the graph
    try {
        dag.addEdge(v1, v2);
        dag.addEdge(v1, v3);
        dag.addEdge(v2, v4);
        dag.addEdge(v3, v4);
        dag.addEdge(v4, v5);
        dag.addEdge(v5, v6);

        // Uncommenting the line below will throw an exception due to cycle detection
        // dag.addEdge(v6, v1); // This would create a cycle

    } catch (const std::exception& e) {
        std::cerr << "Error adding edge: " << e.what() << std::endl;
    }

    // Display the graph
    std::cout << "Graph structure:" << std::endl;
    dag.display();

    // Perform a topological sort
    std::cout << "\nTopological Sort:" << std::endl;
    std::vector<Vertex<std::string>*> sorted = dag.topologicalSort();
    for (Vertex<std::string>* vertex : sorted) {
        std::cout << vertex->getValue() << " ";
    }
    std::cout << std::endl;

    return 0;
}
