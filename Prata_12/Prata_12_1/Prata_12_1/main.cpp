#include <iostream>
#include <vector>
#include "cow.h"

int main()
{
	std::vector<Cow> cows;

	bool want;

	do
	{
		Cow some;

		std::cin >> some;
		cows.push_back(some);
		std::cout << "Do you want to add one more cow? 1 - yes, 0 - no ";
		std::cin >> want;
		std::cin.ignore(100, '\n');
	} while (want);

	return 0;
}