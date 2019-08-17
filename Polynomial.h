#pragma once
#include "math.h"
#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include "Exception.h"
#include "DivisionByZero.h"
#include "InvalidPower.h"
#include "InvalidString.h"

using namespace std;

class Polynomial
{
	friend istream& operator >> (istream& is, Polynomial& rhs);
	friend ostream& operator << (ostream& os, const Polynomial& rhs);
	friend Polynomial operator+ (const Polynomial & p1, const Polynomial & p2);
	friend Polynomial operator- (const Polynomial & p1, const Polynomial & p2);
	friend const Polynomial operator* (const Polynomial& p, double z);
	friend int findSmallerPoly(const Polynomial & p1, const Polynomial & p2);
	friend int findLargerPoly(const Polynomial & p1, const Polynomial & p2);
	friend bool returnLargerPoly(const Polynomial& p1, const Polynomial & p2);
public:
	Polynomial(string input);
	Polynomial(const Polynomial& rhs);
	~Polynomial();
	void testForInvalidString(string input);
	void testForInvalidPower(string input);
	double operator() (double x) const;
	double operator[] (int n) const;
	double & operator[] (int n);
private:
	vector<double> coefficients; // the element of the vector corresponds to the power of x
};