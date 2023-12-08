// graph.h:

// Header guard to prevent multiple inclusion of the header file
#ifndef PROJECT2_GRAPH_H
#define PROJECT2_GRAPH_H

#include <iostream>
#include <queue>
#include <list>

class graph {
private:
    // Structure representing a node in the adjacency list
    struct Node {
        int v;    // Vertex value
        Node* next;    // Pointer to the next node in the list
    };

    bool* visited;
    int numVertices;   // Number of vertices in the graph
    Node** adjList;    // Array of pointers to head nodes of the adjacency lists

public:
    // Getters
    [[nodiscard]] int getNumVertices() const { return numVertices; }

    // Constructor, marked explicit to prevent implicit conversion
    explicit graph(int numVertices);

    // Destructor
    ~graph();

    // Method to add a new vertex to the graph
    void addVertex();

    // Method to add an edge between source and destination vertices
    void addEdge(int src, int dest);

    // Breadth-First Search (BFS) traversal starting from a given source
    // Also prints BFS traversal of graph starting at vertex
    void BFS(int vertexS);

    // Method to print the path from source to destination
    void printPath(int current, int destination);

    // Method to print the whole graph
    void printGraph();

};

#endif //PROJECT2_GRAPH_H