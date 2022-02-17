#include <iostream>
#include <new>
#include <cstring>
#include "chaff.h"

extern const int len;
extern const int quantity;

int main()
{

	bool ordinary_new;

	std::cout << "hello!\ndo you want to work with a ordinary new operation or a new operation with the placement?" << std::endl;
	std::cout << "enter 1 for 0: 1 - ordinary new, 0 - with the placement: ";

	while ( !(std::cin >> ordinary_new) )
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "error. try again: 1 - ordinary new, 0 - with the placement: ";
	}
	while (std::cin.get() != '\n') continue;

	chaff* p_arr_of_struct;

	if (ordinary_new)
	{
		std::cout << "your choice is to work with the ordinary new." << std::endl;
		p_arr_of_struct = new chaff[quantity];
	}
	else
	{
		std::cout << "your choise is to work with the new operation with the placement." << std::endl;

		chaff arr[quantity];

		p_arr_of_struct = new (arr) chaff[quantity];

	}
	complete_arr_of_struct(p_arr_of_struct, quantity);
	show_arr_of_struct(p_arr_of_struct, quantity);

	delete[] p_arr_of_struct;
	return 0;
}