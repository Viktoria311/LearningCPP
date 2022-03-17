#ifndef FUNCS_H_
#define FUNCS_H_

#include <vector>
#include "stonewt.h"

void AddOtherElements(std::vector<Stonewt>& arr, int quantity);

//template<typename T>
//auto EnterValueWithoutType()->decltype T;
//int EnterValue();
//double EnterValue();
 
 
 

//template<typename T>
//void ShowResults(const std::vector<Stonewt>& arr, T some);
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