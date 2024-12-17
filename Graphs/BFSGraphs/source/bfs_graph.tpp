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
BFSGraph<T>::BFSGraph() = default;

template <typename T>
void BFSGraph<T>::add_vertex(Vertex<T> *vertex) {
    _vertices.insert(vertex);
}

template <typename T>
void BFSGraph<T>::add_edge(Vertex<T> *source, Vertex<T> *target) {
    if (_vertices.find(source) == _vertices.end()) {
        add_vertex(source);
    }
    if (_vertices.find(target) == _vertices.end()) {
        add_vertex(target);
    }

    _graph[source].push_back(target);
}

template <typename T>
void BFSGraph<T>::bfs(Vertex<T> *start_vertex) {
    if (!start_vertex) return;

    std::set<Vertex<T>*> visited;
    std::queue<Vertex<T>*> queue;
    queue.push(start_vertex);

    while (!queue.empty()) {
        Vertex<T>* current_vertex = queue.front();
        queue.pop();

        if (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);
            std::cout << current_vertex->getValue() << " ";

            if (_graph.find(current_vertex) != _graph.end()) {
                const auto& neighbors = current_vertex->getNeighbors();
                for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                    if (visited.find(*it) == visited.end()) {
                        queue.push(*it);
                    }
                }
            }
        }
    }

    std::cout << std::endl;
}

template <typename T>
void BFSGraph<T>::display() {
    for (const auto& pair : _graph) {
        std::cout << pair.first->getValue() << " : ";

        for (const auto& neighbor : pair.second) {
            std::cout << neighbor->getValue() << " ";
        }

        std::cout << std::endl;
    }
}

#endif //BFS_GRAPH_TPP
