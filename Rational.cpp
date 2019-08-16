//#include "stdafx.h"
#include "Rational.h"


Rational::Rational(string polynomial1, string polynomial2)
	: numerator(Polynomial(polynomial1)), denominator(Polynomial(polynomial2))
{
}

Rational::Rational(Polynomial& polynomial1, string polynomial2)
	: numerator(polynomial1), denominator(Polynomial(polynomial2))
{
}


Rational::~Rational()
{
}