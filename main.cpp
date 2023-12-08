#include <iostream>
#include "unitTests.h"

int main() {
    testConstructor();
    testDestructor();
    testAddVertex();
    testAddEdge();
    testBFS();

    // Done
    testPrintPath();
    return 0;
}
