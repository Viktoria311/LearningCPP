#include <iostream>
#include <vector>
#include "stonewt.h"
#include "funcs.h"

int main()
{
	std::vector<Stonewt> arr = { Stonewt(450.0), Stonewt(20, 11), Stonewt(13, 9) };

	int quantity;

	bool with_stones;

	std::cout << "How many elements do you want to add: ";
	while (!(std::cin >> quantity))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try enter pounds again: ";
	}
	AddOtherElements(arr, quantity);

	std::cout << "With what do you want to compare elements? 1 - with stones, 0 - with pounds ";
	std::cin >> with_stones;
	std::cin.ignore(100, '\n');
	if (with_stones)
	{
		int st;

		std::cout << "Enter stones for comparing: ";
		EnterValue(st);
		ShowResults(arr, st);
	}
	else
	{
		double p;

		std::cout << "Enter pounds for comparing: ";
		EnterValue(p);
		ShowResults(arr, p);
	}
	
	std::cout << "Bye! " << std::endl;

	return 0;
}