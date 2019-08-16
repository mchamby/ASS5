#pragma once
#include "Exception.h"
#include "Polynomial.h"

class InvalidString : public Exception
{
public:
	string what();
};