//#include "stdafx.h"
#include "Polynomial.h"


Polynomial::Polynomial(string input)
{
	try
	{
		testForInvalidString(input);
		testForInvalidPower(input);

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
	catch (Exception& e)
	{
		cout << e.what() << '\n';
	}
}


void Polynomial::testForInvalidString(string input)
{
	int invalidInputIndex = input.find_first_not_of("+-.^x1234567890");
	if (invalidInputIndex <= input.size())
		throw InvalidString();
}

void Polynomial::testForInvalidPower(string input)
{
	// check to make sure the power isn't negative
	while (true)
	{
		int hatIndex = input.find_last_of('^');
		if (hatIndex > input.size())	// there are no hats left in the string
			break;
		if (input[hatIndex + 1] == '-')
			throw InvalidPower();
		input.erase(hatIndex);
	}

	// maybe test if the powers are in order
}


Polynomial::Polynomial(const Polynomial& rhs)
{
	this->coefficients = rhs.coefficients;
}


Polynomial::~Polynomial()
{
	coefficients.erase(coefficients.begin(), coefficients.end());
}

ostream & operator<<(ostream & os, const Polynomial & rhs)
{
	for (int i = rhs.coefficients.size() - 1; i >= 0; --i)
	{
		if (rhs.coefficients[i] != 0)
			os << showpos << rhs.coefficients[i] << "x^" << noshowpos << i;
	}
	return os;
}

istream& operator>> (istream& is, Polynomial& rhs)
{
	 string poly; 
	 is >> poly; 
	 Polynomial temp(poly); // create a polynomial using the inputted string 
	 rhs = temp;
	 return is;
}

Polynomial operator+ (const Polynomial & p1, const Polynomial & p2) 
{

	Polynomial result("0");

	int count = 0;

	for (int i = 0; i < findSmallerPoly(p1, p2); ++i) { 

		// add elements until the smaller vector goes out of range

		result.coefficients[i] = p1.coefficients[i] + p2.coefficients[i];

		++count;
	}
	
	for (int j = count; j < findLargerPoly(p1, p2); ++j)

		// continue adding starting from the index reached in first loop until the end of the larger vector 
	{
		if (returnLargerPoly(p1, p2)==true) 
			
			// determine which vector is larger for filling the rest of result
		
			result.coefficients[j] = p1.coefficients[j];
		
		else

		result.coefficients[j] = p2.coefficients[j];

	}

	return result;
}

Polynomial operator- (const Polynomial & p1, const Polynomial & p2)
{
	Polynomial result("0");

	int count = 0;

	for (int i = 0; i < findSmallerPoly(p1, p2); ++i) 
	
		{
		result.coefficients[i] = p1.coefficients[i] - p2.coefficients[i];

		++count;
		}
		

	for (int j = count; j < findLargerPoly(p1, p2); ++j)
	{
		if (returnLargerPoly(p1, p2) == true)

			// if p1 has more values, the rest of the subtraction will be positive values of p1

			result.coefficients[j] = p1.coefficients[j];

		else
			// if p2 has more values, the remainder of the subtraction will be negative values of p2
			result.coefficients[j] = -p2.coefficients[j];

	}

}

const Polynomial operator* (const Polynomial& p, double z) 
{

	 Polynomial result("0");

	 for (int i = 0; i < p.coefficients.size; ++i)
	 {
		 result.coefficients[i] = z * p.coefficients[i];
	 }

	 return result;
 }
 
double & Polynomial::operator[] (int n)
{
	try 
	{
		if (n < 0)
			throw InvalidPower();
	}
	catch (Exception &e) {

		cout << e.what();
	}

	 return coefficients[n];
}

double Polynomial::operator[] (int n) const 
{

	try 
	{
		if (n < 0)
			throw InvalidPower();
	}
	catch (Exception& e) 
	{

		cout << e.what();
	}

	return coefficients[n];
 }

double Polynomial::operator() (double x) const
{
  double total;
  for (int i = 0; i < coefficients.size(); ++i)
  {
    total += coefficients[i] * pow(x, i);
  }
  return total;
}

int findSmallerPoly(const Polynomial & p1, const Polynomial & p2)
{

	if (p1.coefficients.size <= p2.coefficients.size)

		return p1.coefficients.size;

	else

		return p2.coefficients.size;
}

int findLargerPoly(const Polynomial & p1, const Polynomial & p2) 
{

	if (p1.coefficients.size >= p2.coefficients.size)

		return p1.coefficients.size;

	else
		return p2.coefficients.size;
}

bool returnLargerPoly(const Polynomial& p1, const Polynomial & p2)
{
	if (p1.coefficients.size >= p2.coefficients.size)

		return true;

	else

		return false;
}