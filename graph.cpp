//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#include "graph.h"

graph::graph(int numVertices) {
    this->numVertices = numVertices;
    adjList = new Node*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjList[i] = nullptr;
    }
}

graph::~graph() {
    for (int i = 0; i < numVertices; i++) {
        Node* current = adjList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;
}

void graph::addEdge(int src, int dest) {
    Node* newNode = new Node;
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void graph::BFS(int source) {
    enum Color { WHITE, GRAY, BLACK };
    Color* color = new Color[numVertices];
    int* distance = new int[numVertices];
    int* predecessor = new int[numVertices];

    for (int i = 0; i < numVertices; i++) {
        color[i] = WHITE;
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }

    std::queue<int> queue;
    color[source] = GRAY;
    distance[source] = 0;
    predecessor[source] = -1;
    queue.push(source);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        Node* current = adjList[u];
        while (current != nullptr) {
            int v = current->vertex;
            if (color[v] == WHITE) {
                color[v] = GRAY;
                distance[v] = distance[u] + 1;
                predecessor[v] = u;
                queue.push(v);
            }
            current = current->next;
        }
        color[u] = BLACK;
    }

    delete[] color;
    delete[] distance;
    delete[] predecessor;
}

void graph::printBFS(int source) {
    BFS(source);

    std::cout << "BFS Tree from source vertex " << source << ":\n";
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vertex " << i << ": ";
        if (i == source) {
            std::cout << "Source";
        } else if (adjList[i] == nullptr) {
            std::cout << "Not reachable";
        } else {
            int parent = -1;
            Node* current = adjList[i];
            while (current != nullptr) {
                parent = current->vertex;
                current = current->next;
            }
            std::cout << parent;
        }
        std::cout << "\n";
    }
}

void graph::printPath(int source, int destination) {
    if (destination == source) {
        std::cout << source;
    }
    else if (adjList[destination] == nullptr) {
        std::cout << "No path from " << source << " to " << destination << " exists\n";
    }
    else {
        printPath(source, adjList[destination]->vertex);
        std::cout << " -> " << destination;
    }
}