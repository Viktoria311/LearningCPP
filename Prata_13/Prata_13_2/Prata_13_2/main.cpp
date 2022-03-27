#include <iostream>
#include <string>
#include "cd.h"

void Bravo(const CD& disc);

int main()
{
	CD c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	CD* pcd = &c1;
	std::cout << "Using objects directly:" << std::endl;
	c1.Report();
	c2.Report();
	std::cout << "Using type cd * pointer to objects:";
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	std::cout << "Calling a function with a cd reference argument:" << std::endl;
	Bravo(c1);
	Bravo(c2);
	std::cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const CD& disc)
{
	disc.Report();
}