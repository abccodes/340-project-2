//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#include "graph.h"

void demo() {
    int numVertices = 8;
    int source = 6;
    int destination = 2;

    graph g(numVertices);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);
    g.addEdge(2, 7);
    g.addEdge(3, 4);
    g.addEdge(5, 6);

    std::cout << "bfs" << std::endl;
    g.BFS(source);
    std::cout << "print path" << std::endl;
    g.printPath(source, destination);

}

void testConstructor() {
    int numVertices = 3;

    // Create a graph with 3 vertices
    graph g(numVertices);

    numVertices++;

    // Verify that the number of vertices is initialized correctly
    if (g.getNumVertices() == numVertices) {
        std::cout << "Graph constructor Passed" << std::endl;
    } else {
        std::cerr << "Graph constructor test failed: Incorrect number of vertices" << std::endl;
    }
}

void testDestructor() {
    int numVerticles = 5;
    // Create a graph with a few vertices and edges
    graph g(numVerticles);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Perform BFS or any other operations if needed

    // Call the destructor explicitly
    g.~graph();

    // Example check
    if (g.getNumVertices() == 0) {
        std::cerr << "Test failed: Destructor did not deallocate memory properly." << std::endl;
    } else {
        std::cout << "Destructor Test passed" << std::endl;
    }
}

void testAddVertex() {
    int numVertex = 1;

    // Create a graph
    graph g(numVertex);  // Initial graph with one vertex

    // Add a new vertex
    g.addVertex();

    // Plus 2 because the constructor adds 1 so vertex cant be 0
    numVertex = numVertex + 2;

    // Check if the number of vertices is incremented
    if(g.getNumVertices() == numVertex) {
        std::cout << "Vertices Test passed" << std::endl;
    } else {
        std::cout << "Vertices Test failed" << std::endl;
    }
}

void testAddEdge() {
    int numVertex = 3;

    graph g (numVertex);

    // Add edges
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 2);

    std::cout << "Graph after adding edges:" << std::endl;
    g.printGraph();

    // Shows that the edges are being added correctly
}

void testBFS() {
    int numVerticles = 4;

    graph g (numVerticles);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    //expected output matches - >-> 2 -> 0 -> 3 -> 1
    // Is performing as expected
}

// Testing if print path is working as expected
void testPrintPath() {
    // Create a graph with 4 vertices
    graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.printPath(1, 4);

}

void printGraph() {
    graph g(6);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 3);
    g.addEdge(2, 4);

    g.printGraph();

}