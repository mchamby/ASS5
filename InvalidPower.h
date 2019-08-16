#include <exception>
#include "Polynomial.h"

class InvalidPower : public exception
{
    public:
        string what() { return "Invalid index of power! No negative powers";};
};