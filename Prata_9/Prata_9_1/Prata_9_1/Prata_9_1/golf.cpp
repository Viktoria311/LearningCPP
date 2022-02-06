#include <iostream>
#include <cstring>
#include "golf.h"

//void setgolf( golf& g, const char* name, int hc )
//{
//	strcpy(g.fullname, name);
//	g.handicap = hc;
//}
extern const int Len;

int setgolf(golf& g)
{
	std::cout << "Enter a name: ";
	while (std::cin.get() != '\n') continue;
	std::cin.getline(g.fullname, Len);
	std::cout << "Enter a handicap: ";
	while (  !(std::cin >> g.handicap)  )
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter a handicap: ";
	}
	if (strlen(g.fullname) == 0) return 0;
	else return 1;
}
     
void change_handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << "Look at this:" << std::endl;
	std::cout << "The name is " << g.fullname << std::endl;
	std::cout << "the handicap is " << g.handicap << std::endl;
}
void new_function(golf* gg, void (*func1)(golf&, int), void (*func2)(const golf&))
{
	bool want;

	int new_handicap;

	std::cout << "Do you want to change a handicap of the struct? 1 - yea, 0 - no" << std::endl;
	std::cin >> want;
	if (want)
	{
		
		std::cout << "Enter a number on which you want to change a handicap: ";
		while (!(std::cin >> new_handicap))  continue;
		func1(*gg, new_handicap);
		std::cout << "Do you want to look at the changing struct? 1 - yes, 0 - no " << std::endl;
		std::cin >> want;
		if (want) func2(*gg);
	}
	else std::cout << "Okey, we will not change its handicap." << std::endl;
}

void new_function(golf* gg, void (*func1)(golf&, int), void (*func2)(const golf&), int quantity_of_elements)
{
	bool want;

	int number_of_the_struct;

	int new_handicap;

	std::cout << "Do you want to change a handicap of any struct? 1 - yes, 0 - no ";
	std::cin >> want;
	do {

		if (want)
		{
			
			std::cout << "What struct in the array do you want to change?\n";
			std::cout << "Enter a number of a struct in the array which you want to change from 1 to "
				      << quantity_of_elements << ":  ";


			while (!(std::cin >> number_of_the_struct) ||
				number_of_the_struct > quantity_of_elements ||
				number_of_the_struct < 0)
			{
				if (!std::cin)
				{
					std::cin.clear();
					std::cin.ignore(100, '\n');
					std::cout << "Try again to enter a number of a struct: ";
				}
				else if ( number_of_the_struct > quantity_of_elements || number_of_the_struct < 0)
					std::cout << "Error. enter a number from 1 to " << quantity_of_elements << " ";
			}

			std::cout << "Enter a new handicap: ";
			while( !(std::cin >> new_handicap) )
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Try again to enter a handicap: ";
			}

			func1(*(gg + number_of_the_struct - 1), new_handicap);
			std::cout << "Do you want to look at the changing struct? 1 - yes, 0 - no " << std::endl;
			std::cin >> want;
			if (want) func2(*(gg + number_of_the_struct - 1));
			std::cout << "Do you want to change a handicap of another struct? 1 - yes, 0 - no ";
			std::cin >> want;
		}
		else std::cout << "Okey, we will not change its handicap." << std::endl;
	} while (want);
}