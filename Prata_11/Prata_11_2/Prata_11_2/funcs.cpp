#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "vect.h"
#include "funcs.h"

void StartingOutputToFile(std::ofstream& fout, double& target, double& dstep)
{
	fout << "Target Distance: " << target << ", Step Size: " << dstep << std::endl;
	fout << "0: (x,y) = (0, 0)" << std::endl;
}

void OutputEveryStepToFile(std::ofstream& fout, Vect& result, double& target, unsigned long& steps, double& direction, double& dstep)
{
	while (result.magval() < target)
	{
		Vect step;
		direction = rand() % 360;
		step.reset(dstep, direction, Vect::POL);
		result = result + step;
		++steps;
		fout << steps << ": " << result << std::endl;
	}
}

void EndingOutputToFile(std::ofstream& fout, Vect& result, unsigned long& steps)
{
	fout << "After " << steps << " steps, the subject has the following location:" << std::endl;
	fout << result << std::endl;
	result.polar_mode();
	fout << "or\n" << result << std::endl;
	fout << "Average outward distance per step = " << result.magval() / steps << std::endl;
}

void MainLoop(double& target, unsigned long& steps, double& direction, double& dstep)
{
	srand(time(0));
	std::cout << "Enter target distance (q to quit): ";

	std::ofstream fout;
	fout.open("vect.txt");
	if (!(fout.is_open()))
		exit(EXIT_FAILURE);

	Vect result(0.0, 0.0);

	while (std::cin >> target)
	{
		std::cout << "Enter step length: ";
		if (!(std::cin >> dstep)) break;

		StartingOutputToFile(fout, target, dstep);
		OutputEveryStepToFile(fout, result, target, steps, direction, dstep);
		EndingOutputToFile(fout, result, steps);
		steps = 0;
		result.reset(0.0, 0.0);
		std::cout << "Enter target distance (q to quit): ";
	}
	fout.close();
}