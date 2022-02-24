#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <vector>
#include <string>

typedef bool (*check_order_arr_t)(const int*, int);
typedef bool (*check_order_vector_t)(const std::vector<int>&);
typedef int (*func_count_numbers_t)(const int*, int);
typedef std::vector<int>(*func_return_vec_t)(const std::vector<int>&);
typedef int (*func_count_t)(const int*, int);
typedef int* (*func_return_arr_t)(const int*, int, int (*)(const int*, int));
typedef std::vector<int>(*func_return_vec_t)(const std::vector<int>&);
typedef  bool (*func_is_there_t)(const std::vector<int>&, int);
typedef std::vector<int>(*func_return_unique_numbers_vec_t)(const std::vector<int>&, func_is_there_t);
typedef void (*func_sort_arr_max_min_t)(std::vector<int>&, check_order_vector_t);
typedef void (*f_sort_arr_min_max_t)(int*, int s, check_order_arr_t);
typedef void (*f_sort_vec_min_max_t)(std::vector<int>&, check_order_vector_t);
typedef bool (*f_was_it_earlier_in_the_arr_t)(const int*, const int);

void show_the_name_of_the_task(int i, const std::string str);
void show_array(const int* arr, int size);
void show_array(const std::vector<int>& vec);
int sum_of_numbers_in_array(const int* arr, int size);//1
int sum_of_numbers_in_array(const std::vector<int>& vec);
int max_from_array(const int* arr, int size);//2
int max_from_array(const std::vector<int>& vec);
int min_from_array(const int* arr, int size);//3
int min_from_array(const std::vector<int>& vec);
void sort_arr_min_max(int* arr, int size, check_order_arr_t check);//4
bool is_arr_in_ascending_order(const int* arr, int size);
bool is_vector_in_ascending_order(const std::vector<int>& vec);
void sort_arr_min_max(std::vector<int>& vec, check_order_vector_t check);
void sort_arr_max_min(int* arr, int size, check_order_arr_t check);//5
bool is_arr_in_descending_order(const int* arr, int size);
bool is_vector_in_descending_order(const std::vector<int>& vec);
void sort_arr_max_min(std::vector<int>& vec, check_order_vector_t check);
int count_of_even_numbers(const int* arr, int size);//6
int* return_even_numbers_array(const int* arr, int size, func_count_t f_count);
std::vector<int> return_even_numbers_vec(const std::vector<int>& vec);
int count_of_odd_numbers(const int* arr, int size);//7
int* return_odd_numbers_array(const int* arr, int size, func_count_t f_count);
std::vector<int> return_odd_numbers_vec(const std::vector<int>& vec);
int sum_of_even_numbers(const int* arr, int size);//8
int sum_of_even_numbers(const std::vector<int>& vec);
int sum_of_odd_numbers(const int* arr, int size);//9
int sum_of_odd_numbers(const std::vector<int>& vec);
int* return_even_odd_numbers_array( int* arr, int size, f_sort_arr_min_max_t f_sort_arr_min_max,func_return_arr_t func_return_even_arr, func_return_arr_t func_return_odd_arr);//10
std::vector<int> return_even_odd_numbers_vec( std::vector<int>& vec, f_sort_vec_min_max_t f_sort_vec_min_max, func_return_vec_t func_even_vec, func_return_vec_t func_odd_vec);
void is_in_array_answer(const int* arr, int size, int num);//11
void is_in_vector_answer(const std::vector<int>& vec, int num);
void repeated_times(const int* arr, int size, f_was_it_earlier_in_the_arr_t);//12
bool was_it_earlier_in_the_arr(const int* f_arr, const int index_of_element);
bool is_in_vector(const std::vector<int>& vec, int num);
std::vector<int> return_unique_numbers_vec(const std::vector<int>& vec, func_is_there_t func_is_there);
void repeated_times(const std::vector<int>& vec, std::vector<int>& unique);

#endif 

