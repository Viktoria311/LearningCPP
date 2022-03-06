#include <iostream>
#include <string>
#include <cstring>
#include "person.h"

//inline
Person::Person()
{
	lname = "";
	fname[0] = '\0';
}

Person::Person(const std::string& ln, const char* fn)
{
	lname = ln;
	strcpy_s(fname, fn);
}

void Person::Show() const
{
	std::cout << fname << ' ' << lname << std::endl;
}

void Person::FormalShow() const
{
	std::cout << lname << ' ' << fname << std::endl;
}

const int Person::Limit()
{
	return LIMIT;
}