#include <iostream>

template <typename T>
void ShowArray(T* arr, int n);

template <typename T>
void ShowArray(T* arr[], int n);

template <typename T>
auto SumArray(T* arr, int n) ->decltype(arr[0]);

template <typename T> 
auto SumArray(T* arr[], int n) -> decltype(**arr);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	int things[6] = { 13, 31, 103, 301, 310, 130 };

	debts my_array[3] = {
							{ "Ima Wolfe", 2400.0},
							{ "Ura Foxe", 1300.0},
							{ "Iby Stout", 1800.0}
						};

	double* pd[3];

	for (int i = 0; i < 3; ++i)
		pd[i] = &my_array[i].amount;

	
	std::cout << "Listing Mr. E`s counts of things:  ";
	ShowArray(things, 6);
	std::cout << "A quantity of things is ";
	std::cout << SumArray(things, 6);
	std::cout << std::endl << std::endl <<"Listing Mr. E`s debts:  ";
	ShowArray(pd, 6);
    std::cout << "The summ of all debts is ";
	std::cout << SumArray(pd, 3) << "\n" << std::endl;
	//2 шаблон функции, возвращающие сумму содержимого массива вместо его отображения
	//сообщать общее колич предметов и сумму всех задолженностей
	return 0;
}

template <typename T>
void ShowArray(T* arr, int n)
{
	std::cout << "\ntemplate A\n";
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i];
		if (i != n - 1) std::cout << "  ";
	}
	std::cout << std::endl;
}

template <typename T>
void ShowArray(T* arr[], int n)
{
	std::cout << "\ntemplate B\n";
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(arr[i]);
		if (i != n - 1) std::cout << "  ";
	}
	std::cout << std::endl;
}

template <typename T>
auto SumArray(T* arr, int n) ->decltype(arr[0])
{
	T summ = arr[0];
	for (int i = 1; i < n; ++i)
		summ += arr[i];
	return summ;
}

template <typename T>
auto SumArray(T* arr[], int n) -> decltype(**arr)
{
	decltype(*arr[0]) sum = *arr[0];

	for (int i = 1; i < n; ++i)
		sum += *arr[i];

	return sum;
}