#include <iostream>
#include "complex0.h"
#include "funcs.h"

int main()
{
	Complex0 a(3.0, 4.0);

	CompareTheNumberWithOthers(a);

	std::cout << "Bye!" << std::endl;

	return 0;
}