#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Polynomial
{
public:
	Polynomial(string input);

	~Polynomial();

	int getValueAfterX(string segment) const;
	double getValueAfterSign(string segment) const;

private:
	vector<double> coefficients; // the element of the vector corresponds to the power of x
};