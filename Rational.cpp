#include "Rational.h"

#include <stdexcept>
#include <iostream>

Rational::Rational() {}
Rational::Rational(int num, int den) {
    numerator = num;
    denominator = num;
}

int Rational::getNumerator() const { return numerator; }
int Rational::getDenominator() const { return denominator; }

Rational Rational::operator+(const Rational &R) {
    return Rational();
}

Rational Rational::operator-(const Rational &R) {
    return Rational();
}

Rational Rational::operator*(const Rational &R) {
    return Rational();
}

Rational Rational::operator/(const Rational &R) {
    return Rational();
}

bool Rational::operator==(const Rational &R) {
    return true;
}

bool Rational::operator!=(const Rational &R) {
    return true;
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
    return Rational();
}

Rational Rational::operator+() const {
    return Rational();
}

Rational& Rational::operator++() {
    return *this;
}

Rational Rational::operator++(int margin) {
    return Rational();
}

Rational& Rational::operator--() {
    return *this;
}

Rational Rational::operator--(int margin) {
    return Rational();
}


std::ostream &operator<<(std::ostream &out, const Rational &rational) {
    out << '(' << rational.getNumerator() << '/' << rational.getDenominator()
        << ')';
    return out;
}