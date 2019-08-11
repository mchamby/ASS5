#include "stdafx.h"
#include "Polynomial.h"


Polynomial::Polynomial(string input)
{
	const int maxNumOfSegments = 100;

	// separating the strings into segments
	string segments[maxNumOfSegments] = { "" }; // the element of the segment corresponds to the power of x
	while (input.empty() == false)
	{
		int first = input.find_last_of("+-");
		int powerOfX = input.back();
		segments[powerOfX] = input.substr(first);
		cout << segments[powerOfX] << " ";
		input.erase(first);
	}

	/*
	int counter = 0;
	for (int i = 0; i < maxNumOfSegments; ++i)
	{
		if (segments[i].empty() == false)
		{
			int first = segments[i].find_first_of();
		}

		// when there is no recorded
	}*/
}


Polynomial::~Polynomial()
{
}
