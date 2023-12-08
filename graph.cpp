//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#include "graph.h"
#include <list>

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

    // Initialize the visited array to false for all vertices
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
}

// Destructor for the graph class
graph::~graph() {
    // Loop through each vertex in the graph
    for (int i = 0; i < numVertices; i++) {
        Node* current = adjList[i];

        // Delete all nodes in the adjacency list for the current vertex
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Delete the array of adjacency lists
    delete[] adjList;

    // Delete the array of visited vertices
    delete[] visited;
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

void graph::BFS(int startVertex) {
    // Create an array to keep track of visited vertices
    visited = new bool[numVertices];

    // Initialize all vertices as not visited
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = true;
    queue.push_back(startVertex);

    // BFS loop
    while (!queue.empty()) {
        // Dequeue a vertex from the queue and print it
        int currVertex = queue.front();
        std::cout << "-> " << currVertex << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex
        Node* currentNode = adjList[currVertex];
        while (currentNode != nullptr) {
            // Get the value of the adjacent vertex
            int adjVertex = currentNode->v;

            // If the adjacent vertex is not visited, mark it as visited and enqueue it
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }

            // Move to the next adjacent vertex in the linked list
            currentNode = currentNode->next;
        }
    }

    // Print a newline after the BFS traversal is complete
    std::cout << std::endl;
}

void graph::printPath(int current, int destination) {
    // Check if the current node is the destination
    if (current == destination) {
        std::cout << current << " " << std::endl;
        std::cout << "Found Path" << std::endl;
    } else {
        // Mark the current node as visited before traversing its neighbors
        visited[current] = true;

        // Print the current node and arrow symbol indicating the path
        std::cout << current << "->";

        // Traverse through the neighbors of the current node
        Node* next = adjList[current];
        while (next != nullptr) {
            // Recursively call the function for unvisited neighbor nodes
            if (!visited[next->v]) {
                printPath(next->v, destination);
            }
            next = next->next;
        }

        // Unmark the current node after traversing its neighbors
        visited[current] = false;
    }
}

// Method to print the adjacency list representation of the graph
void graph::printGraph() {
    for (int i = 1; i < numVertices; i++) {
        std::cout << "Vertex " << i << " --> ";
        Node* current = adjList[i];
        while (current != nullptr) {
            std::cout << current->v << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}