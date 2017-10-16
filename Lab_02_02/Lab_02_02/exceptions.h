#pragma once

#include <exception>

using namespace std;

class exc_empty_multiset : public exception
{
public:
	exc_empty_multiset();
};

class exc_io : public exception
{
public:
	exc_io();
};