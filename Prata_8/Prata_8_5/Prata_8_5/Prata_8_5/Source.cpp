#include <iostream>

template<typename T>
T max5(T* arr)
{
	T the_biggest = arr[0];
	int index_of_the_biggest = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (  arr[i] > arr[index_of_the_biggest]   ) index_of_the_biggest = i;
	}
	return arr[index_of_the_biggest];
}

int main()
{
	double arr1[5] = { 4.5, 23.5, 55.8, 136.0, 26.9 };
	int arr2[5] = { 5, 3, 6, 2, 9 };
	auto the_biggest_of_arr1 = max5(arr1);
	std::cout << "The biggest element of arr1 is " << the_biggest_of_arr1 << std::endl;
	auto the_biggest_of_arr2 = max5(arr2);
	std::cout << "The biggest element of arr2 is " << the_biggest_of_arr2 << std::endl;
	return 0; 
}