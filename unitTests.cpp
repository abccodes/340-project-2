//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#include "graph.h"
#include <cassert>

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


}

void testAddVertex() {


}

void testAddEdge() {

}

void testBFS() {

}

// Testing if print path is working as expected
void testPrintPath() {
    // Create a graph with 4 vertices
    graph g(4);

    // Add edges
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    std::cout << "Print Path";
    g.printPath(1, 4);

    std::cout << "\n";
}