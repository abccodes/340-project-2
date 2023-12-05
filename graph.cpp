//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#include "graph.h"

// Constructor for the graph class
graph::graph(int numVertices) {
    // Initializing the number of vertices in the graph
    this->numVertices = numVertices;

    // Creating an array of pointers to Node objects for the adjacency list
    adjList = new Node*[numVertices];

    // Initializing each element of the adjacency list to nullptr
    for (int i = 0; i < numVertices; i++) {
        adjList[i] = nullptr;
    }
}

// Destructor for the graph class
graph::~graph() {
    // Loop through each vertex in the graph
    for (int i = 0; i < numVertices; i++) {
        Node* current = adjList[i];

        // Delete all nodes in the adjacency list for the current v
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Delete the array of adjacency lists
    delete[] adjList;
}

// Method to add an edge between source and destination vertices
void graph::addEdge(int src, int dest) {
    // Create a new node for the destination v
    Node* newNode = new Node;
    newNode->v = dest;

    // Add the new node to the beginning of the adjacency list for the source v
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void graph::breadthFistSearch(int vertexS) {
    // Array to keep track of visited vertices
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    std::queue<int> bfsQueue;

    // Mark the current node as visited and enqueue it
    visited[vertexS] = true;
    bfsQueue.push(vertexS);

    // Loop to visit all vertices in BFS order
    while (!bfsQueue.empty()) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = bfsQueue.front();
        std::cout << currentVertex << " ";
        bfsQueue.pop();

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex is not visited, mark it as visited and enqueue it
        Node* current = adjList[currentVertex];
        while (current != nullptr) {
            int adjacentVertex = current->v;
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                bfsQueue.push(adjacentVertex);
            }
            current = current->next;
        }
    }
    // Clean up allocated memory
    delete[] visited;
}

//
//void graph::BFS(int source) {
//    enum Color { WHITE, GRAY, BLACK };
//    Color* color = new Color[numVertices];
//    int* distance = new int[numVertices];
//    int* predecessor = new int[numVertices];
//
//    for (int i = 0; i < numVertices; i++) {
//        color[i] = WHITE;
//        distance[i] = INT_MAX;
//        predecessor[i] = -1;
//    }
//
//    std::queue<int> queue;
//    color[source] = GRAY;
//    distance[source] = 0;
//    predecessor[source] = -1;
//    queue.push(source);
//
//    while (!queue.empty()) {
//        int u = queue.front();
//        queue.pop();
//
//        Node* current = adjList[u];
//        while (current != nullptr) {
//            int v = current->v;
//            if (color[v] == WHITE) {
//                color[v] = GRAY;
//                distance[v] = distance[u] + 1;
//                predecessor[v] = u;
//                queue.push(v);
//            }
//            current = current->next;
//        }
//        color[u] = BLACK;
//    }
//
//    delete[] color;
//    delete[] distance;
//    delete[] predecessor;
//}
//
//void graph::printBFS(int source) {
//    BFS(source);
//
//    std::cout << "BFS Tree from source v " << source << ":\n";
//    for (int i = 0; i < numVertices; i++) {
//        std::cout << "v " << i << ": ";
//        if (i == source) {
//            std::cout << "Source";
//        } else if (adjList[i] == nullptr) {
//            std::cout << "Not reachable";
//        } else {
//            int parent = -1;
//            Node* current = adjList[i];
//            while (current != nullptr) {
//                parent = current->v;
//                current = current->next;
//            }
//            std::cout << parent;
//        }
//        std::cout << "\n";
//    }
//}
//
//void graph::printPath(int source, int destination) {
//    if (destination == source) {
//        std::cout << source;
//    }
//    else if (adjList[destination] == nullptr) {
//        std::cout << "No path from " << source << " to " << destination << " exists\n";
//    }
//    else {
//        printPath(source, adjList[destination]->v);
//        std::cout << " -> " << destination;
//    }
//}