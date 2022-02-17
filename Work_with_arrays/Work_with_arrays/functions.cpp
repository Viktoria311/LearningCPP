#include <iostream>
#include <vector>
#include <string>
#include "header.h"

void show_the_name_of_the_task(int i, std::string str)
{
	std::cout << "Exercise " << i << ". " << str << std::endl;
}
void show_array(int* arr, int size)
{
	std::cout << "Look at the array:" << std::endl;
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void show_array(std::vector<int>& arr)
{
	std::cout << "Look at the array:" << std::endl;
	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int sum_of_numbers_in_array(int* arr, int size)
{
	int sum = 0;

	for (int i = 0; i < size; ++i)
		sum += arr[i];

	return sum;
}
int sum_of_numbers_in_array(std::vector<int>& arr)
{
	int sum = 0;

	for (int i = 0; i < arr.size(); ++i)
		sum += arr.at(i);
	
	return sum;
}
int max_from_array(int* arr, int size)
{
	int max = arr[0];

	for (int i = 1; i < size; ++i)
		if (arr[i] > max) max = arr[i];
	
	return max;
}
int max_from_array(std::vector<int>& vec)
{
	int max = vec.at(0);

	for (int i = 1; i < vec.size(); ++i)
		if (vec.at(i) > max) max = vec.at(i);

	return max;
}

int min_from_array(int* arr, int size)
{
	int min = arr[0];

	for (int i = 1; i < size; ++i)
		if (arr[i] < min) min = arr[i];

	return min;
}
int min_from_array(std::vector<int>& vec)
{
	int min = vec.at(0);

	for (int i = 1; i < vec.size(); ++i)
		if (vec.at(i) < min) min = vec.at(i);

	return min;
}
int* sort_array(int* arr, int size)
{
	/*int new_arr[size];
	for(int j = 0; j < size; ++j)
			for (int i = 0; i < size -1; ++i)
			{
				if (arr[i] < arr[i + 1]) new_arr[j] = arr[i];
				else
			}*/
}
std::vector<int>& sort_array(std::vector<int>& arr)
{

}