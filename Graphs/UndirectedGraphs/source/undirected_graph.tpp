#ifndef UNDIRECTED_GRAPH_TPP
#define UNDIRECTED_GRAPH_TPP

#include "../include/undirected_graph.h"
#include <stdexcept> // For potential exception handling

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

// UndirectedGraph Constructor
template <typename T>
UndirectedGraph<T>::UndirectedGraph() = default;
// Default constructor. The `= default` keyword tells the compiler to generate
// the default constructor automatically.

// Add a vertex to the graph
template <typename T>
void UndirectedGraph<T>::addVertex(Vertex<T>* vertex) {
    // Checks if the vertex is not already in the adjacency list.
    // If not, adds it with an empty list of neighbors.
    if (_adjacency_list.find(vertex) == _adjacency_list.end()) {
        _adjacency_list[vertex] = {};
    }
}

// Add an undirected edge between two vertices
template <typename T>
void UndirectedGraph<T>::addEdge(Vertex<T>* vertex1, Vertex<T>* vertex2) {
    // Ensure both vertices are in the graph.
    addVertex(vertex1);
    addVertex(vertex2);

    // Add the edge in both directions (bidirectional).
    _adjacency_list[vertex1].push_back(vertex2);
    _adjacency_list[vertex2].push_back(vertex1);
}

// Check if an edge exists between two vertices
template <typename T>
bool UndirectedGraph<T>::hasEdge(Vertex<T>* source, Vertex<T>* target) const {
    // Check if the source vertex exists in the adjacency list.
    if (_adjacency_list.find(source) == _adjacency_list.end()) {
        return false;
    }

    // Use std::find to check if the target vertex is in the neighbor list of the source.
    return std::find(_adjacency_list.at(source).begin(), _adjacency_list.at(source).end(), target) != _adjacency_list.at(source).end();
}

// Print the adjacency list of the graph
template <typename T>
void UndirectedGraph<T>::print() const {
    // Iterate over each vertex and print its value and neighbors.
    for (const auto& pair : _adjacency_list) {
        std::cout << pair.first->getValue() << " : ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor->getValue() << " ";
        }
        std::cout << std::endl;
    }
}

#endif // UNDIRECTED_GRAPH_TPP
