#include "RationalTests.h"

int main() {
    TestRunner::runTest("Basic Rational Operations", testRationalBasicOperations);
    TestRunner::runTest("Rational Edge Cases", testRationalEdgeCases);
    // TestRunner::runTest("Rational Large Numbers", testRationalLargeNumbers);
    // TestRunner::runTest("Rational String Conversion", testRationalStringConversion);
    // TestRunner::runTest("Rational Comparison Operators", testRationalComparisonOperators);
    // TestRunner::runTest("Rational Unary Operators", testRationalUnaryOperators);
    
    return 0;
}