#include <iostream>
#include "my_stock.h"

const int STKS = 4;

int main()
{
	MyStock stocks[STKS] = {
								MyStock("NanoSmart", 12, 20.0),
								MyStock("Boffo Objects", 200, 2.0),
								MyStock("Monolithic Obelisks", 130, 3.25),
								MyStock("Fleep Enterprises", 60, 6.5)
							};

	std::cout << "Stock holdings:" << std::endl;
	for (int i = 0; i < STKS; ++i)
		std::cout << stocks[i];
	const MyStock* top = &stocks[0];
	for (int i = 1; i < STKS; ++i)
		top = &top->topval(stocks[i]);
	std::cout << std::endl << "Most valuable holding:" << std::endl;
	std::cout << *top;

	return 0;
}