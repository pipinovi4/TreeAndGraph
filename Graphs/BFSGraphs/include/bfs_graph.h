#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

#pragma once
#include <map>
#include <iostream>
#include <vector>
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
class BFSGraph {
public:
    BFSGraph();
    void add_vertex(Vertex<T>* vertex);
    void add_edge(Vertex<T>* source, Vertex<T>* target);
    void bfs(Vertex<T>* start_vertex);
    void display();
private:
    std::map<Vertex<T>*, std::vector<Vertex<T>*>> _graph;
    std::set<Vertex<T>*> _vertices;
};

#include "../source/bfs_graph.tpp"

#endif //BFS_GRAPH_H
