#ifndef DFS_INCLUDE_TPP
#define DFS_INCLUDE_TPP

#include "../include/dfs_graph.h"
#include <iostream>
#include <stack>

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
DFSGraph<T>::DFSGraph() = default;  // Default constructor for the graph

template <typename T>
void DFSGraph<T>::add_vertex(Vertex<T>* vertex) {
    // Add the vertex to the set of vertices in the graph
    _vertices.insert(vertex);
}

template <typename T>
void DFSGraph<T>::add_edge(Vertex<T>* source, Vertex<T>* target) {
    // Ensure source and target vertices are not null
    if (!source || !target) return;

    // Add source and target vertices to the set of vertices if they are not already present
    _vertices.insert(source);
    _vertices.insert(target);

    // Add a directed edge from source to target in the adjacency list
    _graph[source].push_back(target);
}

template <typename T>
void DFSGraph<T>::dfs(Vertex<T>* start_vertex) {
    // Handle the case where the starting vertex is null
    if (!start_vertex) return;

    // Set to track visited vertices to avoid revisiting nodes
    std::set<Vertex<T>*> visited;

    // Stack for iterative DFS traversal, initialized with the starting vertex
    std::stack<Vertex<T>*> stack;
    stack.push(start_vertex);

    // Perform DFS until the stack is empty
    while (!stack.empty()) {
        // Get the current vertex from the top of the stack and remove it
        Vertex<T>* current_vertex = stack.top();
        stack.pop();

        // If the vertex has not been visited yet
        if (visited.find(current_vertex) == visited.end()) {
            // Mark the vertex as visited and print its value
            visited.insert(current_vertex);
            std::cout << current_vertex->getValue() << " ";

            // Check if the current vertex exists in the graph before accessing neighbors
            if (_graph.find(current_vertex) != _graph.end()) {
                // Add neighbors to the stack in reverse order to maintain the correct DFS order
                const auto& neighbors = current_vertex->getNeighbors();
                for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                    if (visited.find(*it) == visited.end()) {
                        stack.push(*it);
                    }
                }
            }
        }
    }

    // Print a newline after the traversal is complete
    std::cout << std::endl;
}

template <typename T>
void DFSGraph<T>::display() {
    // Iterate over each vertex in the adjacency list and print its neighbors
    for (const auto& pair : _graph) {
        // Print the current vertex's value
        std::cout << pair.first->getValue() << " : ";

        // Print the neighbors of the current vertex
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor->getValue() << " ";
        }

        // Print a newline after each vertex's neighbors are displayed
        std::cout << std::endl;
    }
}

#endif // DFS_INCLUDE_TPP
