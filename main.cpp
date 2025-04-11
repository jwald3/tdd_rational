#include "RationalTests.h"

int main() {
    TestRunner::runTest("TestConstruction", testConstruction);
    TestRunner::runTest("TestRationalAddition", testRationalAddition);

    return 0;
}