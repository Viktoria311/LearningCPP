#include <iostream>
#include <valarray>
#include "my_classes.h"
#include "my_templates.h"


int Cool_Pair::size() const
{
	const std::valarray<int> y = Pair::years();

	return y.size();
}

void Cool_Pair::GetBottles()
{
	std::cout << "Enter years and quantity of bottles." << std::endl;
	for (int i = 0; i < this->size(); ++i)
	{
		std::cout << "enter " << i + 1 << " year: ";
		std::valarray<int> y = Pair<std::valarray<int>, std::valarray<int>>::years();
		while (!(std::cin >> y[i]))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Try again to enter " << i + 1 << " year: ";
		}

		std::cout << "enter quantity of bottles in " << y[i] << ": ";
		std::valarray<int>& b = Pair<std::valarray<int>, std::valarray<int>>::bottles();
		while (!(std::cin >> b[i]))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Try again to enter quantity of bottles in " << y[i] << ": ";
		}
	}
}
int Cool_Pair::sum() const
{
	int z = 0;
	const std::valarray<int> b = Pair<std::valarray<int>, std::valarray<int>>::bottles();

	for (int i = 0; i < size(); ++i)
		z += b[i];

	return z;
}

int Cool_Pair::years(int i) const
{
	if (this->size() <= i)
		return 0;
	else
		return (Pair<std::valarray<int>, std::valarray<int>>::years())[i];
}

int Cool_Pair::bottles(int i) const
{
	if (this->size() <= i)
		return 0;
	else
		return (Pair<std::valarray<int>, std::valarray<int>>::bottles())[i];
}

void Cool_Pair::Show() const
{
	std::cout << "Look at the pairs!" << std::endl;

	for (int i = 0; i < this->size(); ++i)
		std::cout << years(i) << ": " << bottles(i) << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Wine::Wine(const std::string& name, int q, const int* y, const int* b) : name_(name), p_(q, y, b)
{

}

Wine::Wine(const std::string& name, int q) : name_(name), p_(q)
{

}

void Wine::GetBottles()
{
	p_.GetBottles();
}

const std::string& Wine::Label() const
{
	return name_;
}

int Wine::sum() const
{
	return p_.sum();
}

void Wine::Show() const
{
	std::cout << "Wine: " << name_ << std::endl;
	std::cout << '\t' << "Year\tBottles\n";
	for (int i = 0; i < p_.size(); ++i)
		std::cout << "\t" << p_.years(i) << "\t" << p_.bottles(i) << std::endl;
}