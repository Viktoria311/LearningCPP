#include <iostream>
#include "sales.h"

int main()
{
	SALES::Sales my_struct_1;

	SALES::Sales my_struct_2;

	double my_arr[] = { 177.2, 200, 85.5, 82.4 };

	SALES::setSales(my_struct_1, my_arr, 4);

	SALES::setSales(my_struct_2);

	SALES::showSales(my_struct_1);

	SALES::showSales(my_struct_2);

	std::cout << "Bye!" << std::endl;

	return 0;
}