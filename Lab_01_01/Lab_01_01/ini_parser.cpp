#include "ini_parser.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string removeSpaces(string input) 
{
	/*
	//from stackoverflow
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	return input
	*/

	string output = "";
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')
		{
			output.push_back(input[i]);
		}
	}
	return output;
}

bool isEmpty(string input)
{
	return (input == "");
}

IniParser::IniParser()
{
	inited = false;
}

void IniParser::MapAppend(const string & section_name, const string & param_name, const string & value)
{
	cout << section_name << " " << param_name << " " << value << endl;
	info[section_name][param_name] = value;
}

void IniParser::StringToMap(string & in)
{
	in = removeSpaces(in);
	if (!isEmpty(in))
	{
		if (in[0] == '[')
		{
			section_name = in.substr(1, in.length() - 2);
		}
		else
		{
			equal_pos = in.find('=');
			dot_pos = in.find(';');
			if ((equal_pos != -1) && !((equal_pos > 0) && (dot_pos == 0)))
			{
				value_name = in.substr(0, equal_pos);
				if (dot_pos == -1)
				{
					value_value = in.substr(equal_pos + 1, in.length() - 2);
				}
				else
				{
					value_value = in.substr(equal_pos + 1, dot_pos - equal_pos - 1);
				}
				MapAppend(section_name, value_name, value_value);
			}
		}
	}
}

void IniParser::Initialize(const string & filename_cstr)
{
	ifstream fin;
	fin.open(filename_cstr);
	if (!fin.is_open())
	{
		throw exc_io();
	}
	inited = true;
	while (!fin.eof())
	{
		getline(fin, in);
		StringToMap(in);
	}
}

bool IniParser::IsHaveSection(const string & section_name) const
{
	if (!inited) 
	{
		throw exc_not_inited();
	}
	return !(info.find(section_name) == info.end());
}

bool IniParser::IsHaveParam(const string & section_name, const string & param_name) const
{
	if (!IsHaveSection(section_name))
		return false;
	auto section = info.find(section_name);
	return !(section->second.find(param_name) == section->second.end());
}