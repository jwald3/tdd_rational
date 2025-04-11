#include "Rational.h"
#include <iostream>

Rational::Rational(){}
Rational::Rational(int num, int den) {
        int greatestCommonMultiple { 1 };

        for (int i { num }; i > 1; --i) {
            if (num % i == 0 && den % i == 0) {
                greatestCommonMultiple = i;
                break;
            }
        }

        numerator = num / greatestCommonMultiple;
        denominator = den / greatestCommonMultiple;
    }

int Rational::getNumerator() const { return numerator; }
int Rational::getDenominator() const { return denominator; }

Rational operator + (const Rational &L, const Rational &R) {
    int lDenom = L.getDenominator();
    int rDenom = R.getDenominator();

    int denominator = lDenom == rDenom ? lDenom : lDenom * rDenom;

    int numerator { 0 };

    if (denominator == lDenom) {
        numerator = L.getNumerator() + R.getNumerator();
        
    } else {
        numerator = (L.getNumerator() * rDenom) + (R.getNumerator() * lDenom);
    }

    if (numerator == 0) {
        denominator = 1;
    }

    return Rational(numerator, denominator);
}

Rational operator - (const Rational &l, const Rational &R) {
    return Rational(1, 1);
}

bool operator == (const Rational &L, const Rational &R) {
    return L.getNumerator() == R.getNumerator() && L.getDenominator() == R.getDenominator();
}

std::ostream& operator<<(std::ostream& out, const Rational& rational) {
    out << '(' << rational.getNumerator() << '/' << rational.getDenominator() << ')';
    return out;
}