#include <iostream>
#include <vector>
#include <cstring>
#include "classes.h"

const int q = 1;

int main()
{
	MyABC* z[q];
	int rating_;
	int choice;

	for (int i = 0; i < q; ++i)
	{

		std::cout << "What object do you want to create?" << std::endl;
		std::cout << "1 - BaseDMA" << std::endl;
		std::cout << "2 - LacksDMA" << std::endl;
		std::cout << "3 - HasDMA" << std::endl;

		while (!(std::cin >> choice))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Try again to enter your choice: " << std::endl;
			std::cout << "1 - BaseDMA";
			std::cout << " 2 - LacksDMA";
			std::cout << " 3 - HasDMA" << std::endl;
		}

		std::cout << "Enter raiting of " << i + 1 << " client: ";
		while (!(std::cin >> rating_))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Try again to enter raiting: ";
		}
		std::cin.ignore(100, '\n');

		switch (choice)
		{
			case 1: 
			{
				std::cout << "Enter label: ";
				char* label = new char[40];
				std::cin.getline(label, 40);
				z[i] = new BaseDMA(rating_, label);
				delete[] label;
				break;
			}
			case 2: 
			{
				std::cout << "Enter color: ";
				char* color = new char[40];
				std::cin.getline(color, 40);
				z[i] = new LacksDMA(rating_, color);
				delete[] color;
				break;
			}
			case 3:
			{
				std::cout << "Enter style: ";
				char* style = new char[40];
				std::cin.getline(style, 40);
				z[i] = new HasDMA(rating_, style);
				delete[] style;
				break;
			}
		}
	}

	for(int i = 0; i < q; ++i)
		z[i]->Show();

	for(int i = 0; i < q; ++i)
		delete[] z[i];

	return 0;
}