#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include "vect.h"
#include "funcs.h"

void StartingOutputToFile(std::ofstream& fout, double& target, double& dstep)
{
	fout << "Target Distance: " << target << ", Step Size: " << dstep << std::endl;
}

int CountingOfSteps(Vect& result, double& target, double& direction, double& dstep)
{
	unsigned long steps = 0;
	while (result.magval() < target)
	{
		Vect step;
		direction = rand() % 360;
		step.reset(dstep, direction, Vect::POL);
		result = result + step;
		++steps;
	}
	return steps;
}

void EndingOutputToFile(std::ofstream& fout, std::vector<int>& vec_of_steps_for_every_attempts)
{
	int max = vec_of_steps_for_every_attempts[0];
	int min = vec_of_steps_for_every_attempts[0];
	int sum = 0;
	int average_quantity_of_steps;

	for(int i = 0; i < vec_of_steps_for_every_attempts.size(); ++i)
	{
		if (max < vec_of_steps_for_every_attempts[i]) max = vec_of_steps_for_every_attempts[i];
		if (min > vec_of_steps_for_every_attempts[i]) min = vec_of_steps_for_every_attempts[i];
		sum += vec_of_steps_for_every_attempts[i];
	}

	average_quantity_of_steps = sum / vec_of_steps_for_every_attempts.size();

	fout << "max: " << max << std::endl;
	fout << "min: " << min << std::endl;
	fout << "average quantity of steps: " << average_quantity_of_steps << std::endl;

	/*fout << "After " << steps << " steps, the subject has the following location:" << std::endl;
	fout << result << std::endl;
	result.polar_mode();
	fout << "or\n" << result << std::endl;
	fout << "Average outward distance per step = " << result.magval() / steps << std::endl;*/
}

void ToFile()
{
	double direction;
	double target;
	double dstep;
	unsigned int attempts;
	Vect result(0.0, 0.0);

	srand(time(0));
	std::cout << "Enter target distance (q to quit): ";

	std::ofstream fout;
	fout.open("vect.txt");
	if (!(fout.is_open()))
		exit(EXIT_FAILURE);


	while (std::cin >> target)
	{
		std::vector<int> vec_of_steps_for_every_attempts;

		std::cout << "Enter step length: ";
		if (!(std::cin >> dstep)) break;

		std::cout << "Enter quantity of attempts: ";
		if (!(std::cin >> attempts)) break;

		StartingOutputToFile(fout, target, dstep);

		for(int i = 0; i < attempts; ++i)
			vec_of_steps_for_every_attempts.push_back(CountingOfSteps(result, target, direction, dstep));

		EndingOutputToFile(fout, vec_of_steps_for_every_attempts);
		
		result.reset(0.0, 0.0);
		std::cout << "Enter target distance (q to quit): ";
	}
	fout.close();
}