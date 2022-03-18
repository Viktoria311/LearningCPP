#include <iostream>
#include "complex0.h"
#include "funcs.h"

void CompareTheNumberWithOthers(const Complex0& a)
{
	Complex0 c;

	std::cout << "Enter a complex number (q to quit): " << std::endl;
	while (std::cin >> c)
	{
		std::cout << "c is " << c << std::endl;
		std::cout << "complex conjugate is " << ~c << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "a + c is " << a + c << std::endl;
		std::cout << "a - c is " << a - c << std::endl;
		std::cout << "a * c is " << a * c << std::endl;
		std::cout << "2 * c is " << 2 * c << std::endl;
		std::cout << "Enter a complex number (q to quit): " << std::endl;
	}
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
}


