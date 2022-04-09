#include <iostream>
#include <string>
#include <valarray>
#include "my_classes.h"

int main()
{
	char lab[50];

	int q_years;

	std::cout << "Enter a name of wine: ";
	std::cin.getline(lab, 50);
	std::cout << "Enter number of years: ";
	while (!(std::cin >> q_years))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter number of years: ";
	}

	Wine my_wine(lab, q_years);
	my_wine.GetBottles();
	my_wine.Show();

	const int YRS = 3;
	int y[YRS] = { 1985, 1986, 1973 };
	int b[YRS] = { 48, 60, 72 };
	Wine second_wine("Gushing Grape Red", YRS, y, b);
	second_wine.Show();
	std::cout << "Total bottles for " << second_wine.Label() << ": " << second_wine.sum() << std::endl;

	std::cout << "Use operator const std::string& : " << (const std::string&)second_wine << std::endl;

	std::cout << "Bye!" << std::endl;

	return 0;
}

