#include "factor.h"
#include <cmath>
#include <sstream>
#include <thread>
#include <mutex>

using namespace std;

void factor::createFactor(uint64_t number)
{
	data.clear();
	const uint64_t limit = uint64_t(round(sqrt(number)));

	for (uint64_t i = 2; i <= limit; ++i)
	{
		while (number % i == 0)
		{
			number /= i;
			data.push_back(i);
		}
	}

	if (number != 1)
	{
		data.push_back(number);
	}
}

std::string factor::convertToString(const uint64_t &val)
{
	std::ostringstream strstream;
	strstream << val;
	return std::move(std::string(strstream.str()));
}

std::string factor::getString()
{
	std::string value = "1";

	for (uint64_t &n : data)
	{
		value += " * ";
		value += convertToString(n);
	}

	return std::move(value);
}

uint64_t factor::createNum()
{
	uint64_t num = 1;
	for (uint64_t &n : data)
	{
		num *= n;
	}
	return num;
}