#include <exception>
#include "Polynomial.h"

class InvalidString : public exception
{
    public:
        string what(){ return "String is mal-formed";};
}