#pragma once
#include <string>

using namespace std;

class Exception
{
public:
	Exception();
	~Exception();
	virtual string what();
};

