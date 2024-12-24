#ifndef DIRECTED_ACYCLIC_GRAPH_TPP
#define DIRECTED_ACYCLIC_GRAPH_TPP

#include "../include/directed_acyclic_graph.h"
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <type_traits>

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

template <typename T, typename U>
DirectedAcyclicGraph<T, U>::DirectedAcyclicGraph() {
    _graph = {};
    _vertices = {};
}

template <typename T, typename U>
DirectedAcyclicGraph<T, U>::~DirectedAcyclicGraph() {
    for (Vertex<T>* vertex : _vertices) {
        delete vertex;
    }
}

template <typename T, typename U>
void DirectedAcyclicGraph<T, U>::addVertex(Vertex<T>* vertex) {
    if (!vertex) throw std::invalid_argument("Passed argument to addVertex is nullptr");

    _vertices.insert(vertex);
}

template <typename T, typename U>
void DirectedAcyclicGraph<T, U>::addEdge(Vertex<T>* source, Vertex<T>* target) {
    if (!source || !target) throw std::invalid_argument("Passed invalid argument, some which argument is nullptr");

    if (_vertices.find(source) == _vertices.end()) {
        addVertex(source);
    }
    if (_vertices.find(target) == _vertices.end()) {
        addVertex(target);
    }

    source->addNeighbor(target);  // This ensures that the neighbors are correctly updated
    _graph[source].push_back(target);

    // Check if the value type of the vertex is not string, then transform it
    if constexpr (!std::is_same<T, std::string>::value) {
        if (_hasCycle()) {
            _graph[source].pop_back();
            throw std::invalid_argument(
                    "Adding edge " + std::to_string(source->getValue()) + " -> " +
                    std::to_string(target->getValue()) + " introduces a cycle!"
            );
        }
    } else {
        if (_hasCycle()) {
            _graph[source].pop_back();
            throw std::invalid_argument(
                    "Adding edge " + source->getValue() + " -> " + target->getValue() + " introduces a cycle!"
            );
        }
    }
}

template <typename T, typename U>
U DirectedAcyclicGraph<T, U>::dfsIterative(Vertex<T>* start_vertex, std::set<Vertex<T>*>* visited,
                                           std::function<void()>* process, std::stack<Vertex<T>*>* record_stack,
                                           bool detect_cycle) {
    // Initialize visited set if not provided
    std::set<Vertex<T>*> local_visited;
    visited = (visited != nullptr) ? visited : &local_visited;

    // Use set for rec_stack to detect cycles
    std::set<Vertex<T>*> rec_stack;

    std::stack<Vertex<T>*> stack;
    stack.push(start_vertex);

    while (!stack.empty()) {
        Vertex<T>* vertex = stack.top();
        stack.pop();

        if (visited->find(vertex) == visited->end()) {
            visited->insert(vertex);

            if (detect_cycle) rec_stack.insert(vertex);
            if (process) (*process)();
            if (record_stack) record_stack->push(vertex);

            for (auto it = _graph[vertex].rbegin(); it != _graph[vertex].rend(); ++it) {
                Vertex<T>* neighbor = *it;
                if (detect_cycle && rec_stack.find(neighbor) != rec_stack.end()) {
                    return true;  // Cycle detected
                }
                if (visited->find(neighbor) == visited->end()) {
                    stack.push(neighbor);
                }
            }

            if (detect_cycle) rec_stack.erase(vertex);
        }
    }

    return false;  // No cycle detected
}

template <typename T, typename U>
bool DirectedAcyclicGraph<T, U>::_hasCycle() {
    std::set<Vertex<T>*> visited;  // Local visited set
    for (Vertex<T>* vertex : _vertices) {
        if (visited.find(vertex) == visited.end()) {
            if (dfsIterative(vertex, &visited, nullptr, nullptr, true)) {  // Pass &visited
                return true;
            }
        }
    }
    return false;  // No cycle detected
}

template <typename T, typename U>
std::vector<Vertex<T>*> DirectedAcyclicGraph<T, U>::topologicalSort() {
    std::set<Vertex<T>*> visited;
    std::stack<Vertex<T>*> stack;  // Change to stack instead of queue

    for (Vertex<T>* vertex : _vertices) {
        if (visited.find(vertex) == visited.end()) {
            dfsIterative(vertex, &visited, nullptr, &stack, false);
        }
    }

    std::vector<Vertex<T>*> result;

    // Pop vertices from the stack to get the topological order
    while (!stack.empty()) {
        result.push_back(stack.top());  // Push to result in the order they are removed from the stack
        stack.pop();
    }

    return result;
}

template <typename T, typename U>
void DirectedAcyclicGraph<T, U>::display() {
    // Iterate over each vertex and print its value and neighbors
    for (const auto& vertex : _vertices) {
        std::cout << vertex->getValue() << " : ";
        for (const auto& neighbor : vertex->getNeighbors()) {
            std::cout << neighbor->getValue() << " ";
        }
        std::cout << std::endl;
    }
}

#endif //DIRECTED_ACYCLIC_GRAPH_TPP
