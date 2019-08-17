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





 Polynomial operator+(const Polynomial & p1, const Polynomial & p2) {

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

 Polynomial operator-(const Polynomial & p1, const Polynomial & p2)
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

 istream& operator>> (istream & is, Polynomial& p) // add exception for mal-formed string 
 {
	 string poly; 
	 is >> poly; 
	 Polynomial temp(poly); // create a polynomial using the inputted string 
	 p = temp;
	 return is;
 }

 ostream& operator<< (ostream & os, const Polynomial& p) 
 {
	 for (int i = 0; i < p.coefficients.size; ++i)

		 os << p.coefficients[i] << "x^" << i << " ";

	 return os;
 }
 
 double & Polynomial::operator[] (int n)
 {
	 try {
		 if (n < 0)
			 throw exception();
	 }
	 catch (exception )
 }
int findSmallerPoly(const Polynomial & p1, const Polynomial & p2) {

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
