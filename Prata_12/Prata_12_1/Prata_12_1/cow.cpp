#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
	name_ = "no name";
	hobby_ = nullptr;
	weight_ = 0.0;
}

Cow::Cow(const std::string& name, const char* hobby, double weight)
{
	name_ = name;
	hobby_ = new char[strlen(hobby) + 1];
	strcpy_s(hobby_, strlen(hobby) + 1, hobby);
	weight_ = weight;
}

Cow::Cow(const Cow& c)
{
	name_ = c.name_;
	hobby_ = new char[strlen(c.hobby_) + 1];
	strcpy_s(hobby_, strlen(c.hobby_) + 1, c.hobby_);
	
	weight_ = c.weight_;
}

Cow::Cow(Cow&& c)
{
	name_ = std::move(c.name_);
	hobby_ = std::move(c.hobby_);
	weight_ = c.weight_;
}

Cow::~Cow()
{
	delete[] hobby_;
}

void Cow::ShowCow() const
{
	std::cout << "name: " << name_ << std::endl;
	std::cout << "hobby: " << hobby_ << std::endl;
	std::cout << "weight: " << weight_ << std::endl;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c) return *this;
	else
	{
		name_ = c.name_;

		delete[] hobby_;
		hobby_ = new char[strlen(c.hobby_ + 1)];
		strcpy_s(hobby_, strlen(c.hobby_) + 1, c.hobby_);
		
		weight_ = c.weight_;

		return *this;
	}
}

Cow& Cow::operator=(Cow&& c)
{
	name_ = std::move(c.name_);
	hobby_ = std::move(c.hobby_);
	weight_ = c.weight_;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Cow& c)
{
	os << "name: " << c.name_ << std::endl;
	os << "hobby: " << c.hobby_ << std::endl;
	os << "weight: " << c.weight_ << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Cow& c)
{
	std::string name;

	char hobby[20];

	double weight;

	std::cout << "Enter a cow name: ";
	getline(is, name);

	std::cout << "Enter a cow hobby: ";
	is.getline(hobby, 20);

	std::cout << "Enter a cow weight: ";
	while (!(is >> weight))
	{
		is.clear();
		is.ignore(100, '\n');
		std::cout << "Try to enter a cow weight again: ";
	}

	c = Cow(name, hobby, weight);
	return is;
}