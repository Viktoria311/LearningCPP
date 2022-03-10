#include <iostream>
#include <vector>
#include "golf.h"
#include "functions.h"

int main()
{
	std::vector<Golf> vec;

	AddGolf(vec);
	Show(vec);

	return 0;
}