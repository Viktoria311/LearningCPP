#include <iostream>
#include <vector>
#include "stonewt.h"
#include "funcs.h"

void AddOtherElements(std::vector<Stonewt>& arr, int quantity)
{
	double p;

	for (int i = 0; i < quantity; ++i)
	{
		std::cout << "Enter pounds for " << i << " object: ";
		while (!(std::cin >> p))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Try enter pounds again: ";
		}
		arr[i] = Stonewt(p);
	}
}
