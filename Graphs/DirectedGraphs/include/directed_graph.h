#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#pragma once

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

/**
 * @class Vertex
 * @brief Represents a vertex (node) in a directed graph.
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
 * @class DirectedGraph
 * @brief Represents a directed graph using an adjacency list.
 *
 * The graph consists of vertices of type `Vertex<T>`, where each vertex maintains a list
 * of its neighboring vertices. The adjacency list is implemented as a `std::map` that
 * maps each vertex to its list of neighbors.
 *
 * @tparam T The type of the value stored in each vertex.
 */
template <typename T>
class DirectedGraph {
public:
    /**
     * @brief Constructor to initialize an empty directed graph.
     */
    DirectedGraph();

    /**
     * @brief Adds a vertex to the graph.
     *
     * If the vertex already exists in the graph, no action is taken.
     *
     * @param vertex Pointer to the vertex to be added.
     */
    void addVertex(Vertex<T>* vertex);

    /**
     * @brief Adds a directed edge from the source vertex to the target vertex.
     *
     * If either vertex does not exist in the graph, it will be added automatically.
     *
     * @param source Pointer to the source vertex.
     * @param target Pointer to the target vertex.
     */
    void addEdge(Vertex<T>* source, Vertex<T>* target);

    /**
     * @brief Checks if an edge exists from the source vertex to the target vertex.
     *
     * @param source Pointer to the source vertex.
     * @param target Pointer to the target vertex.
     * @return True if an edge exists from the source to the target, otherwise false.
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

#include "../source/directed_graph.tpp"

#endif // DIRECTED_GRAPH_H
