#include <iostream>
#include <cstring>
#include "plorg.h"


Plorg::Plorg(const std::string name, int CI)
{
	name_ =  name;
	CI_ = CI;
}

Plorg::Plorg()
{
	name_ = "Plorga";
	CI_ = 50;
}

void Plorg::ShowName() const
{
	std::cout << "Plorg name: " << name_ << std::endl;
}

void Plorg::ShowCI() const
{
	std::cout << "CI : " << CI_ << std::endl;
}

void Plorg::ShowPlorg() const
{
	this->ShowName();
	this->ShowCI();
}

void Plorg::ChangeCI(int index)
{
	CI_ = index;
}