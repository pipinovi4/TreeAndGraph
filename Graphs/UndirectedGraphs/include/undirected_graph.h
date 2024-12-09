#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#pragma once

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

/**
 * @class Vertex
 * @brief Represents a vertex (node) in an undirected graph.
 *
 * Each vertex stores a value of type `T` and maintains a list of neighboring vertices.
 *
 * @tparam T The type of the value stored in the vertex.
 */
template <typename T>
class Vertex {
public:
    /**
     * @brief Constructor to initialize the vertex with a given value.
     *
     * @param value The value to store in the vertex.
     */
    Vertex(T value);

    /**
     * @brief Adds a neighboring vertex to the current vertex.
     *
     * @param neighbor Pointer to the neighboring vertex to be added.
     */
    void addNeighbor(Vertex<T>* neighbor);

    /**
     * @brief Retrieves the value stored in the vertex.
     *
     * @return A const reference to the value of the vertex.
     */
    const T& getValue() const;

    /**
     * @brief Retrieves the list of neighboring vertices.
     *
     * @return A const reference to the vector of neighboring vertices.
     */
    const std::vector<Vertex<T>*>& getNeighbors() const;

private:
    T _value;                            ///< The value stored in the vertex.
    std::vector<Vertex<T>*> _neighbors; ///< The list of neighboring vertices.
};

/**
 * @class UndirectedGraph
 * @brief Represents an undirected graph using an adjacency list.
 *
 * The graph consists of vertices of type `Vertex<T>`, where each vertex maintains a list
 * of its neighboring vertices. The adjacency list is implemented as a `std::map` that
 * maps each vertex to its list of neighbors.
 *
 * @tparam T The type of the value stored in each vertex.
 */
template <typename T>
class UndirectedGraph {
public:
    /**
     * @brief Constructor to initialize an empty undirected graph.
     */
    UndirectedGraph();

    /**
     * @brief Adds a vertex to the graph.
     *
     * If the vertex already exists in the graph, no action is taken.
     *
     * @param vertex Pointer to the vertex to be added.
     */
    void addVertex(Vertex<T>* vertex);

    /**
     * @brief Adds an undirected edge between two vertices.
     *
     * If either vertex does not exist in the graph, it will be added automatically.
     *
     * @param vertex1 Pointer to the first vertex.
     * @param vertex2 Pointer to the second vertex.
     */
    void addEdge(Vertex<T>* vertex1, Vertex<T>* vertex2);

    /**
     * @brief Checks if an edge exists between two vertices.
     *
     * @param source Pointer to the source vertex.
     * @param target Pointer to the target vertex.
     * @return True if an edge exists between the source and target vertices, otherwise false.
     */
    bool hasEdge(Vertex<T>* source, Vertex<T>* target) const;

    /**
     * @brief Prints the adjacency list of the graph.
     *
     * Displays each vertex and its corresponding neighbors.
     */
    void print() const;

private:
    std::map<Vertex<T>*, std::vector<Vertex<T>*>> _adjacency_list; ///< The adjacency list representing the graph.
};

#include "../source/undirected_graph.tpp"

#endif // UNDIRECTED_GRAPH_H
