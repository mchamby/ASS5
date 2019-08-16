#pragma once
#include "Polynomial.h"

class Rational
{
	friend ostream& operator<< (ostream& os, const Rational& r1);
public:
	Rational(string polynomial1, string polynomial2);
	Rational(string polynomial1, Polynomial& polynomial2);
	Rational(Polynomial& polynomial1, string polynomial2);
	Rational(Polynomial& polynomial1, Polynomial& polynomial2);
	~Rational();
private:
	Polynomial numerator;
	Polynomial denominator;
};