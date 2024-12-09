#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#pragma once
#include <vector>

template <typename T>
class UndirectedGraph {
public:
    UndirectedGraph();

    void addVertex(std::vector<T> vertex);

    void addEdge(std::vector<T> vertex1, std::vector<T> vertex2);

    bool hasEdge(std::vector<T> source, std::vector<T> target);

    void print();

private:
    std::vector<T> _adjacency_list;
};

#include "../source/undirected_graph.tpp"

#endif //UNDIRECTED_GRAPH_H
