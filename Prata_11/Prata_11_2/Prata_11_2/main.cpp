#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "vect.h"
#include "funcs.h"

int main()
{
	double direction;
	unsigned long  steps = 0;
	double target;
	double dstep;

	MainLoop(target, steps, direction, dstep);

	std::cout << "Bye!" << std::endl;

	return 0;
}