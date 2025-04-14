#include "TestRunner.h"
#include "Rational.h"
#include <stdexcept>
#include <limits>
#include <sstream>
#include <cstdint>

// Basic Rational Tests
bool testRationalBasicOperations() {
    // Test construction and equality
    Rational a(1, 2);
    Rational b(2, 4);
    Rational c(1, 3);

    // Test that Rational automatically reduces to lowest form
    bool result = ASSERT_EQ(a, b);
    
    // Test inequality
    result = result && ASSERT_EQ(false, a == c);

    // Test addition
    Rational sum = a + c;  // 1/2 + 1/3 = 5/6
    result = result && ASSERT_EQ(Rational(5, 6), sum);

    // Test subtraction
    Rational diff = a - c;  // 1/2 - 1/3 = 1/6
    result = result && ASSERT_EQ(Rational(1, 6), diff);

    // Test multiplication
    Rational product = a * c;  // 1/2 * 1/3 = 1/6
    result = result && ASSERT_EQ(Rational(1, 6), product);

    // Test division
    Rational quotient = a / c;  // 1/2 / 1/3 = 3/2
    result = result && ASSERT_EQ(Rational(3, 2), quotient);
    
    return result;
}

// Edge Case Tests
bool testRationalEdgeCases() {
    bool result = true;
    
    // Test zero denominator handling
    try {
        Rational invalid(1, 0);
        result = false;  // Should not reach here
    } catch (const std::invalid_argument&) {
        // Expected exception
    } catch (...) {
        result = false;  // Wrong exception type
    }
    
    // Test zero numerator
    Rational zero(0, 5);
    result = result && ASSERT_EQ(Rational(0, 1), zero);
    
    // Test negative numbers handling
    Rational neg1(-1, 2);
    Rational neg2(1, -2);
    Rational neg3(-1, -2);
    
    // Negative in numerator or denominator should be normalized
    result = result && ASSERT_EQ(neg1, neg2);
    // Double negative should be positive
    result = result && ASSERT_EQ(Rational(1, 2), neg3);
    
    // Test addition with zero
    result = result && ASSERT_EQ(neg1, zero + neg1);
    
    // Test multiplication with zero
    result = result && ASSERT_EQ(zero, zero * neg1);
    
    // Test division by zero
    try {
        neg1 / zero;
        result = false;  // Should not reach here
    } catch (const std::invalid_argument&) {
        // Expected exception
    } catch (...) {
        result = false;  // Wrong exception type
    }
    
    return result;
}

// Large Number Handling Test
bool testRationalLargeNumbers() {
    // Test with large integers that could cause overflow
    int64_t largeNum = std::numeric_limits<int32_t>::max();
    int64_t largeNum2 = largeNum - 1;
    
    Rational large1(largeNum, largeNum2);
    Rational large2(largeNum2, largeNum);
    
    // These operations could cause overflow if not handled properly
    Rational product = large1 * large2;
    
    // Expected results (calculated manually or verified)
    // For product: (largeNum/largeNum2) * (largeNum2/largeNum) = 1
    
    bool result = ASSERT_EQ(Rational(1, 1), product);
    
    // Test that the result is in the simplified form
    // This is particularly important for large numbers
    result = result && (product.getNumerator() == 1 && product.getDenominator() == 1);
    
    return result;
}

// String Conversion Test
bool testRationalStringConversion() {
    Rational r1(1, 2);
    Rational r2(-3, 4);
    Rational r3(5, 1);
    Rational r4(0, 7);
    
    std::stringstream ss1, ss2, ss3, ss4;
    ss1 << r1;
    ss2 << r2;
    ss3 << r3;
    ss4 << r4;
    
    bool result = ASSERT_EQ("1/2", ss1.str());
    result = result && ASSERT_EQ("-3/4", ss2.str());
    result = result && ASSERT_EQ("5", ss3.str());  // Integer should be displayed without denominator
    result = result && ASSERT_EQ("0", ss4.str());  // Zero should be displayed as 0
    
    return result;
}

// Comparison Operators Test
bool testRationalComparisonOperators() {
    Rational a(1, 2);
    Rational b(2, 3);
    Rational c(1, 2);
    
    bool result = ASSERT_EQ(true, a < b);
    result = result && ASSERT_EQ(false, b < a);
    result = result && ASSERT_EQ(true, a <= c);
    result = result && ASSERT_EQ(true, a >= c);
    result = result && ASSERT_EQ(false, a > c);
    result = result && ASSERT_EQ(true, b > a);
    
    return result;
}

