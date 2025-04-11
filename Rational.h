#pragma once
#include <ostream>

class Rational {
private:
    int numerator{};
    int denominator{};
public:
    Rational();
    Rational(int numerator, int denominator);

    int getNumerator() const;

    int getDenominator() const;

    static int getCommonDenominator(Rational& L, Rational& R);
};

Rational operator+(const Rational& L, const Rational& R);
Rational operator-(const Rational& L, const Rational& R);
bool operator==(const Rational& L, const Rational& R);
std::ostream& operator<<(std::ostream& out, const Rational& rational);
