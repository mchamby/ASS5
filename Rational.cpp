//#include "stdafx.h"
#include "Rational.h"


Rational::Rational(string polynomial1, string polynomial2)
	: numerator(Polynomial(polynomial1)), denominator(Polynomial(polynomial2))
{
}

Rational::Rational(string polynomial1, Polynomial & polynomial2)
	: numerator(Polynomial(polynomial1)), denominator(polynomial2)
{
}

Rational::Rational(Polynomial& polynomial1, string polynomial2)
	: numerator(polynomial1), denominator(Polynomial(polynomial2))
{
}

Rational::Rational(Polynomial & polynomial1, Polynomial & polynomial2)
	: numerator(polynomial1), denominator(polynomial2)
{
}

double Rational::operator () (const double x) const
{
  const double num = numerator(x);
  const double denom = denominator(x);

  try
  {
    if (denom == 0)
      throw DivisionByZero();
  }
  catch (DivisionByZero& e)
  {
    cout << e.what() << '\n';
    return 0.0;
  }
  
  return (num / denom);
}


ostream & operator << (ostream & os, const Rational & r1)
{
	os << r1.numerator << "\n-----------------------------------\n" << r1.denominator;

	return os;
}
