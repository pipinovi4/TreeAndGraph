#ifndef DFS_INCLUDE_H
#define DFS_INCLUDE_H

#pragma once
#include <vector>
#include <map>
#include <set>

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

template <typename T>
class DFSGraph {
public:
    DFSGraph();

    void add_vertex(Vertex<T>* vertex);

    void add_edge(Vertex<T>* source, Vertex<T>* target);

    void dfs(Vertex<T>* start_vertex);

    void display();
private:
    std::map<Vertex<T>*, std::vector<Vertex<T>*>> _graph;
    std::set<Vertex<T>*> vertices;
};

#include "../source/dfs_graph.tpp"

#endif //DFS_INCLUDE_H
