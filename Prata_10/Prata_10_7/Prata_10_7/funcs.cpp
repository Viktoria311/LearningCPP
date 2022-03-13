#include <iostream>
#include <vector>
#include <string>
#include "plorg.h"

std::string EnterName()
{
	std::string name;
	std::cout << "Please enter a Plorg1s name: " << std::endl;
	getline(std::cin, name);
	return name;
}

void AddObject(std::vector<Plorg>& vec_of_plorgs)
{
	bool want;

	std::cout << "Do you want to enter Plorg`s name? 1 - yes, 0 - no ";
	std::cin >> want;
	std::cin.ignore(100, '\n');
	if (want)
	{
		vec_of_plorgs.push_back(Plorg(EnterName()));
	}
	else vec_of_plorgs.push_back(Plorg());
}

int EnterCI()
{
	int index;

	std::cout << "Enter new CI please: ";
	while (!(std::cin >> index))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Please try to enter new CI again: ";
	}
	return index;
}

void DoYouWantToChangeCI(std::vector<Plorg>& vec_of_plorgs)
{
	bool want;

	std::cout << "Do you want to change CI of this object? 1 - yes, 0 - no ";
	std::cin >> want;
	std::cin.ignore(100, '\n');
	if (want)
	{
		vec_of_plorgs[vec_of_plorgs.size() - 1].ChangeCI(EnterCI());
		std::cout << "Changing ";
		vec_of_plorgs[vec_of_plorgs.size() - 1].ShowCI();
	}
}

void ShowAllObjects(const std::vector<Plorg>& vec_of_plorgs)
{
	int count = 1;

	std::cout << std::endl << "There are " << vec_of_plorgs.size() << " objects. Look at it." << std::endl;
	for (std::vector<Plorg>::const_iterator i = vec_of_plorgs.cbegin(); i != vec_of_plorgs.cend(); ++i)
	{
		std::cout << "Plorg " << count << ":" << std::endl;
		i->ShowPlorg();
		++count;
	}
}

void MainLoop(std::vector<Plorg>& vec_of_plorgs)
{
	bool want;

	std::cout << "Welcome!" << std::endl;
	do
	{
		AddObject(vec_of_plorgs);
		vec_of_plorgs[vec_of_plorgs.size() - 1].ShowPlorg();
		DoYouWantToChangeCI(vec_of_plorgs);
		std::cout << "Do you want to add one more object? 1 - yes, 0 - no ";
		std::cin >> want;
		std::cin.ignore(100, '\n');
	} while(want);
	ShowAllObjects(vec_of_plorgs);

	std::cout << "Bye!";
}