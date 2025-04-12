#include "RationalTests.h"

int main() {
    TestRunner::runTest("TestConstruction", testConstruction);
    TestRunner::runTest("TestRationalAddition", testRationalAddition);
    TestRunner::runTest("TestRationalSubtraction", testRationalSubtraction);

    return 0;
}