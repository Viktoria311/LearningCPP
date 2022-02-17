#ifndef HEADER_H_
#define HEADER_H_

void show_the_name_of_the_task(int i, std::string str);
void show_array(int* arr, int size);
void show_array(std::vector<int>& arr);
int sum_of_numbers_in_array(int* arr, int size);
int sum_of_numbers_in_array(std::vector<int>& arr);
int max_from_array(int* arr, int size);
int max_from_array(std::vector<int>& vec);
int min_from_array(int* arr, int size);
int min_from_array(std::vector<int>& vec);
int* sort_array(int* arr, int size);
std::vector<int>& sort_array(std::vector<int>& arr);


#endif 

