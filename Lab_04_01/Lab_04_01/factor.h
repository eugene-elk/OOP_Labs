#pragma once
#include <string>
#include <vector>

class factor {

public:

	const std::string getString();

	const void createFactor(uint64_t number);

	const uint64_t createNum();

private:

	mutable std::vector<uint64_t> data;

	std::string convertToString(const uint64_t& val);
};