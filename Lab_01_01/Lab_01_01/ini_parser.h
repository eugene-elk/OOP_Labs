#pragma once

#include "exceptions.h"

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

class IniParser {
private:
	bool inited;
	map <string, map<string, string> > info;
	string in;
	string section_name;
	string value_name;
	string value_value;
	int equal_pos;
	int dot_pos;

public:
	IniParser();
	~IniParser() = default;

	void Initialize(const std::string& filename_cstr) 
		throw(exc_io);

	void StringToMap(std::string& in);
	void MapAppend(const string & section_name, const string & param_name, const string & value);

	bool IsHaveSection(const std::string& section_name) const
		throw(exc_not_inited);

	bool IsHaveParam(const std::string& section_name, const std::string& param_name) const
		throw (exc_no_section, exc_not_inited);

	template<typename T> T GetValue(const std::string& section_name, const std::string& param_name) const
		throw (exc_unknown_type);
	template <> std::string GetValue<std::string>(const std::string& section_name, const std::string& param_name) const
		throw (exc_no_section, exc_not_inited);
	template <> int GetValue<int>(const std::string& section_name, const std::string& param_name) const
		throw (exc_type_conversion);
	template <> double GetValue<double>(const std::string& section_name, const std::string& param_name) const
		throw (exc_type_conversion);
};

template<typename T>
T IniParser::GetValue(const std::string& section_name, const std::string& param_name) const
{
	throw exc_unknown_type();
}

template <>
std::string IniParser::GetValue<std::string>(const std::string& section_name, const std::string& param_name) const
{
	if (!IsHaveSection(section_name))
	{
		throw exc_no_section();
	}
	if (!IsHaveParam(section_name, param_name))
	{
		throw exc_no_param();
	}
	return info.at(section_name).at(param_name);
}

template <>
int IniParser::GetValue<int>(const std::string& section_name, const std::string& param_name) const
{
	string rawValue = GetValue<std::string>(section_name, param_name);
	int rawToInt = stoi(rawValue);
	string intToString = to_string(rawToInt);
	if (rawValue.length() == intToString.length())
		return rawToInt;
	else
		throw exc_type_conversion();
}

template <>
double IniParser::GetValue<double>(const std::string& section_name, const std::string& param_name) const
{
	string rawValue = GetValue<std::string>(section_name, param_name);
	double rawToDouble = stod(rawValue);
	return rawToDouble;

}