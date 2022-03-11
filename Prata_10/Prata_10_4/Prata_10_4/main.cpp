#include <iostream>
#include <array>
#include <vector>
#include "funcs.h"
#include "sales.h"

int main()
{
	std::vector<double> vec1 = { 32.4, 23.6, 22.4, 45.2 };

	std::vector<double> vec2 = { 56.7, 45.4 };

	std::vector<SALES::Sales> my_vec;

	my_vec.push_back(SALES::Sales(vec1));

	my_vec.push_back(SALES::Sales(vec2));

	my_vec.push_back(SALES::Sales());
	
	Show(my_vec);

	return 0;
}
