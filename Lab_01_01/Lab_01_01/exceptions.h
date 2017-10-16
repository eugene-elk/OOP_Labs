#pragma once

#include <exception>

using namespace std;

class exc_io : public exception
{
public:
	exc_io();
};

class exc_not_inited : public exception
{
public:
	exc_not_inited();
};

class exc_no_section : public exception
{
public:
	exc_no_section();
};

class exc_no_param : public exception
{
public:
	exc_no_param();
};

class exc_unknown_type : public exception
{
public:
	exc_unknown_type();
};

class exc_type_conversion : public exception
{
public:
	exc_type_conversion();
};