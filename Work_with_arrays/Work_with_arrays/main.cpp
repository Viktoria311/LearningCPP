#include <iostream>
#include <vector>
#include <string>
#include "header.h"

int main()
{
	int array[] = {1, 5, 32, 2, 4, 6, 8, 23, 4, 0, 6, 7, 2, 6, 8, 5, 3, 5, 8, 93, 44, 66 };

	std::vector<int> my_vec = {1, 5, 32, 2, 4, 6, 8, 23, 4, 0, 6, 7, 2, 6, 8, 5, 3, 5, 8, 93, 44, 66};

	int quantity_of_numbers_in_array = sizeof(array) / sizeof(array[0]);

	show_the_name_of_the_task(1, "Return the sum of numbers in the array.");
	int array_sum = sum_of_numbers_in_array(array, quantity_of_numbers_in_array);
	int vector_sum = sum_of_numbers_in_array(my_vec);
	std::cout << "The sum of numbers of integers in the array  is " << array_sum << std::endl;
	std::cout << "The sum of numbers of integers from vector is " << vector_sum << std::endl;

	show_the_name_of_the_task(2, "Find the max number in the array.");
	std::cout << "The max number in the array is " << max_from_array(array, quantity_of_numbers_in_array) << std::endl;
	std::cout << "The max number from vector is " << max_from_array(my_vec) << std::endl;

	show_the_name_of_the_task(3, "Find the min number in the array.");
	std::cout << "The min number in the array is " << min_from_array(array, quantity_of_numbers_in_array) << std::endl;
	std::cout << "The min number from vector is " << min_from_array(my_vec) << std::endl;

	show_the_name_of_the_task(4, "Sort the array from max to min and return it.");
	int sorted_array1[] = sort_array(array, quantity_of_numbers_in_array);
	//int sorted_array2[] = sort_array(my_arr, quantity_of_numbers_in_array, min_from_array(array, quantity_of_numbers_in_array));
	//здесь отсортировать вектор
	
	show_array(sorted_array1, quantity_of_numbers_in_array);
	show_array(my_vec);


	show_the_name_of_the_task(5, "Sort the array from min to max and return it.");
	show_the_name_of_the_task(6, "Return the array of only even numbers.");
	show_the_name_of_the_task(7, "Return the array of only odd numbers.");
	show_the_name_of_the_task(8, "Return the sum of only even numbers in the array.");
	show_the_name_of_the_task(9, "Return the sum of only odd numbers in the array.");
	show_the_name_of_the_task(10, "Return the  the array where there are even numbers and after them ood numbers from min to max.");
	show_the_name_of_the_task(11, "Return true or false is there a number in the array.");
	show_the_name_of_the_task(12, "Return the quantity of every reterned numbers in the array.");
	return 0;
}