#pragma once
#include "Exception.h"
#include "Polynomial.h"

class InvalidPower : public Exception
{
public:
	string what();
};