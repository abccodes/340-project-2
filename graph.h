//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#ifndef PROJECT2_GRAPH_H
#define PROJECT2_GRAPH_H

#include <iostream>
#include <queue>

class graph {
private:
    struct Node {
        int vertex;
        Node* next;
    };

    Node** adjList; // Array of pointers to head nodes of the adjacency lists
    int numVertices;

public:
    graph(int numVertices);
    ~graph();
    void addEdge(int src, int dest);
    void BFS(int source);
    void printBFS(int source);
    void printPath(int source, int destination);
};

#endif //PROJECT2_GRAPH_H