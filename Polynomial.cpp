//#include "stdafx.h"
#include "Polynomial.h"


Polynomial::Polynomial(string input)
{
	try
	{
		// we need to get the coefficients from the string input
		int counter = 0;	// counter for the while loop

		// keep parsing coefficients until the input string is empty
		while (input.empty() == false)
		{
			int lastSignIndex = input.find_last_of("+-");
			int lastPowerIndex = input.find_last_of("^") + 1;
			int powerOfX = stoi(input.substr(lastPowerIndex));

			if (powerOfX == counter)
			{
				// get the coefficient from the string and add it to the vector
				string coeffString = input.substr(lastSignIndex, lastPowerIndex - 2 - lastSignIndex);
				double coeff = stod(coeffString);
				coefficients.push_back(coeff);

				// remove this part of the the input string and move on to the next
				input.erase(input.find_last_of("+-"));
			}
			// if the power of x in the rightmost term doesn't match counter,
			// we put a 0 as that coefficient
			else coefficients.push_back(0.0);
			++counter;
		}

		// printing all coefficients for testing
		for (int i = 0; i < coefficients.size(); ++i)
		{
			cout << coefficients[i] << ' ';
		}
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
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
