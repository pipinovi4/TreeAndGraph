#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

// Vertex class
template <typename T>
class Vertex {
public:
    Vertex(T value);

    void addNeighbor(Vertex<T>* neighbor);

    // Getters
    const T& getValue() const;
    const std::vector<Vertex<T>*>& getNeighbors() const;

private:
    T _value;
    std::vector<Vertex<T>*> _neighbors;
};

// UndirectedGraph class
template <typename T>
class UndirectedGraph {
public:
    UndirectedGraph();

    void addVertex(Vertex<T>* vertex);

    void addEdge(Vertex<T>* vertex1, Vertex<T>* vertex2);

    bool hasEdge(Vertex<T>* source, Vertex<T>* target) const;

    void print() const;

private:
    std::map<Vertex<T>*, std::vector<Vertex<T>*>> _adjacency_list;
};

#include "../source/undirected_graph.tpp"

#endif // UNDIRECTED_GRAPH_H
