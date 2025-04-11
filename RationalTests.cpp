#include "RationalTests.h"
#include "TestRunner.h"

bool testRationalAddition() {
    Rational r1(1, 2);      // Represents 1/2
    Rational r2(1, 3);      // Represents 1/3

    Rational rationalSum = r1 + r2;

    bool positiveRationalAdditionSum = 
        ASSERT_EQ(Rational(5, 6), rationalSum);

    Rational r3(-1, 2);     // Represents -1/2
    Rational r4(1, 2);      // Represents 1/2

    Rational rationalCanceledSum = r3 + r4;
    
    bool canceledOutRationalAdditionSum = 
        ASSERT_EQ(Rational(0, 1), rationalCanceledSum);

    Rational r5(1, 2);       // Represents 1/2
    Rational r6(-2, 3);      // Represents -2/3

    Rational rationalNegativeSum = r5 + r6;
    
    bool negativeOutRationalAdditionSum = 
        ASSERT_EQ(Rational(-1, 6), rationalNegativeSum);

    return positiveRationalAdditionSum && canceledOutRationalAdditionSum && negativeOutRationalAdditionSum;
}