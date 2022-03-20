#include <iostream>
#include <vector>
#include "cow.h"

int main()
{
	std::vector<Cow> cows;
	bool want;
	Cow some;
	do
	{
	
		std::cin >> some;
		cows.push_back(some);
		std::cout << "Do you want to add one more cow? 1 - yes, 0 - no ";
		std::cin >> want;
		//std::cin.get();
		std::cin.ignore(100, '\n');
	} while (want);


	cows.push_back(Cow("zzzz", "xxxx", 34));
	cows.push_back(Cow("dddddddd", "ffffffffff", 34));
	cows.push_back(Cow("aaaaaaa", "sssss", 84));

	for (int i = 0; i < cows.size(); ++i)
		std::cout << cows[i] << std::endl;

	return 0;
}