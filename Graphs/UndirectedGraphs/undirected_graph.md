# Undirected Graph

An **Undirected Graph** is a data structure used to represent a collection of **vertices (nodes)** connected by **edges** where the edges have **no direction**. This means that if an edge exists between vertex A and vertex B, you can traverse from A to B and also from B to A.

## Key Concepts

1. **Vertex (Node)**:
   - Represents a point or location in the graph.
   - Each vertex can store a value and maintain a list of neighboring vertices.

2. **Edge**:
   - Represents a connection between two vertices.
   - In an undirected graph, an edge between vertices A and B means you can traverse in both directions (A to B and B to A).

3. **Adjacency List**:
   - A common way to represent a graph.
   - Each vertex maps to a list of neighboring vertices (vertices directly connected by an edge).

---

## Structure of an Undirected Graph

An undirected graph consists of:
1. **Vertices**: Each vertex can hold a value of any type and a list of neighbors.
2. **Edges**: Connections between pairs of vertices, stored in both vertices’ neighbor lists.

### Adjacency List Representation

An **adjacency list** stores vertices and their neighbors. For example:

```
A : B C
B : A D
C : A D
D : B C
```

In this example:
- Vertex **A** is connected to **B** and **C**.
- Vertex **B** is connected to **A** and **D**.
- Vertex **C** is connected to **A** and **D**.
- Vertex **D** is connected to **B** and **C**.

---

## Core Operations

### 1. Adding a Vertex

**Purpose**: Add a new vertex to the graph.

**Process**:
1. Check if the vertex already exists in the graph.
2. If not, add it with an empty list of neighbors.

**Example**:
```
Add Vertex A
Graph: A : []
```

### 2. Adding an Edge

**Purpose**: Create an undirected edge between two vertices.

**Process**:
1. Ensure both vertices exist in the graph.
2. Add each vertex to the other's neighbor list to represent the bidirectional connection.

**Example**:
```
Add Edge between A and B
Graph:
A : B
B : A
```

### 3. Checking for an Edge

**Purpose**: Determine if there is an edge between two vertices.

**Process**:
1. Check if the first vertex exists in the graph.
2. Check if the second vertex is in the neighbor list of the first vertex.

**Example**:
```
Check if Edge exists between A and B
Result: True
```

### 4. Printing the Graph

**Purpose**: Display the adjacency list representation of the graph.

**Example**:
```
Graph:
A : B C
B : A
C : A
```

---

## Complexity Analysis

- **Adding a Vertex**: \(O(1)\) – Adding a new vertex takes constant time.
- **Adding an Edge**: \(O(1)\) – Adding an edge takes constant time if vertices are already in the graph.
- **Checking for an Edge**: \(O(V)\) – Where \(V\) is the number of neighbors of a vertex (worst case).
- **Printing the Graph**: \(O(V + E)\) – Where \(V\) is the number of vertices and \(E\) is the number of edges.

---

## Example of Operations

### Inserting Vertices and Edges

1. **Add Vertices A, B, and C**:
   ```
   Graph:
   A : []
   B : []
   C : []
   ```

2. **Add Edge between A and B**:
   ```
   Graph:
   A : B
   B : A
   ```

3. **Add Edge between A and C**:
   ```
   Graph:
   A : B C
   B : A
   C : A
   ```

4. **Add Edge between B and C**:
   ```
   Graph:
   A : B C
   B : A C
   C : A B
   ```

### Checking for an Edge

- **Check if an Edge exists between A and B**:
  - Result: **True**

- **Check if an Edge exists between B and D**:
  - Result: **False**

---

## Applications of Undirected Graphs

1. **Social Networks**:
   - Represent relationships where connections are mutual (e.g., friends on a social media platform).

2. **Road Maps**:
   - Represent intersections and roads where travel is possible in both directions.

3. **Computer Networks**:
   - Model networks where nodes (computers) are connected and communication is bidirectional.

4. **Biological Networks**:
   - Represent relationships between species or genetic networks where interactions are mutual.

5. **Game Development**:
   - Create maps and levels where paths between locations can be traveled in both directions.

---

## Summary

An **Undirected Graph** is a versatile data structure for modeling relationships where connections are bidirectional. Its simple adjacency list representation allows efficient insertion, edge creation, and traversal. This structure is widely applicable in real-world scenarios like networks, maps, and social connections. By understanding the core operations and complexity, developers can effectively utilize undirected graphs in various applications.