#include "Rational.h"

#include <stdexcept>
#include <iostream>

int findGCD(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    
    return a;
}

Rational::Rational() {}
Rational::Rational(int num, int den) {
    if (den == 0) throw std::invalid_argument("cannot pass 0 in the denominator");

    if (num == 0) {
        numerator = 0;
        denominator = 1;
        return;
    }

    int gcd = findGCD(num, den);

    numerator = num / gcd;
    denominator = den / gcd;
}

int Rational::getNumerator() const { return numerator; }
int Rational::getDenominator() const { return denominator; }

Rational Rational::operator+(const Rational &R) {
    if (R.getDenominator() == 0) throw std::invalid_argument("cannot pass 0 in the denominator");

    if (denominator == R.getDenominator()) {
        return Rational(numerator + R.getNumerator(), denominator);
    }

    return Rational((numerator * R.getDenominator()) + (R.getNumerator() * denominator), denominator * R.getDenominator());
}

Rational Rational::operator-(const Rational &R) {
    if (R.getDenominator() == 0) throw std::invalid_argument("cannot pass 0 in the denominator");

    if (denominator == R.getDenominator()) {
        return Rational(numerator - R.getNumerator(), denominator);
    }
    
    return Rational((numerator * R.getDenominator()) - (R.getNumerator() * denominator), denominator * R.getDenominator());
}

Rational Rational::operator*(const Rational &R) {
    if (R.getDenominator() == 0) throw std::invalid_argument("cannot pass 0 in the denominator");

    return Rational((numerator * R.getNumerator()), (R.getDenominator() * denominator));
}

Rational Rational::operator/(const Rational &R) {
    if (R.getDenominator() == 0) throw std::invalid_argument("cannot pass 0 in the denominator");

    return Rational((numerator * R.getDenominator()), (R.getNumerator() * denominator));
}

bool Rational::operator==(const Rational &R) {
    return (numerator == R.getNumerator()) && (denominator == R.getDenominator());
}

bool Rational::operator!=(const Rational &R) {
    return (numerator != R.getNumerator()) || (denominator != R.getDenominator());
}

bool Rational::operator<=(const Rational &R) {
    return true;
}

bool Rational::operator>=(const Rational &R) {
    return true;
}

bool Rational::operator<(const Rational &R) {
    return true;
}

bool Rational::operator>(const Rational &R) {
    return true;
}

Rational Rational::operator-() const {
    return Rational(1, 1);
}

Rational Rational::operator+() const {
    return Rational(1, 1);
}

Rational& Rational::operator++() {
    return *this;
}

Rational Rational::operator++(int margin) {
    return Rational(1, 1);
}

Rational& Rational::operator--() {
    return *this;
}

Rational Rational::operator--(int margin) {
    return Rational(1, 1);
}


std::ostream &operator<<(std::ostream &out, const Rational &rational) {
    out << '(' << rational.getNumerator() << '/' << rational.getDenominator()
        << ')';
    return out;
}