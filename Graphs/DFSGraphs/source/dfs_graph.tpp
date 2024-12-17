#ifndef DFS_INCLUDE_TPP
#define DFS_INCLUDE_TPP

#include "../include/dfs_graph.h"
#include <iostream>
#include <stack>

template <typename T>
Vertex<T>::Vertex(T value) : _value(value) {}

template <typename T>
void Vertex<T>::addNeighbor(Vertex<T> *neighbor) {
    _neighbors.push_back(neighbor);
}

template <typename T>
const T &Vertex<T>::getValue() const {
    return _value;
}

template <typename T>
const std::vector<Vertex<T> *> &Vertex<T>::getNeighbors() const {
    return _neighbors;
}

template <typename T>
DFSGraph<T>::DFSGraph() = default;

template <typename T>
void DFSGraph<T>::add_vertex(Vertex<T> *vertex) {
    _vertices.insert(vertex);
}

template <typename T>
void DFSGraph<T>::add_edge(Vertex<T>* source, Vertex<T>* target) {
    if (_vertices.find(source) == _vertices.end()) {
        _vertices.insert(source);
    }
    if (_vertices.find(target) == _vertices.end()) {
        _vertices.insert(target);
    }

    // Ensure source exists in the graph before adding the target
    _graph[source].push_back(target);
    source->addNeighbor(target);  // Add the neighbor to the source vertex
}

template <typename T>
void DFSGraph<T>::dfs(Vertex<T>* start_vertex) {
    if (!start_vertex) return;  // Handle null input

    std::set<Vertex<T>*> visited;
    std::stack<Vertex<T>*> stack;

    stack.push(start_vertex);

    while (!stack.empty()) {
        Vertex<T>* current_vertex = stack.top();
        stack.pop();

        if (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);
            std::cout << current_vertex->getValue() << " ";

            // Check if the vertex exists in the graph before accessing neighbors
            if (_graph.find(current_vertex) != _graph.end()) {
                for (auto it = _graph[current_vertex].rbegin(); it != _graph[current_vertex].rend(); ++it) {
                    if (visited.find(*it) == visited.end()) {
                        stack.push(*it);
                    }
                }
            }
        }
    }

    std::cout << std::endl;
}

template <typename T>
void DFSGraph<T>::display() {
    // Iterate over each vertex and print its value and neighbors.
    for (const auto& pair : _graph) {
        std::cout << pair.first->getValue() << " : ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor->getValue() << " ";
        }
        std::cout << std::endl;
    }
}

#endif //DFS_INCLUDE_TPP
