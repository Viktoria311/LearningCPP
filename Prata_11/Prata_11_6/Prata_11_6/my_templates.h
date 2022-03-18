#ifndef MY_TEMPLATES_H_
#define MY_TEMPLATESH_

#include <iostream>
#include <vector>
#include "stonewt.h"

template<typename T>
void EnterValue(T& some)
{
	while (!(std::cin >> some))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try to enter again: ";
	}
}

template<typename T>
void ShowResults(const std::vector<Stonewt>& arr, T some)
{
	Stonewt min = arr[0];

	Stonewt max = arr[0];

	int count_of_elements_more_than_ = 0;

	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] > some) ++count_of_elements_more_than_;
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];
	}

	std::cout << "Max: " << max << std::endl;
	std::cout << "Min: " << min << std::endl;
	std::cout << "There are " << count_of_elements_more_than_ << " elements in array which nore than " << some << std::endl;
}

#endif