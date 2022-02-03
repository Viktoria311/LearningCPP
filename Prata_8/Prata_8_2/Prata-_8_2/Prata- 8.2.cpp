#include <iostream>
#include <cstring>

const int SIZE = 30;
struct CandyBar
{
	char name[30];
	double weight;
	int kkal;
};

void setCandyBar(CandyBar& cb, const char* pn = "Millenium Munch", const double w = 2.85, const int k = 350);
void showCandyBar(const CandyBar& cb);

int main()
{
	bool again;

	std::cout << "Welcome to the program where  you can enter  data in struct and look at it." << std::endl;

	do
	{
			bool yourself;
			
			std::cout << "Do you want to set data of sweets`s box yourself? 1- yes, 0 - no\n";
			std::cin >> yourself;
			CandyBar my_box;
			if (!yourself) setCandyBar(my_box);
			else
			{
				char p_box_name[SIZE];
				
				std::cout << "Enter a name of the sweets`s box: ";
				while (std::cin.get() != '\n') continue;

				while (  std::cin.getline(p_box_name, SIZE) &&  strlen(p_box_name) == 0)
						std::cout << " Try to enter a name of the sweets`s box again: ";
			

				double box_weight;
				std::cout << "Enter weight of this box: ";
				while (!(std::cin >> box_weight))
				{
					std::cin.clear();
					std::cin.ignore(100, '\n');
					std::cout << "input error. Try to enter weight of this box again: ";
				}
				int box_kkal;
				std::cout << "Enter kkal of this sweets: ";
				while (!(std::cin >> box_kkal))
				{
					std::cin.clear();
					std::cin.ignore(100, '\n');
					std::cout << "input error. Try to enter kkal of these sweets again: ";
				}
				setCandyBar(my_box, p_box_name, box_weight, box_kkal);
			}
		showCandyBar(my_box);
		std::cout << "Do you want to repeate this loop again? 1 - yes, 0 - no\n";
		std::cin >> again;
		
	} while (again);

	std::cout << "It`s the end. Bye!\n";
	return 0;
}

void setCandyBar(CandyBar& cb, const char* pn, const double w, const int k)
{
	strcpy_s(cb.name, pn);
	cb.weight = w;
	cb.kkal = k;
}

void showCandyBar(const CandyBar& cb)
{
	std::cout << std::endl << "look at the sweet`s box:" << std::endl;
	std::cout << "The name of sweets box is " << cb.name << ".\n";
	std::cout << "This sweets box weighs " << cb.weight << " gramms.\n";
	std::cout << "This sweets box has " << cb.kkal << " kkals.\n";
}
