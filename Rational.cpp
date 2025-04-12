#include "Rational.h"

#include <stdexcept>
#include <iostream>

int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Rational::Rational() {}
Rational::Rational(int num, int den) {
    if (den == 0) {
        throw std::invalid_argument("denominator cannot be zero.");
    }

    int divisor = gcd(num, den);
    numerator = num / divisor;
    denominator = den / divisor;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int Rational::getNumerator() const { return numerator; }
int Rational::getDenominator() const { return denominator; }

int Rational::getCommonDenominator(const Rational &L, const Rational &R) {
    if (L.getDenominator() == R.getDenominator())
        return L.getDenominator();
    else
        return L.getDenominator() * R.getDenominator();
}

Rational operator+(const Rational &L, const Rational &R) {
    int lDenom = L.getDenominator();
    int rDenom = R.getDenominator();

    int denominator = Rational::getCommonDenominator(L, R);

    int numerator{0};

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

Rational operator-(const Rational &L, const Rational &R) {
    int commonDenominator = Rational::getCommonDenominator(L, R);
    int LNumerator =
        (commonDenominator / L.getDenominator()) * L.getNumerator();
    int RNumerator =
        (commonDenominator / R.getDenominator()) * R.getNumerator();

    return Rational(
        LNumerator - RNumerator,
        commonDenominator);
}

bool operator==(const Rational &L, const Rational &R) {
    return L.getNumerator() == R.getNumerator() &&
           L.getDenominator() == R.getDenominator();
}

std::ostream &operator<<(std::ostream &out, const Rational &rational) {
    out << '(' << rational.getNumerator() << '/' << rational.getDenominator()
        << ')';
    return out;
}
