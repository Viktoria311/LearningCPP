#include <iostream>

double func(double x, double y);

int main()
{
	double x;

	double y;

	std::cout << "This program was made by count a Harmonic Mean of two numbers.\n";

	std::cout << "Enter two numbers, 0 to quit: ";

	while (std::cin >> x   &&   x != 0   &&   std::cin >> y   &&    y != 0)
	{
		std::cout << "The Harmonic Mean of  your numbers is " << func(x, y) << std::endl;

		std::cout << "Enter two numbers, 0 to quit: ";
	}
	
	std::cout <<  "You write 0 to quit\nBye!";

	return 0;
 }

double func(double x, double y)
{
	return 2.0 * x * y / (x + y);
}