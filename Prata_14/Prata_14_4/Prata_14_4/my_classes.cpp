#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "my_classes.h"

void Person::ShowName() const
{
	std::cout << "Name: " << name_ << std::endl;
}

void Person::ShowSurname() const
{
	std::cout << "Surname: " << surname_ << std::endl;
}

Person::Person() : name_("unknone") , surname_("unknone")
{

}

Person::Person(std::string& name, std::string surname) : name_(name), surname_(surname)
{

}

Person::~Person()
{

}

void Person::Show() const
{
	ShowName();
	ShowSurname();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GUNSLINGER

void Gunslinger::ShowPrepareTime() const
{
	std::cout << "Prepare time: " << prepare_time_ << std::endl;
}
void Gunslinger::ShowNotches() const
{
	std::cout << "Notches: " << quantity_of_rifle_notches_ << std::endl;
}

Gunslinger::Gunslinger() : Person(),  prepare_time_(0.0), quantity_of_rifle_notches_(0)
{

}

Gunslinger::Gunslinger(const Person& p, double t, int q) : Person(p), prepare_time_(t), quantity_of_rifle_notches_(q)
{

}

Gunslinger::Gunslinger(std::string& name, std::string surname, double t, int q) : Person(name, surname), prepare_time_(t), quantity_of_rifle_notches_(q)
{

}

Gunslinger::~Gunslinger()
{

}

void Gunslinger::Show() const
{
	Person::Show();
	ShowPrepareTime();
	ShowNotches();
}
double Gunslinger::Draw() const
{
	return prepare_time_;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//POCKET PLAYER


PockerPlayer::PockerPlayer() : Person()
{

}

PockerPlayer::PockerPlayer(std::string& name, std::string surname) : Person(name, surname)
{

}

PockerPlayer::PockerPlayer(const Person& p) : Person(p)
{

}

PockerPlayer::~PockerPlayer()
{

}

void PockerPlayer::Show() const   // Show от Person
{
	Person::Show();
}

int PockerPlayer::Draw() const   // случайное число от 1 до 52. это карта
{
	std::srand(time(0));

	return std::rand() % 52 + 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PBAD DUDE

BadDude::BadDude() : Person(), Gunslinger(), PockerPlayer()
{

}

BadDude::BadDude(const Person& p, double prepare_time, int notches) : Person(p), Gunslinger(p, prepare_time, notches), PockerPlayer(p)
{

}

BadDude::BadDude(std::string& name, std::string surname, double prepare_time, int notches) : Person(name, surname), Gunslinger(name, surname, prepare_time, notches), PockerPlayer(name, surname)
{

}

BadDude::BadDude(const PockerPlayer& p, double prepare_time, int notches) : Person(p), Gunslinger(p, prepare_time, notches), PockerPlayer(p)
{

}

BadDude::BadDude(const  Gunslinger& g) : Person(g), Gunslinger(g), PockerPlayer(g)
{

}

double BadDude::Gdraw() const   // время вынимания оружия
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw() const   // возвращает следующую вытянутую карту
{
	return PockerPlayer::Draw();
}

void BadDude::Show() const
{
	Gunslinger::Show();
	std::cout << "I like playing pocker!" << std::endl;
}