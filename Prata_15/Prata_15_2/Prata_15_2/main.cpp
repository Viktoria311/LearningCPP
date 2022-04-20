#include <iostream>
#include "my_exept.h"
#include "my_funcs.h"



int main()
{

	double x, y, z;

	std::cout << "Enter 2 numbers: ";
	while (std::cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			
			std::cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << std::endl;
			std::cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << std::endl;
			std::cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (bad_hmean& m)
		{
			m.mess();
			std::cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean& hg)
		{
			std::cout << hg.mess();
			std::cout << "Values used: " << hg.v1 << ", "
				<< hg.v2 << std::endl;
			std::cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}

	std::cout << "Bye" << std::endl;

	return 0;
}