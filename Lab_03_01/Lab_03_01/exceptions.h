#pragma once

#include <string>

class exceptions
{
private:
	std::string error;

public:
	exceptions(const std::string& input);
	std::string out();

};