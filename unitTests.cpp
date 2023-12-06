//
// Created by Aidan Bayer-Calvert on 12/4/23.
//

#include "graph.h"
#include <cassert>

void runUnitTests() {
    int rootNode = 1;
    int numVertices = 3;


    // Create a g with 3 vertices
    graph g(numVertices);

    g.addEdge(1,2 );
    g.addEdge(1,3 );
    g.addEdge(3,4 );

    g.printGraph();

    g.breadthFistSearch(rootNode);
    // Create a g with 4 vertices
//    std::cout << "Shortest path from 3 to 0: ";
//    std::cout << "\n";
}

//
//    // Add edges
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
//    g.addEdge(2, 3);
//    g.addEdge(3, 3);
//
//    // Perform BFS from source vertex 2
//    g.BFS(2);
//
//    // Test BFS Tree
//    std::cout << "BFS Tree:\n";
//    g.printBFS(2);
//    std::cout << "\n";
//
//    // Test shortest path
//    std::cout << "Shortest path from 2 to 3: ";
//    g.printPath(2, 3);
//    std::cout << "\n";
//
//    std::cout << "Shortest path from 0 to 3: ";
//    g.printPath(0, 3);
//    std::cout << "\n";
//
//    std::cout << "Shortest path from 1 to 2: ";
//    g.printPath(1, 2);
//    std::cout << "\n";