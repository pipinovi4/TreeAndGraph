#ifndef DFS_INCLUDE_H
#define DFS_INCLUDE_H

#pragma once
#include <vector>
#include <map>
#include <set>

/**
 * @brief Class representing a vertex in a graph.
 *
 * @tparam T The type of the value stored in the vertex.
 */
template <typename T>
class Vertex {
public:
    /**
     * @brief Constructor to initialize the vertex with a value.
     *
     * @param value The value associated with the vertex.
     */
    Vertex(T value);

    /**
     * @brief Add a neighboring vertex to this vertex.
     *
     * @param neighbor A pointer to the neighboring vertex.
     */
    void addNeighbor(Vertex<T>* neighbor);

    /**
     * @brief Get the value of the vertex.
     *
     * @return const T& The value of the vertex.
     */
    const T& getValue() const;

    /**
     * @brief Get the list of neighboring vertices.
     *
     * @return const std::vector<Vertex<T>*>& A reference to the vector of neighboring vertices.
     */
    const std::vector<Vertex<T>*>& getNeighbors() const;

private:
    T _value;  ///< The value stored in the vertex.
    std::vector<Vertex<T>*> _neighbors;  ///< List of pointers to neighboring vertices.
};

/**
 * @brief Class representing a graph with Depth-First Search (DFS) functionality.
 *
 * @tparam T The type of the value stored in the vertices.
 */
template <typename T>
class DFSGraph {
public:
    /**
     * @brief Constructor to initialize an empty graph.
     */
    DFSGraph();

    /**
     * @brief Add a vertex to the graph.
     *
     * @param vertex A pointer to the vertex to be added.
     */
    void add_vertex(Vertex<T>* vertex);

    /**
     * @brief Add an edge between two vertices in the graph.
     *
     * @param source A pointer to the source vertex.
     * @param target A pointer to the target vertex.
     */
    void add_edge(Vertex<T>* source, Vertex<T>* target);

    /**
     * @brief Perform a Depth-First Search (DFS) starting from a given vertex.
     *
     * @param start_vertex A pointer to the vertex where DFS traversal begins.
     */
    void dfs(Vertex<T>* start_vertex);

    /**
     * @brief Display the graph as an adjacency list.
     */
    void display();

private:
    std::map<Vertex<T>*, std::vector<Vertex<T>*>> _graph;  ///< Adjacency list representing the graph.
    std::set<Vertex<T>*> vertices;  ///< Set of vertices in the graph to ensure uniqueness.
};

#include "../source/dfs_graph.tpp"

#endif // DFS_INCLUDE_H
