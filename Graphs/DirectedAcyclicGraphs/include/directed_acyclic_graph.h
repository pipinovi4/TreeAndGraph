#ifndef DIRECTED_ACYCLIC_GRAPH_H
#define DIRECTED_ACYCLIC_GRAPH_H

#pragma once
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <functional>

template <typename T>
class Vertex {
public:
    Vertex(T value);

    void addNeighbor(Vertex<T>* neighbor);

    const T& getValue() const;

    const std::vector<Vertex<T>*>& getNeighbors() const;

private:
    T _value;
    std::vector<Vertex<T>*> _neighbors;
};

template <typename T, typename U>
class DirectedAcyclicGraph {
public:
    DirectedAcyclicGraph();
    ~DirectedAcyclicGraph();

    void addVertex(Vertex<T>* vertex);
    void addEdge(Vertex<T>* source, Vertex<T>* target);

    U dfsIterative(Vertex<T>* start_vertex, std::set<Vertex<T>*>* visited=nullptr, std::function<void()>* process= nullptr, std::stack<Vertex<T>*>* record_stack=nullptr, bool detect_cycle=false);

    std::vector<Vertex<T>*> topologicalSort();

    void display();
private:
    std::map<Vertex<T>*, std::vector<Vertex<T>*>> _graph;
    std::set<Vertex<T>*> _vertices;

    bool _hasCycle();
};

#include "../source/directed_acyclic_graph.tpp"

#endif //DIRECTED_ACYCLIC_GRAPH_H
