#ifndef DFS_INCLUDE_TPP
#define DFS_INCLUDE_TPP

#include "../include/dfs_graph.h"

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

#endif //DFS_INCLUDE_TPP
