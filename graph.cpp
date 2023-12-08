//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#include "graph.h"

// Constructor for the graph class
graph::graph(int numVertices) {
    numVertices++;
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

// Method to add a new vertex to the graph
void graph::addVertex() {
    // Create a new array with increased size
    int newNumVertices = numVertices + 1;
    Node** newAdjList = new Node*[newNumVertices];

    // Copy existing adjacency list to the new array
    for (int i = 0; i < numVertices; i++) {
        newAdjList[i] = adjList[i];
    }

    // Initialize the new vertex with nullptr
    newAdjList[numVertices] = nullptr;

    // Delete the old adjacency list
    delete[] adjList;

    // Update the member variables with the new values
    adjList = newAdjList;
    numVertices = newNumVertices;
}

// Method to add an edge between source and destination vertices
void graph::addEdge(int src, int dest) {
    // Create a new node for the destination vertex
    Node* newNode = new Node;
    newNode->v = dest;
    newNode->next = nullptr;

    // If the adjacency list for the source vertex is empty, set the new node as the head
    if (adjList[src] == nullptr) {
        adjList[src] = newNode;
    } else {
        // Otherwise, find the last node in the adjacency list and add the new node
        Node* last = adjList[src];
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void graph::breadthFistSearch(int vertexS) {}

void graph::printBFS(int vertexS) {}

void graph::printPath(int source, int current) {
    // Base case: If the current vertex is the source, print it
    if (current == source) {
        std::cout << source;
    }
    // If the adjacency list for the current vertex is empty, no path exists
    else if (adjList[current] == nullptr) {
        std::cout << "No path from " << source << " to " << current << " exists\n";
    }
    else {
        // Recursively call printPath for the predecessor vertex
        printPath(source, adjList[current]->v);
        std::cout << " -> " << current;
    }
}

// Method to print the adjacency list representation of the graph
//void graph::printGraph() {
//    for (int i = 1; i < numVertices; i++) {
//        std::cout << "Vertex " << i << " --> ";
//        Node* current = adjList[i];
//        while (current != nullptr) {
//            std::cout << current->v << " ";
//            current = current->next;
//        }
//        std::cout << std::endl;
//    }
//}