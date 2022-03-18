#include <iostream>
#include <vector>
#include "cow.h"

int main()
{
	std::vector<Cow> cows;

	Cow some;
	bool want;

	do
	{
		std::cin >> some;
		cows.push_back(some);
		std::cout << "Do you want to add one more cow? 1 - yes, 0 - no ";
		std::cin >> want;
		//std::cin.get();
		std::cin.ignore(100, '\n');
	} while (want);

	for (int i = 0; i < cows.size(); ++i)
		std::cout << cows[i] << std::endl;

	return 0;
}