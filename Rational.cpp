//#include "stdafx.h"
#include "Rational.h"


Rational::Rational(string polynomial1,string polynomial2)
{
    Polynomial p1(polynomial1);
    Polynomial p2(polynomial2);
    if(p2 == 0)

}

Rational::Rational(Polynomial& polynomial1,string polynomial2)
{
    Polynomial p1 = polynomial1;
    Polynomial p2(polynomial2);
    
}


Rational::~Rational()
{
}