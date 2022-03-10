#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf()
{
	std::cout << "Enter a name: ";
	std::cin.getline(fullname_, LEN);
	std::cout << "Enter a handicap: ";
	while (!(std::cin >> handicap_))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter a handicap: ";
	}
}

Golf::Golf(const char* fullname, int handicap)
{
	strcpy_s(fullname_, fullname);
	int handicap_ = handicap;
}

Golf::Golf(int handicap, const char* fullname)
{
	strcpy_s(fullname_, fullname);
	int handicap_ = handicap;
}

const int Golf::ReturnLEN()
{
	return LEN;
}

const char* Golf::Fullname() const
{
	return const_cast<const char*>(fullname_);
}

int Golf::Handicap() const
{
	return handicap_;
}

void Golf::ChangeHandicap(int handicap)
{
	handicap_ = handicap;
}

void Golf::ShowGolf() const
{
	std::cout << "name: " << fullname_ << std::endl;
	std::cout << "handicap: " << handicap_ << std::endl;
}
