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

    Rational operator+(const Rational& R);
    Rational operator-(const Rational& R);
    Rational operator*(const Rational& R);
    Rational operator/(const Rational& R);

    bool operator==(const Rational& R);
    bool operator!=(const Rational& R);
    bool operator<(const Rational& R);
    bool operator>(const Rational& R);
    bool operator<=(const Rational& R);
    bool operator>=(const Rational& R);

    Rational operator-() const;
    Rational operator+() const;

    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);

    friend std::ostream& operator<<(std::ostream& out,
                                    const Rational& rational);
};