#include <iostream>
#include "golf.h"

extern const int Len;

int main()
{
	int quantity;

	std::cout << "How many structures do you want to  enter? ";

	while ( !(std::cin >> quantity)  )
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Try again to enter a quantity of structs: ";
	}
	std::cout << "Create an array!" << std::endl;
	golf* arr = new golf[quantity];

	for (int i = 0; i < quantity && setgolf(*(arr + i)) != 0; ++i);

	 if (quantity == 1) new_function(arr, change_handicap, showgolf);
	else new_function(arr, change_handicap, showgolf, quantity);

	delete[] arr;
	std::cout << "Bye!\n";
	return 0;
}