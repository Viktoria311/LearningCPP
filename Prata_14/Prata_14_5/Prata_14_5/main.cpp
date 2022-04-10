#include <iostream>
#include <string>
#include "my_classes.h"

const int size_of_elements = 4;

int main()
{
	Emploee em("Trip", "Harris", "Thumper");
	std::cout << em << std::endl;
	em.Show();

	Manager m("Amorphia" , "Spindragon", "Nuancer", 5);
	std::cout << m << std::endl;
	m.Show();

	Fink fi("Matt", "Oggs", "Oiler", "JunoBar");
	std::cout << fi << std::endl;
	fi.Show();

	HighFink hi(m, "Curly Cew");
	hi.Show();

	std::cout << "Enter a key for newt fase: ";
	std::cin.get();

	HighFink second_hi;
	second_hi.Show();

	std::cout << "Usind an AbstractEmploee* pointer: " << std::endl;

	AbstractEmploee* arr[size_of_elements] = { &em, &m, &fi, &hi };

	for (int i = 0; i < size_of_elements; ++i)
	{
		std::cout << "  *      *      *" << std::endl;
		arr[i]->Show();
	}
		
	return 0;
}