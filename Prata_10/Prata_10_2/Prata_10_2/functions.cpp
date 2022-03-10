#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "functions.h"
#include "person.h"

void EnterFirstName(char* arr, int size_)
{
	std::cout << "Enter your first name: ";
	std::cin.get(arr, size_);
	std::cin.get();
}
void EnterLastName(std::string& last_name_)
{
	std::cout << "Enter your last name: ";
	getline(std::cin, last_name_);
}

void Show(std::vector<Person>& vec)
{
	for (int i = 0; i < (int)vec.size(); ++i)
	{
		std::cout << "person " << i + 1 << ':' << std::endl;
		vec[i].Show();
		vec[i].FormalShow();
	}
}