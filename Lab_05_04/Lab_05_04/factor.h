#pragma once
#include <string>
#include <vector>

class factor {

public:

	std::string getString();

	void createFactor(uint64_t number);

	uint64_t createNum();

private:

	std::vector<uint64_t> data;

	std::string convertToString(const uint64_t& val);
};