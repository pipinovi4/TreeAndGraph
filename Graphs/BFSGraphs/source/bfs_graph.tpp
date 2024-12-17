#ifndef BFS_GRAPH_TPP
#define BFS_GRAPH_TPP

#include "../include/bfs_graph.h"
#include <queue>

template <typename T>
Vertex<T>::Vertex(T value) : _value(value) {
    // Constructor to initialize the vertex with a value
}

template <typename T>
void Vertex<T>::addNeighbor(Vertex<T>* neighbor) {
    // Add a neighbor to the current vertex's neighbors list
    _neighbors.push_back(neighbor);
}

template <typename T>
const T& Vertex<T>::getValue() const {
    // Return the value stored in the vertex
    return _value;
}

template <typename T>
const std::vector<Vertex<T>*>& Vertex<T>::getNeighbors() const {
    // Return the list of neighboring vertices
    return _neighbors;
}

template <typename T>
BFSGraph<T>::BFSGraph() = default;  // Default constructor for the BFSGraph class

template <typename T>
void BFSGraph<T>::add_vertex(Vertex<T> *vertex) {
    // Insert the vertex into the set of vertices
    _vertices.insert(vertex);
}

template <typename T>
void BFSGraph<T>::add_edge(Vertex<T> *source, Vertex<T> *target) {
    // Add the source vertex if it is not in the set
    if (_vertices.find(source) == _vertices.end()) {
        add_vertex(source);
    }

    // Add the target vertex if it is not in the set
    if (_vertices.find(target) == _vertices.end()) {
        add_vertex(target);
    }

    // Add the target vertex to the adjacency list of the source vertex
    _graph[source].push_back(target);
}

template <typename T>
void BFSGraph<T>::bfs(Vertex<T>* start_vertex) {
    // Return immediately if the starting vertex is null
    if (!start_vertex) return;

    std::set<Vertex<T>*> visited;       // Set to track visited vertices
    std::queue<Vertex<T>*> queue;       // Queue for BFS traversal
    queue.push(start_vertex);           // Start BFS with the initial vertex

    while (!queue.empty()) {
        // Get the vertex at the front of the queue
        Vertex<T>* current_vertex = queue.front();
        queue.pop();  // Remove the vertex from the queue

        // If the vertex has not been visited
        if (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);            // Mark the vertex as visited
            std::cout << current_vertex->getValue() << " ";  // Print the vertex's value

            // Access neighbors from the graph's adjacency list
            if (_graph.find(current_vertex) != _graph.end()) {
                for (Vertex<T>* neighbor : _graph[current_vertex]) {
                    // Add unvisited neighbors to the queue
                    if (visited.find(neighbor) == visited.end()) {
                        queue.push(neighbor);
                    }
                }
            }
        }
    }

    std::cout << std::endl;  // Print a newline after traversal is complete
}

template <typename T>
void BFSGraph<T>::display() {
    // Iterate through each vertex and its adjacency list
    for (const auto& pair : _graph) {
        std::cout << pair.first->getValue() << " : ";

        // Print each neighbor's value
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor->getValue() << " ";
        }

        std::cout << std::endl;  // Newline for each vertex's adjacency list
    }
}

#endif // BFS_GRAPH_TPP
