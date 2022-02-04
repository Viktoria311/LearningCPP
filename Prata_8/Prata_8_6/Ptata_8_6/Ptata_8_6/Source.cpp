#include <iostream>

// шаблон show
template<typename T>
void show( T* arr, int n);

//прототип явной специализации show
template<> void show<const char*>(const char** arr, int n);

//шаблон maxn
template<typename T>
T maxn( T* arr, int n);

//прототип явной специализации maxn
template<> const char* maxn<const char*>(const char** arr, int n);


int main()
{
	const int arr_of_int[] = { 4, 94, 54, 8, 223, 59 };

	int size_of_arr_of_int = sizeof(arr_of_int) / sizeof(int);

	const double arr_of_double[] = { 45.6, 34.6, 2.56, 8, 2 };

	int size_of_arr_of_double = sizeof(arr_of_double) / sizeof(double);

	const char* arr_of_p_to_cstrings[] = { "The first string.",
										   "And the second string.", 
										   "The third string.",
										   "The fouth string.",
										   "And the fifth string."
										 };

	int size_of_pointer_to_arr_of_cstrings = sizeof(arr_of_p_to_cstrings) / sizeof(char*);

	std::cout << "There are an array of " << size_of_arr_of_int << " integers." << std::endl;
	show( arr_of_int, size_of_arr_of_int);
	std::cout << "The largest integer in this array is " << maxn(arr_of_int, size_of_arr_of_int) << std::endl;

	std::cout << "There are an array of " << size_of_arr_of_double << " doubles." << std::endl;
	show(arr_of_double, size_of_arr_of_double);
	std::cout << "The largest double in this array is " << maxn(arr_of_int, size_of_arr_of_double) << std::endl;
	
	show(arr_of_p_to_cstrings, 5);
	std::cout << "The longest csrting:   " << maxn(arr_of_p_to_cstrings, size_of_pointer_to_arr_of_cstrings);
	std::cout << std::endl;

	std::cout << "Bye!\n";
	return 0;
}

template<typename T>
void show(T* arr, int n)
{
	std::cout << "Look at the array:" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		std::cout << i + 1 << ".   " << arr[i] << std::endl;
	}
}

template<> void show<const char*>(const char** arr, int n)
{
	std::cout << "There are 5 cstrings in an array: " << std::endl;
	for (int i = 0; i < n; ++i)
	{
		std::cout << i+1 << ".  " << arr[i] << std::endl;
	}
}

template<typename T>
T maxn( T arr[], int n)
{
	int index_of_max_element = 0;

	for (int i = 0; i < n; ++i)
		if (arr[i] > arr[index_of_max_element]) index_of_max_element = i;

	return arr[index_of_max_element];
}

template<> const char* maxn<const char*>(const char* arr[], int n)
{
	int index_of_the_longest_string = 0;

	for (int i = 0; i < n; ++i)
		if (sizeof(arr[i]) > sizeof(arr[index_of_the_longest_string])) index_of_the_longest_string = i;

	return arr[index_of_the_longest_string];
}
