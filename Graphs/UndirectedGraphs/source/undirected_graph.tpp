#ifndef UNDIRECTED_GRAPH_TPP
#define UNDIRECTED_GRAPH_TPP

#include "../include/undirected_graph.h"
#include <stdexcept>

// Vertex Constructor
template <typename T>
Vertex<T>::Vertex(T value) : _value(value) {}

// Add a neighbor to the vertex
template <typename T>
void Vertex<T>::addNeighbor(Vertex<T>* neighbor) {
    _neighbors.push_back(neighbor);
}

// Get the value of the vertex
template <typename T>
const T& Vertex<T>::getValue() const {
    return _value;
}

// Get the neighbors of the vertex
template <typename T>
const std::vector<Vertex<T>*>& Vertex<T>::getNeighbors() const {
    return _neighbors;
}

// UndirectedGraph Constructor
template <typename T>
UndirectedGraph<T>::UndirectedGraph() = default;

// Add a vertex to the graph
template <typename T>
void UndirectedGraph<T>::addVertex(Vertex<T>* vertex) {
    if (_adjacency_list.find(vertex) == _adjacency_list.end()) {
        _adjacency_list[vertex] = {};
    }
}

// Add an undirected edge between two vertices
template <typename T>
void UndirectedGraph<T>::addEdge(Vertex<T>* vertex1, Vertex<T>* vertex2) {
    addVertex(vertex1);
    addVertex(vertex2);

    _adjacency_list[vertex1].push_back(vertex2);
    _adjacency_list[vertex2].push_back(vertex1);
}

// Check if an edge exists between two vertices
template <typename T>
bool UndirectedGraph<T>::hasEdge(Vertex<T>* source, Vertex<T>* target) const {
    if (_adjacency_list.find(source) == _adjacency_list.end()) {
        return false;
    }
    return std::find(_adjacency_list.at(source).begin(), _adjacency_list.at(source).end(), target) != _adjacency_list.at(source).end();
}

// Print the adjacency list of the graph
template <typename T>
void UndirectedGraph<T>::print() const {
    for (const auto& pair : _adjacency_list) {
        std::cout << pair.first->getValue() << " : ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor->getValue() << " ";
        }
        std::cout << std::endl;
    }
}

#endif // UNDIRECTED_GRAPH_TPP
