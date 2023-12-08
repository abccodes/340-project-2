#include <iostream>
#include "unitTests.h"

int main() {
    // Running unit tests
    std::cout << "-----------  Unit Tests -----------" << std::endl;
    // WIP
//    testAddVertex();
//    testAddEdge();
//    testPrintPath();
//    testPrintPath();
//    // Done
    testConstructor();
//    testDestructor();
    testBFS();
    printGraph();

    std::cout << "-----------------------------------" << std::endl;

    return 0;
}
