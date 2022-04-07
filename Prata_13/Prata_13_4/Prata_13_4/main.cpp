#include <iostream>
#include "Port.h"

int main()
{
	Port f1;
	Port s2("Jack Daniels");
	Port th3 = { "Jack Daniels", "modern", 150 };
	VintagePort f4;
	VintagePort f5( "New Brand", 200, "Old Velvet", 1985);
	f1.Show();
	std::cout << s2 << std::endl;
	std::cout << th3 << std::endl;
	f4.Show();
	std::cout << f5 << std::endl;

	Port* arr[5];
	arr[0] = &f1;
	arr[1] = &s2;
	arr[2] = &th3;
	arr[3] = &f4;
	arr[4] = &f5;

	for (int i = 0; i < 5; ++i)
		std::cout << *arr[i] << std::endl;
	return 0;
}