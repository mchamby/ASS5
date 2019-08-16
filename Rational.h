#pragma once
#include "Polynomial.h"

class Rational
{
	friend ostream& operator<< (ostream& os,const Rational& r1);
public:
	Rational(string poly1,string poly2);
	Rational(string poly1,Polynomial& poly2);
	Rational(Polynomial& poly1,string poly2);
	Rational(Polynomial& poly1,Polynomial& poly2);
	~Rational();
private:
	//Polynomial numerator;
	//Polynomial denominator;
};

