#include <exception>
#include "Polynomial.h"

class DivisionByZero : public exception
{
    public:
        string what() {return "Division by zero";};
}