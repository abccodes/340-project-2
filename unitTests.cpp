//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#include "graph.h"
#include <cassert>

void demo() {
    int numVertices = 1;

    graph g(numVertices);

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
    // Create a graph with a few vertices and edges
    graph g(5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Perform BFS or any other operations if needed

    // Call the destructor explicitly
    g.~graph();

    // At this point, the destructor should have freed all allocated memory

    // If you want to check for memory leaks, you might use a memory profiler
    // or tools like Valgrind.

    // Example check (not exhaustive)
    // In a real test framework, you would use assertions.
    if (g.getNumVertices() != 0) {
        std::cerr << "Test failed: Destructor did not deallocate memory properly." << std::endl;
    } else {
        std::cout << "Test passed: Destructor deallocated memory properly." << std::endl;
    }
}

void testAddVertex() {


}

void testAddEdge() {

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
    g.printPath(2,3);


}

// Testing if print path is working as expected
void testPrintPath() {
    // Create a graph with 4 vertices
    graph g(3);

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

    g.printPath(1, 4);

    std::cout << "\n";
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