#include <iostream>
#include <vector>
#include <string>
#include "header.h"

int main()
{
	int my_array[] = {1, 5, 32, 2, 4, 6, 8, 23, 4, 0, 6, 7, 2, 6, 8, 5, 3, 5, 8, 93, 44, 66 };

	std::vector<int> my_vec = {1, 5, 32, 2, 4, 6, 8, 23, 4, 0, 6, 7, 2, 6, 8, 5, 3, 5, 8, 93, 44, 66};

	int quantity_of_numbers_in_array = sizeof(my_array) / sizeof(my_array[0]);

	show_the_name_of_the_task(1, "Return the sum of numbers in the array.");///////////////////////////////////////////////////////////////////////////////////
	int array_sum = sum_of_numbers_in_array(my_array, quantity_of_numbers_in_array);
	int vector_sum = sum_of_numbers_in_array(my_vec);
	std::cout << "The sum of numbers of integers in the array  is " << array_sum << std::endl;
	std::cout << "The sum of numbers of integers from vector is " << vector_sum << std::endl;

	std::cout << std::endl;

	show_the_name_of_the_task(2, "Find the max number in the array.");/////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "The max number in the array is " << max_from_array(my_array, quantity_of_numbers_in_array) << std::endl;
	std::cout << "The max number from vector is " << max_from_array(my_vec) << std::endl;

	std::cout << std::endl;

	show_the_name_of_the_task(3, "Find the min number in the array.");/////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "The min number in the array is " << min_from_array(my_array, quantity_of_numbers_in_array) << std::endl;
	std::cout << "The min number from vector is " << min_from_array(my_vec) << std::endl;

	std::cout << std::endl;

	show_the_name_of_the_task(4, "Sort the array from min to max and return it.");/////////////////////////////////////////////////////////////////////////////
	sort_arr_min_max(my_array, quantity_of_numbers_in_array, is_arr_in_ascending_order);
	sort_arr_min_max(my_vec, is_vector_in_ascending_order);
	show_array(my_array, quantity_of_numbers_in_array);
	show_array(my_vec);

	std::cout << std::endl;

	show_the_name_of_the_task(5, "Sort the array from max to min and return it.");/////////////////////////////////////////////////////////////////////////////
	sort_arr_max_min(my_array, quantity_of_numbers_in_array, is_arr_in_descending_order);
	sort_arr_max_min(my_vec, is_vector_in_descending_order);
	show_array(my_array, quantity_of_numbers_in_array);
	show_array(my_vec);

	std::cout << std::endl;

	show_the_name_of_the_task(6, "Return the array of only even numbers.");////////////////////////////////////////////////////////////////////////////////////
	int quantity_of_even_numbers_in_array = count_of_even_numbers(my_array, quantity_of_numbers_in_array);
	if (quantity_of_even_numbers_in_array) //если количество не ноль, то есть любое число , кроме нуля = true
	{
		int* even_numbers_array = return_even_numbers_array(my_array, quantity_of_numbers_in_array, count_of_even_numbers);

		show_array(even_numbers_array, quantity_of_even_numbers_in_array);
		delete[] even_numbers_array;
	} else
		std::cout << "Can`t return an array of only even numbers. There are no even numbers in my_arr." << std::endl;
	
	std::vector<int> even_numbers_vec = return_even_numbers_vec(my_vec);
	show_array(even_numbers_vec);

	std::cout << std::endl;

	show_the_name_of_the_task(7, "Return the array of only odd numbers.");/////////////////////////////////////////////////////////////////////////////////////
	int quantity_of_odd_numbers_in_array = count_of_odd_numbers(my_array, quantity_of_numbers_in_array);
	if (quantity_of_odd_numbers_in_array) //если количество не ноль, то есть любое число , кроме нуля = true
	{
		int* odd_numbers_array = return_odd_numbers_array(my_array, quantity_of_numbers_in_array, count_of_odd_numbers);

		show_array(odd_numbers_array, quantity_of_odd_numbers_in_array);
		delete[] odd_numbers_array;
	}
	else
		std::cout << "Can`t return an array of only even numbers. There are no even numbers in my_arr." << std::endl;

	std::vector<int> odd_numbers_vec = return_odd_numbers_vec(my_vec);
	show_array(odd_numbers_vec);

	std::cout << std::endl;

	show_the_name_of_the_task(8, "Return the sum of only even numbers in the array.");/////////////////////////////////////////////////////////////////////////
	std::cout << "The sum of only even numbers in the array is " << sum_of_even_numbers(my_array, quantity_of_numbers_in_array) << std::endl;
	std::cout << "The sum of only even numbers in the array is " << sum_of_even_numbers(my_vec) << std::endl;
	
	std::cout << std::endl;

	show_the_name_of_the_task(9, "Return the sum of only odd numbers in the array.");//////////////////////////////////////////////////////////////////////////
	std::cout << "The sum of only odd numbers in the vector is " << sum_of_odd_numbers(my_array, quantity_of_numbers_in_array) << std::endl;
	std::cout << "The sum of only odd numbers in the vector is " << sum_of_odd_numbers(my_vec) << std::endl;

	std::cout << std::endl;

	show_the_name_of_the_task(10, "Return the  the array where there are even numbers and after them ood numbers from min to max.");///////////////////////////
	int* even_odd_numbers_array = return_even_odd_numbers_array(my_array, quantity_of_numbers_in_array, sort_arr_min_max,return_even_numbers_array, return_odd_numbers_array);
	show_array(even_odd_numbers_array, quantity_of_numbers_in_array);
	delete[] even_odd_numbers_array;

	std::vector<int> even_odd_numbers_vec = return_even_odd_numbers_vec(my_vec, sort_arr_min_max, return_even_numbers_vec, return_odd_numbers_vec);
	show_array(even_odd_numbers_vec);

	std::cout << std::endl;

	show_the_name_of_the_task(11, "Return true or false is there a number in the array.");/////////////////////////////////////////////////////////////////////
	int a = 6;
	std::cout << "Is there the number " << a << " in the array? ";
	is_in_array_answer(my_array, quantity_of_numbers_in_array, a);
	std::cout << "Is there the number " << a << " in the vector? ";
	is_in_vector_answer(my_vec, a);

	std::cout << std::endl;

	show_the_name_of_the_task(12, "Return the quantity of every repeated numbers in the array.");//////////////////////////////////////////////////////////////
	repeated_times(my_array, quantity_of_numbers_in_array, was_it_earlier_in_the_arr);
	std::vector<int> unique_vector = return_unique_numbers_vec(my_vec, is_in_vector);
	std::cout << std::endl;
	repeated_times(my_vec, unique_vector);

	return 0;
}