// Assignment 5.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "Polynomial.h"
#include "Rational.h"

int main()
{
	string input = "+4.5x^8+3.4x^3-6.4x^1+3.1x^0";
	Polynomial p1(input);
	string input2 = "+12.0x^1-50.0x^0";
	Polynomial p2(input2);
	Polynomial p3 = p1;
	cout << '\n';

	cout << "\n\n";

	Rational r1(p1, p2);
	cout << r1 << '\n';

    return 0;
}