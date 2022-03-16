#include <iostream>
#include "my_time.h"

int main()
{
	MyTime Aida(3, 35);

	MyTime Tosca(2, 48);

	std::cout << "Opera \"Aida\" lasts " << Aida << std::endl;
	std::cout << "Opera \"Tosca\" lasts " << Tosca << std::endl;
	std::cout << "Two operas last " << Aida + Tosca << std::endl;
	std::cout << "Opera \"Aida\" one and a half times slower lasts " << Aida * 1.5 << std::endl;
	std::cout << "Opera \"Tosca\" 2 times faster lasts " << Tosca * 0.5 << std::endl;

	return 0;
}