// Unary Operators Test
bool testRationalUnaryOperators() {
    Rational a(1, 2);
    Rational b(-1, 2);
    
    // Test unary minus
    Rational negA = -a;
    bool result = ASSERT_EQ(b, negA);
    
    // Test unary plus (should be a no-op)
    Rational posA = +a;
    result = result && ASSERT_EQ(a, posA);
    
    // Test prefix increment
    Rational c(1, 2);
    Rational d = ++c;  // c becomes 3/2, d should be 3/2
    result = result && ASSERT_EQ(Rational(3, 2), c);
    result = result && ASSERT_EQ(Rational(3, 2), d);
    
    // Test postfix increment
    Rational e(1, 2);
    Rational f = e++;  // e becomes 3/2, f should be 1/2
    result = result && ASSERT_EQ(Rational(3, 2), e);
    result = result && ASSERT_EQ(Rational(1, 2), f);
    
    // Test prefix decrement
    Rational g(3, 2);
    Rational h = --g;  // g becomes 1/2, h should be 1/2
    result = result && ASSERT_EQ(Rational(1, 2), g);
    result = result && ASSERT_EQ(Rational(1, 2), h);
    
    // Test postfix decrement
    Rational i(3, 2);
    Rational j = i--;  // i becomes 1/2, j should be 3/2
    result = result && ASSERT_EQ(Rational(1, 2), i);
    result = result && ASSERT_EQ(Rational(3, 2), j);
    
    return result;
}

// Test for sign normalization
bool testRationalSignNormalization() {
    // All of these should be equivalent to 1/2
    Rational a(1, 2);
    Rational b(-1, -2);
    Rational c(2, 4);
    Rational d(-2, -4);
    
    bool result = ASSERT_EQ(a, b);
    result = result && ASSERT_EQ(a, c);
    result = result && ASSERT_EQ(a, d);
    
    // All of these should be equivalent to -1/2
    Rational e(-1, 2);
    Rational f(1, -2);
    Rational g(-2, 4);
    Rational h(2, -4);
    
    result = result && ASSERT_EQ(e, f);
    result = result && ASSERT_EQ(e, g);
    result = result && ASSERT_EQ(e, h);
    
    return result;
}

// Test for complex fractions
bool testRationalComplexOperations() {
    Rational a(3, 4);
    Rational b(5, 8);
    Rational c(2, 5);
    
    // Test more complex addition: 3/4 + 5/8 = 11/8
    Rational sum = a + b;
    bool result = ASSERT_EQ(Rational(11, 8), sum);
    
    // Test chained operations: (3/4 + 5/8) * 2/5 = 11/8 * 2/5 = 11/20
    Rational complex = sum * c;
    result = result && ASSERT_EQ(Rational(11, 20), complex);
    
    // Test complex subtraction: 3/4 - 5/8 = 1/8
    Rational diff = a - b;
    result = result && ASSERT_EQ(Rational(1, 8), diff);
    
    // Test division with simplification: (3/4) / (2/5) = (3/4) * (5/2) = 15/8
    Rational quotient = a / c;
    result = result && ASSERT_EQ(Rational(15, 8), quotient);
    
    return result;
}

// Test for repeated operations and compound expressions
bool testRationalCompoundExpressions() {
    Rational a(1, 2);
    Rational b(1, 3);
    Rational c(1, 4);
    
    // Test compound expression: a + b - c = 1/2 + 1/3 - 1/4 = 7/12
    Rational result1 = a + b - c;
    bool result = ASSERT_EQ(Rational(7, 12), result1);
    
    // Test another compound expression: a * b / c = 1/2 * 1/3 / 1/4 = 1/2 * 1/3 * 4/1 = 2/3
    Rational result2 = a * b / c;
    result = result && ASSERT_EQ(Rational(2, 3), result2);
    
    // Test complex compound expression: (a + b) * (a - c) / (b + c)
    // (1/2 + 1/3) * (1/2 - 1/4) / (1/3 + 1/4)
    // (5/6) * (1/4) / (7/12) = 5/6 * 1/4 * 12/7 = 5/6 * 3/7 = 5/14
    Rational result3 = (a + b) * (a - c) / (b + c);
    result = result && ASSERT_EQ(Rational(5, 14), result3);
    
    return result;
}

// Test for boundary/special cases
bool testRationalSpecialCases() {
    // Test integers
    Rational a(5, 1);
    Rational b(5);  // Optional: Test a constructor that takes just numerator
    
    // Test negatives with reduction
    Rational c(-15, 20);
    
    bool result = ASSERT_EQ(Rational(-3, 4), c);
    
    // Test multiple increments/decrements
    Rational d(1, 2);
    d++; // 3/2
    d++; // 5/2
    result = result && ASSERT_EQ(Rational(5, 2), d);
    
    d--; // 3/2
    d--; // 1/2
    result = result && ASSERT_EQ(Rational(1, 2), d);
    
    // Test chained increments/decrements
    Rational e(1, 2);
    Rational f = ++(++e);  // e becomes 5/2, f becomes 5/2
    result = result && ASSERT_EQ(Rational(5, 2), e);
    result = result && ASSERT_EQ(Rational(5, 2), f);
    
    return result;
}

