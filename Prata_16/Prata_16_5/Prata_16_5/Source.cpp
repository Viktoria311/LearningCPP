#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>

template<typename T>
int reduce(T ar[], int n);

int reduce(long& n);

int reduce(std::string& str);


int main()
{
	double arr[] = { 23.4, 33.0, 43.5, 33.0, 49.0, 23.4 };
	std::string word = "otto";
	long number_1 = 475468678; // 45678
	int number_2 = 124251; // 1245

	
	std::cout << "The array: ";
	for(auto elem : arr)
	{
		std::cout << elem << " ";
	}
	int unique_elements_count = reduce(arr, sizeof(arr) / sizeof(arr[0]));
	std::cout << " has " << unique_elements_count << " unique elements: ";
	for (int i = 0; i < unique_elements_count; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "The word: " << word;
	std::cout << " has "<< reduce(word) << " unique symbols: " << word << std::endl;

	std::cout << "The number: " << number_1;
	std::cout << " has " << reduce(number_1) << " unique digits: ";
	std::cout << number_1 << std::endl;

	std::cout << "The number: " << number_2;
	std::cout << " has " << reduce(reinterpret_cast<long&>(number_2)) << " unique digits: ";
	std::cout << number_2 << std::endl;

	return 0;
}

template<typename T>
int reduce(T ar[], int n)
{
	std::sort(ar, ar + n);

	auto  iter = std::unique(ar, ar + n);

	int unique_count = 0;

	for(int i = 0; ar + i != iter; ++i)
	{
		++unique_count;
	}
	return unique_count;
}

int reduce(long& n)
{
	std::set<int> unique_digit;

	while (n)
	{
		unique_digit.insert(n % 10);
		n /= 10;
	}

	int quantity = unique_digit.size();

	int zero = static_cast<int>(pow(10, quantity - 1));

	for (auto i = unique_digit.begin(); i != unique_digit.end(); ++i)
	{
		n += (*i) * zero;
		zero /= 10;
	}

	return quantity;
}

int reduce(std::string& str)
{
	std::sort(str.begin(), str.end());
	str.erase(std::unique(str.begin(), str.end()), str.end());

	return str.size();
}