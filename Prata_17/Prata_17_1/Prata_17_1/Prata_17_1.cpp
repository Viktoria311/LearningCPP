#include <iostream>

int main()
{
	int count = 0;

	std::cout << "Enter a string and the program will count symbols before the first $." << std::endl;

	while (std::cin.get() != '$')
		++count;

	std::cin.ignore(100, '\n');
	std::cout << count << " symbols before the first $" << std::endl;

	return 0;
}
