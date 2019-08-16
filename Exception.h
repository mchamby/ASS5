#pragma once
#include <string>

class Exception
{
public:
	virtual string what() {return "Error";}
};
