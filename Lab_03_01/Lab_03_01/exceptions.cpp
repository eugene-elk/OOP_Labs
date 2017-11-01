#include "exceptions.h"
#include <string>

exceptions::exceptions(const std::string& input) 
{
	error = input;
}

std::string exceptions::out() 
{
	return error;
}