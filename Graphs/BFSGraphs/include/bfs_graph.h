#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

#pragma once

#include <map>
#include <iostream>
#include <vector>
#include <set>

/**
 * @brief Represents a vertex in the graph.
 *
 * @tparam T The type of the value stored in the vertex.
 */
template <typename T>
class Vertex {
public:
    /**
     * @brief Constructs a Vertex with the specified value.
     *
     * @param value The value to store in the vertex.
     */
    Vertex(T value);

    /**
     * @brief Adds a neighbor to the current vertex.
     *
     * @param neighbor A pointer to the neighboring vertex.
     */
    void addNeighbor(Vertex<T>* neighbor);

    /**
     * @brief Gets the value of the vertex.
     *
     * @return A constant reference to the value stored in the vertex.
     */
    const T& getValue() const;

    /**
     * @brief Gets the list of neighbors of the vertex.
     *
     * @return A constant reference to a vector of pointers to neighboring vertices.
     */
    const std::vector<Vertex<T>*>& getNeighbors() const;

private:
    T _value;  ///< The value stored in the vertex.
    std::vector<Vertex<T>*> _neighbors;  ///< List of pointers to neighboring vertices.
};

/**
 * @brief Represents a directed graph with Breadth-First Search (BFS) functionality.
 *
 * @tparam T The type of the value stored in the vertices.
 */
template <typename T>
class BFSGraph {
public:
    /**
     * @brief Constructs an empty BFSGraph.
     */
    BFSGraph();

    /**
     * @brief Adds a vertex to the graph.
     *
     * @param vertex A pointer to the vertex to be added.
     */
    void add_vertex(Vertex<T>* vertex);

    /**
     * @brief Adds a directed edge from the source vertex to the target vertex.
     *
     * If the vertices do not exist in the graph, they are added automatically.
     *
     * @param source A pointer to the source vertex.
     * @param target A pointer to the target vertex.
     */
    void add_edge(Vertex<T>* source, Vertex<T>* target);

    /**
     * @brief Performs a Breadth-First Search (BFS) traversal starting from the specified vertex.
     *
     * @param start_vertex A pointer to the vertex where the BFS traversal begins.
     *
     * Prints the vertices visited during the BFS traversal in the order they are visited.
     */
    void bfs(Vertex<T>* start_vertex);

    /**
     * @brief Displays the graph as an adjacency list.
     *
     * Prints each vertex and its list of adjacent vertices.
     */
    void display();

private:
    std::map<Vertex<T>*, std::vector<Vertex<T>*>> _graph;  ///< Adjacency list representing the graph.
    std::set<Vertex<T>*> _vertices;  ///< Set of vertices in the graph to ensure uniqueness.
};

#include "../source/bfs_graph.tpp"

#endif // BFS_GRAPH_H
