#ifndef DIRECTED_GRAPH_TPP
#define DIRECTED_GRAPH_TPP

#include "../include/directed_graph.h"

// Vertex Constructor
template <typename T>
Vertex<T>::Vertex(T value) : _value(value) {
    // Initializes the vertex with the given value.
    // Uses the initializer list to set the _value member variable.
}

// Add a neighbor to the vertex
template <typename T>
void Vertex<T>::addNeighbor(Vertex<T>* neighbor) {
    // Adds a pointer to a neighboring vertex to the _neighbors list.
    _neighbors.push_back(neighbor);
}

// Get the value of the vertex
template <typename T>
const T& Vertex<T>::getValue() const {
    // Returns a constant reference to the value stored in the vertex.
    // This prevents the caller from modifying the value.
    return _value;
}

// Get the neighbors of the vertex
template <typename T>
const std::vector<Vertex<T>*>& Vertex<T>::getNeighbors() const {
    // Returns a constant reference to the list of neighboring vertices.
    // This ensures the neighbors cannot be modified from outside the class.
    return _neighbors;
}

// DirectedGraph Constructor
template <typename T>
DirectedGraph<T>::DirectedGraph() = default;
// Default constructor. The `= default` keyword tells the compiler to generate
// the default constructor automatically.

// Add a vertex to the graph
template <typename T>
void DirectedGraph<T>::addVertex(Vertex<T>* vertex) {
    // Checks if the vertex is not already in the adjacency list.
    // If not, adds it with an empty list of neighbors.
    if (_adjacency_list.find(vertex) == _adjacency_list.end()) {
        _adjacency_list[vertex] = {};
    }
}

// Add a directed edge from source to target
template <typename T>
void DirectedGraph<T>::addEdge(Vertex<T>* source, Vertex<T>* target) {
    // Ensure the source vertex is in the graph.
    addVertex(source);
    addVertex(target);

    // Add the edge only from source to target (unidirectional).
    _adjacency_list[source].push_back(target);
}

// Check if an edge exists from source to target
template <typename T>
bool DirectedGraph<T>::hasEdge(Vertex<T>* source, Vertex<T>* target) const {
    // Check if the source vertex exists in the adjacency list.
    if (_adjacency_list.find(source) == _adjacency_list.end()) {
        return false;
    }

    // Use std::find to check if the target vertex is in the neighbor list of the source.
    return std::find(_adjacency_list.at(source).begin(), _adjacency_list.at(source).end(), target) != _adjacency_list.at(source).end();
}

// Print the adjacency list of the graph
template <typename T>
void DirectedGraph<T>::print() const {
    // Iterate over each vertex and print its value and neighbors.
    for (const auto& pair : _adjacency_list) {
        std::cout << pair.first->getValue() << " : ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor->getValue() << " ";
        }
        std::cout << std::endl;
    }
}

#endif // DIRECTED_GRAPH_TPP
