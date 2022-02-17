#include <iostream>
#include <cstring>
#include "chaff.h"

extern const int LEN;

extern const int quantity;

void complete_arr_of_struct(chaff* p, int n)
{
	std::cout << "Let`s complete the array os chaff structs!" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		char str[LEN];
		std::cout << "Enter a dross of " << i + 1 << " struct: ";

		std::cin.get((p + i)->dross, LEN);

		while (std::cin.get() != '\n') continue;

		std::cout << "Enter a slag of " << i + 1 << " struct: ";
		while (!(std::cin >> (p + i)->slag))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Try again to enter a slag of " << i + i << " struct: ";
		}
		std::cin.get();
	}
}

void show_arr_of_struct(const chaff* p, int n)
{
	std::cout << "Look at all structs in the array:" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		std::cout << i + 1 << ". " << (p + i)->dross << " " << (p + i)->slag << std::endl;
	}
}