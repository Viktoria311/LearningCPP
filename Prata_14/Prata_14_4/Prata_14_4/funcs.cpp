#include <iostream>
#include <string>


void EnterIdentyfire(int& identity_)
{
	std::cout << " Enter idenifire what object do you want to create." << std::endl;
	std::cout << "1 - Person\n2 - Gunsligter\n3 - PocketPlayer\n4 - BadDude\n";
	while (!(std::cin >> identity_))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter an identity: ";
	}
}

void WantEnterFullName(bool& want_)
{

	std::cout << "Do you want to enter a name and a surname? 1 - yes, 0 - no : ";
	std::cin >> want_;
	std::cin.ignore(100, '\n');
}

void EnterTimeAndNotches(double& d, int& notches_)
{
	std::cout << "Enter prepare time: ";
	while (!(std::cin >> d))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter prepare time: ";
	}
	std::cout << "Enter quantity of notches: ";
	while (!(std::cin >> notches_))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter quantity of notches: ";
	}
}



