#include "RationalTests.h"

int main() {
    TestRunner::runTest("Basic Rational Operations", testRationalBasicOperations);
    TestRunner::runTest("Rational Edge Cases", testRationalEdgeCases);
    TestRunner::runTest("Rational Large Numbers", testRationalLargeNumbers);
    TestRunner::runTest("Rational String Conversion", testRationalStringConversion);
    TestRunner::runTest("Rational Comparison Operators", testRationalComparisonOperators);
    TestRunner::runTest("Rational Unary Operators", testRationalUnaryOperators);
    // TestRunner::runTest("Sign Normalization", testRationalSignNormalization);
    // TestRunner::runTest("Complex Operations", testRationalComplexOperations);
    // TestRunner::runTest("Extreme Values", testRationalExtremeValues);
    // TestRunner::runTest("Reduction with Large Values", testRationalReductionWithLargeValues);
    // TestRunner::runTest("Compound Expressions", testRationalCompoundExpressions);
    // TestRunner::runTest("Special Cases", testRationalSpecialCases);

    return 0;
}