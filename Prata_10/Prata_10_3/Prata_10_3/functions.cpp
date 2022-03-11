#include <iostream>
#include <cstring>
#include <vector>
#include "golf.h"
#include "functions.h"


bool HaveName(const Golf& g)
{
	char arr[] = "New user";
	if (strcmp(g.Fullname(), arr) != 0) return true;
	else return false;
}

void EnterName(char* fullname_, int size_)
{
	std::cout << "Enter a name: ";
	std::cin.getline(fullname_, size_);
}

void EnterHandicap(int& handicap_)
{
	std::cout << "Enter a handicap: ";
	while (!(std::cin >> handicap_))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter a handicap: ";
	}
}

Golf Func(int size)
{
	bool want_constructor;

	std::cout << "Do you want to use Golf() constructor without arguments? 1 - yes, 0 - no" << std::endl;
	std::cin >> want_constructor;
	while (std::cin.get() != '\n') continue;
	if (want_constructor)
	{
		Golf obj;
		return obj;
	} else
	{
		bool want_both; 

		bool want_name;
		//bool want_handicap;
		char* fullname = new char[size];

		int handicap;
		//оба ввести
		std::cout << "Do you want to enter a name and a handicap? 1 - yes, 0 - no" << std::endl;
		std::cin >> want_both;
		if (want_both)
		{
			EnterName(fullname, size);
			EnterHandicap(handicap);
		} else
		{
			std::cout << "Do you want to enter a name or a handicap? 1 - name, 0 - handicap" << std::endl;
			std::cin >> want_name;
			if (want_name) EnterName(fullname, size);
			else EnterHandicap(handicap);
		}

		if (want_both)
		{
			 Golf obj (fullname, handicap);
			 delete[] fullname;
			 return obj;
		} else if (want_name)
		{
			Golf obj (fullname);
			delete[] fullname;
			return obj;
		} else 
		{
			delete[] fullname;
			return Golf(handicap);
		} 
	}
}

void AddGolf(std::vector<Golf>& my_vec)
{
	bool add_object;

	do
	{
		my_vec.push_back(Func(Golf::ReturnLEN()));
		std::cout << "Do you want to add another one object? 1 - yes, 0 - no" << std::endl;
		std::cin >> add_object;
		while (std::cin.get() != '\n') continue;
	} while (add_object);

}

void Show(const std::vector<Golf>& my_vec)
{
	std::cout << "Look at the Objects!" << std::endl;
	for(int i = 0; i < (int)my_vec.size(); ++i)
		my_vec[i].ShowGolf();
}