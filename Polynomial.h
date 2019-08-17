#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include "Exception.h"
#include "DivisionByZero.h"
#include "InvalidPower.h"
#include "InvalidString.h"

using namespace std;

class Polynomial
{
	friend ostream& operator << (ostream& os, const Polynomial& rhs);
public:
	Polynomial(string input);
	Polynomial(const Polynomial& rhs);
	~Polynomial();
	void testForInvalidString(string input);
	void testForInvalidPower(string input);
  double operator() (double x) const;
private:
	vector<double> coefficients; // the element of the vector corresponds to the power of x
};

