#include <iostream>
#include "move.h"


void EnterCoordinate(double& c)
{
	while (!(std::cin >> c))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
}

void Entering(double& x, double& y)
{
	std::cout << " Enter x: ";
	EnterCoordinate(x);
	std::cout << " Enter y: ";
	EnterCoordinate(y);
}

void MainLoop(Move& customer)
{
	bool want;

	double x;

	double y;

	do
	{
		customer.ShowMove();
		std::cout << "Please enter coordinates to move:" << std::endl;

		Entering(x, y);
		customer.Reset(x, y);
		customer.ShowMove();

		std::cout << "do you want to move more time? 1 - yes, 0 - no" << std::endl;
		std::cin >> want;
		std::cin.ignore(100, '\n');
	} while (want);
}