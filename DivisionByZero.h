#pragma once
#include "Exception.h"
#include "Polynomial.h"
#include <string>

class DivisionByZero : public Exception
{
public:
	string what();
};