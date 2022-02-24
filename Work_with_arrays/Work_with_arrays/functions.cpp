#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "header.h"

void show_the_name_of_the_task(int i, const std::string str)
{
	std::cout << "Exercise " << i << ". " << str << std::endl;
}
void show_array(const int* arr, int size)
{
	if (size == 0)
		std::cout << "Array is empty.";
	else
	{
		std::cout << "Look at the array:" << std::endl;
		for (int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void show_array(const std::vector<int>& vec)
{
	if (vec.empty())
		std::cout << "Vector is empty.";
	else
	{
		std::cout << "Look at the vector:" << std::endl;
		for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
			std::cout << *i << " ";
	}
	std::cout << std::endl;
}
//1
int sum_of_numbers_in_array(const int* arr, int size)
{
	int sum = 0;

	for (int i = 0; i < size; ++i)
		sum += arr[i];

	return sum;
}
int sum_of_numbers_in_array(const std::vector<int>& vec)
{
	int sum = 0;

	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
		sum += *i;
	
	return sum;
}
//2
int max_from_array(const int* arr, int size)
{
	int max = arr[0];

	for (int i = 1; i < size; ++i)
		if (arr[i] > max) max = arr[i];
	
	return max;
}
int max_from_array(const std::vector<int>& vec)
{
	int max = vec.at(0);

	for (std::vector<int>::const_iterator i = vec.begin() + 1; i != vec.end(); ++i)
		if (*i > max) max = *i;

	return max;
}
//3
int min_from_array(const int* arr, int size)
{
	int min = arr[0];

	for (int i = 1; i < size; ++i)
		if (arr[i] < min) min = arr[i];

	return min;
}
int min_from_array(const std::vector<int>& vec)
{
	int min = vec.at(0);

	for (std::vector<int>::const_iterator i = vec.begin() + 1; i != vec.end(); ++i)
		if (*i > min) min = *i;

	return min;
}
//4
bool is_arr_in_ascending_order(const int* arr, int size)//по возрастанию
{
	for (int i = 0; i < size - 1; ++i)
		if (arr[i] > arr[i + 1]) return false;
		
	return true;
}

void sort_arr_min_max(int* arr, int size, check_order_arr_t check)
{
	while (!check(arr, size))
	{
		for (int i = 0; i < size - 1; ++i)
			if (arr[i] > arr[i + 1])
			{
				int element = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = element;
			}
	}
}
bool is_vector_in_ascending_order(const std::vector<int>& vec)//по возрастанию
{
	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end() - 1; ++i)
		if ( *i > *(i + 1) ) return false;

	return true;
}
void sort_arr_min_max(std::vector<int>& vec, check_order_vector_t check)
{
	while(!check(vec))
	{

		for (std::vector<int>::iterator i = vec.begin(); i != vec.end() - 1; ++i)
			if ( *i > *(i + 1) )
				std::swap(*i, *(i + 1));	
	}
}
//5
bool is_arr_in_descending_order(const int* arr, int size)
{
	for (int i = size - 1; i > 0; --i)
		if (arr[i] > arr[i - 1]) return false;

	return true;
}
bool is_vector_in_descending_order(const std::vector<int>& vec)
{
	for (std::vector<int>::const_iterator i = vec.end() - 1; i != vec.begin(); --i)
		if (*i > *(i - 1)) return false;

	return true;
}

void sort_arr_max_min(int* arr, int size, check_order_arr_t check)
{
	while (!check(arr, size))
		for (int i = size - 1; i > 0 ; --i)
			if (arr[i] > arr[i - 1])
			{
				int element = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = element;
			}
}
void sort_arr_max_min(std::vector<int>& vec, check_order_vector_t check)
{
	while (!check(vec))
	{
		for (std::vector<int>::iterator i = vec.end() - 1; i != vec.begin(); --i)
			if (*i > *(i - 1))
				std::swap(*i, *(i - 1) );
	}
}
// 6
int count_of_even_numbers(const int* arr, int size)
{
	int count = 0;

	for (int i = 0; i < size; ++i)
		if ( !(arr[i] & 1) ) ++count; //побитовые операции. Если последний бит не true, то есть не 1
	return count;
}

int* return_even_numbers_array(const int* arr, int size, func_count_t f_count)
{
	int count = f_count(arr, size);

	int* even_num_arr = new int[count];

	for (int i = 0, j = 0; i < count; ++i, ++j)
		if (!(arr[j] & 1)) even_num_arr[i] = arr[j];
		else --i;

	return even_num_arr;
}

std::vector<int> return_even_numbers_vec(const std::vector<int>& vec)
{
	std::vector<int> new_vec;

	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
		if ((*i) % 2 == 0)
			new_vec.push_back(*i);

	int size = new_vec.size();

	new_vec.resize(size);

	return new_vec;
}
// 7
int count_of_odd_numbers(const int* arr, int size)
{
	int count = 0;

	for (int i = 0; i < size; ++i)
		if (arr[i] & 1) ++count; //побитовые операции. Если последний бит 1, тогда условие true
	return count;
}

int* return_odd_numbers_array(const int* arr, int size, func_count_t f_count)
{
	int count = f_count(arr, size);

	int* odd_num_arr = new int[count];

	for (int i = 0, j = 0; i < count; ++i, ++j)
		if ((arr[j] & 1)) odd_num_arr[i] = arr[j];
		else --i;

	return odd_num_arr;
}

std::vector<int> return_odd_numbers_vec(const std::vector<int>& vec)
{
	std::vector<int> new_vec;

	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
		if ((*i) % 2 != 0)
			new_vec.push_back(*i);
		
	int size = new_vec.size();

	new_vec.resize(size);

	return new_vec;
}
//8
int sum_of_even_numbers(const int* arr, int size)
{
	int sum = 0;

	for (int i = 0; i < size; ++i)
		if (arr[i] % 2 == 0) sum += arr[i];

	return sum;
}

int sum_of_even_numbers(const std::vector<int>& vec)
{
	int sum = 0;

	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
		if (*i % 2 == 0) sum += *i;

	return sum;
}
//9
int sum_of_odd_numbers(const int* arr, int size)
{
	int sum = 0;

	for (int i = 0; i < size; ++i)
		if (arr[i] % 2 != 0) sum += arr[i];

	return sum;
}
int sum_of_odd_numbers(const std::vector<int>& vec)
{
	int sum = 0;

	for(std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
		if (*i % 2 != 0) sum += *i;

	return sum;
}
//10
int* return_even_odd_numbers_array(int* arr, int size, f_sort_arr_min_max_t f_sort_arr_min_max, func_return_arr_t func_return_even_arr, func_return_arr_t func_return_odd_arr)
{

	int* final_even_ood_arr = new int[size];

	int size_of_left_side = count_of_even_numbers(arr, size);

	int size_of_right_side = count_of_odd_numbers(arr, size);

	f_sort_arr_min_max(arr, size, is_arr_in_ascending_order);//сортируем массив перед созданием других массивов

	int* even_arr = func_return_even_arr(arr, size, count_of_even_numbers);

	int* ood_arr = func_return_odd_arr(arr, size, count_of_odd_numbers);

	for (int i = 0; i < size_of_left_side; ++i)
		final_even_ood_arr[i] = even_arr[i];

	for (int i = size_of_left_side, j = 0; i < size  &&  j < size_of_right_side;  ++i, ++j)
		final_even_ood_arr[i] = ood_arr[j];

	return final_even_ood_arr;
}
std::vector<int> return_even_odd_numbers_vec(std::vector<int>& vec, f_sort_vec_min_max_t f_sort_vec_min_max, func_return_vec_t func_even_vec, func_return_vec_t func_odd_vec)
{
	f_sort_vec_min_max(vec, is_vector_in_ascending_order);
	std::vector<int> final_even_ood_vec = func_even_vec(vec);

	std::vector<int> ood_vec = func_odd_vec(vec);

	for (int i = 0; i < ood_vec.size(); ++i)
		final_even_ood_vec.push_back(ood_vec[i]);

	
	return final_even_ood_vec;
}
//11
void is_in_array_answer(const int* arr, int size, int num)
{
	bool is_there = false;

	for (int i = 0; i < size; ++i)
		if (arr[i] == num) is_there = true;
		

	if (is_there) std::cout << "Yes." << std::endl;
	else  std::cout << "No." << std::endl;
}

void is_in_vector_answer(const std::vector<int>& vec, int num)
{
	bool is_there = false;

	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
		if (*i == num)  is_there = true;

	if (is_there) std::cout << "Yes." << std::endl;
	else  std::cout << "No." << std::endl;
}
//12
bool is_in_vector(const std::vector<int>& vec, int num)
{
	for (int i = 0; i < vec.size(); ++i)
		if (vec[i] == num) return true;

	return false;
}

bool was_it_earlier_in_the_arr(const int* f_arr, const int index_of_element)
{
	for (int i = index_of_element-1; i >= 0; --i)
		if (f_arr[index_of_element] == f_arr[i]) return true;
	return false;
}
void repeated_times(const int* arr, int size, f_was_it_earlier_in_the_arr_t f_was_it_earlier_in_the_arr)
{
	if (size == 0) std::cout << "The array is empty." << std::endl;
	else
	{
		int count = 1;

		//цикл для первого элемента
		for (int i = 1; i < size; ++i)
			if (arr[0] == arr[i]) ++count;

		std::cout << "Repeats in vector:" << std::endl;
		std::cout << "Number " << arr[0] << " repeats " << count << " times." << std::endl;

		count = 1;
		//цикл для остальных элементов
		for (int i = 1; i < size; ++i)
		{
			for (int j = i + 1; j < size - 1; ++j)
				if (arr[i] == arr[j] && !f_was_it_earlier_in_the_arr(arr, i)  ) ++count;

			if (!f_was_it_earlier_in_the_arr(arr, i))
				std::cout << "Number " << arr[i] << " repeats " << count << " times." << std::endl;

			count = 1;
		}
	}
}

std::vector<int> return_unique_numbers_vec(const std::vector<int>& vec, func_is_there_t func_is_there)
{
	std::vector<int> unique_numbers_vec{ vec[0] };

	for (int i = 1; i < vec.size(); ++i)
		if (!func_is_there(unique_numbers_vec, vec[i]))
			unique_numbers_vec.push_back(vec[i]);

	return unique_numbers_vec;
}

void repeated_times(const std::vector<int>& vec, std::vector<int>& unique)
{
	const std::vector<int> unique_vec = unique;

	int count = 0;

	std::cout << "Repeats in vector:" << std::endl;

	for (int i = 0; i < unique_vec.size(); ++i)
	{
		for (int j = 0; j < vec.size(); ++j)
			if (unique_vec[i] == vec[j]) ++count;

		std::cout << "Number " << unique_vec[i]  << " repeats " << count << " times." << std::endl;
		count = 0;
	}

}