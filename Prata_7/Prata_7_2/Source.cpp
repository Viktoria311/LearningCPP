#include <iostream>

int func_enter(int* arr_of_game_results, int size_of_arr);

double func_arithmetic_mean(int* arr, int quantity);

void func_display(int* arr, int size, double(*func)(int*, int));

int main()
{
	int arr_of_game_results[10];

	int quantity_of_results = func_enter(arr_of_game_results, 10);

	func_display(arr_of_game_results, quantity_of_results, func_arithmetic_mean);

	return 0;
}
int func_enter(int* arr, int size_of_arr)
{
	std::cout << "Enter not more than 10 game results (q to quit): ";

	int i = 0;

	while (std::cin >> *(arr + i)  &&  i <=  size_of_arr  )
	{
		++i;

		std::cin.clear();
	}
	return i + 1;
}

double func_arithmetic_mean(int* arr, int quantity)
{
	double arithmetic_mean = 0.0;

	for(int i = 0; i < quantity; ++i)
	{
		arithmetic_mean += *(arr + i);
	}
	return arithmetic_mean /= quantity;
}

void func_display(int* arr, int size, double(*func)(int*, int) )
{
	std::cout << "All game results:" << std::endl;

	for(int i = 0;  i < size;  ++i)
	{
		std::cout << *(arr + i);

		if (i != size - 1) std::cout << " ";
	}
		
	std::cout << std::endl << "Arithmetic mean of all game results: " 
		<<  (*func)(arr, size ) << std::endl;

}
