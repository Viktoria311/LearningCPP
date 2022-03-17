#include <iostream>
#include "stonewt.h"

int main()
{
	Stonewt my(450.0);

	Stonewt Ann(20, 11);

	Stonewt Kate(13, 9);

	std::cout << "Kate have " << Kate << std::endl;
	std::cout << "I have " << my << std::endl;
	std::cout << "Ann have " << Ann << std::endl;
	std::cout << "We all have " << Kate + my + Ann << std::endl;
	std::cout << "Kate and Ann have " << Kate + Ann << std::endl;
	std::cout << "Kate have put on 5.4 percent her money. In a year she will have " << Kate + Kate * 0.054 << std::endl;
	std::cout << "Bye! " << std::endl;

	return 0;
}