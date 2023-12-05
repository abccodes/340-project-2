// graph.h:

// Header guard to prevent multiple inclusion of the header file
#ifndef PROJECT2_GRAPH_H
#define PROJECT2_GRAPH_H

#include <iostream>
#include <queue>

class graph {
private:
    // Structure representing a node in the adjacency list
    struct Node {
        int v;    // Vertex value
        Node* next;    // Pointer to the next node in the list
    };

    int numVertices;   // Number of vertices in the graph
    Node** adjList;    // Array of pointers to head nodes of the adjacency lists

public:
    // Constructor, marked explicit to prevent implicit conversion
    explicit graph(int numVertices);

    // Destructor
    ~graph();

    // Method to add an edge between source and destination vertices
    void addEdge(int src, int dest);

    // Breadth-First Search (BFS) traversal starting from a given source
    void breadthFistSearch(int vertexS);

    // Method to print BFS traversal starting from a given source
//    void printBFS(int source);

    // Method to print the shortest path from source to destination
//    void printPath(int source, int destination);
};

#endif //PROJECT2_GRAPH_H