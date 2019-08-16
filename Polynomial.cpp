//#include "stdafx.h"
#include "Polynomial.h"


Polynomial::Polynomial(string input)
{
	const int maxNumOfSegments = 10;
	string segments[maxNumOfSegments] = { "" }; // the element of the segment corresponds to the power of x
	
	// separating the input string into segments
	while (input.empty() == false)
	{
		int first = input.find_last_of("+-");
		int powerOfX = (input.back() - 48);	// this only works for 1 digit powers
		segments[powerOfX].assign(input.substr(first));
		cout << segments[powerOfX] << " ";	// printing the parsed segment
		input.erase(first);	// erase the parsed segment from the input string
	}

	// put the coefficients into the coefficients vector
	for (int i = 0; i < maxNumOfSegments; ++i)
	{
		// check if there is a string in this element
		// we don't want to perform operations on an empty string!
		if (segments[i].empty() == false)
		{
			coefficients.push_back(getValueAfterSign(segments[i]));
		}
		else coefficients.push_back(0.0);
	}

	cout << '\n';
	// printing all coefficients
	for (int i = 0; i < 10; ++i)
	{
		cout << coefficients[i] << ' ';
	}
}


Polynomial::~Polynomial()
{
}

int Polynomial::getValueAfterX(string segment) const
{
	int xIndex = segment.find('x');
	return segment[xIndex + 1];
}

double Polynomial::getValueAfterSign(string segment) const
{
	int signIndex = segment.find("+-");
	int xIndex = segment.find('x');
	string valueString = segment.substr(signIndex + 1, xIndex - signIndex);
	double value = stod(valueString);
	return value;
}
