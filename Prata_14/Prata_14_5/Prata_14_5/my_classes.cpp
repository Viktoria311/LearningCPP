#include <iostream>
#include <string>
#include "my_classes.h"


void AbstractEmploee::SetName()
{
	std::cout << "Enter a name: ";
	getline(std::cin, name_);
}

void  AbstractEmploee::SetSurname()
{
	std::cout << "Enter a surname: ";
	getline(std::cin, surname_);
}

void  AbstractEmploee::SetJob()
{
	std::cout << "Enter a job: ";
	getline(std::cin, job_);
}

void AbstractEmploee::ShowName() const
{
	std::cout << "Name: " << name_ << std::endl;
}
void AbstractEmploee::ShowSurname() const
{
	std::cout << "Surname: " << surname_ << std::endl;
}
void AbstractEmploee::ShowJob() const
{
	std::cout << "Job: " << job_ << std::endl;
}

AbstractEmploee::AbstractEmploee() : name_("unknown"), surname_("unknown"), job_("unknown")
{

}

AbstractEmploee::AbstractEmploee(const std::string& name, const std::string& surname, const std::string& job) : name_(name), surname_(surname), job_(job)
{

}

AbstractEmploee::~AbstractEmploee()
{

}

void  AbstractEmploee::Show() const
{
	ShowName();
	ShowSurname();
	ShowJob();
}

void  AbstractEmploee::Set()
{
	SetName();
	SetSurname();
	SetJob();
}

std::ostream& operator<<(std::ostream& os, const AbstractEmploee& emp)
{
	os << emp.name_ << " " << emp.surname_;
	return os;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EMPLOEE

Emploee::Emploee() : AbstractEmploee()
{

}

Emploee::Emploee(const std::string& name, const std::string& surname, const std::string& job) : AbstractEmploee(name, surname, job)
{

}

Emploee::~Emploee()
{

}

void Emploee::Show() const
{
	AbstractEmploee::Show();
}

void Emploee::Set()
{
	AbstractEmploee::Show();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MANAGER

void Manager::SetSubordinates()
{
	std::cout << "Enter quantity of subordinates: ";
	while(!(std::cin >> subordinates_))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter quantity of subordinates: ";
	}
}

void  Manager::ShowSubordinates() const
{
	std::cout << "Subordinates: " << subordinates_ << std::endl;
}

int Manager::subordinates() const
{
	return subordinates_;
}

Manager::Manager() : AbstractEmploee(), subordinates_(0)
{

}

Manager::Manager(const std::string& name, const std::string& surname, const std::string& job, int subordinates) : AbstractEmploee(name, surname, job), subordinates_(subordinates)
{

}

Manager::Manager(const AbstractEmploee& emp, int subordinates) : AbstractEmploee(emp), subordinates_(subordinates)
{

}

Manager::Manager(const Manager& m) :AbstractEmploee(m), subordinates_(m.subordinates())
{

}

Manager::~Manager()
{

}

void Manager::Show() const
{
	AbstractEmploee::Show();
	ShowSubordinates();
}

void Manager::Set()
{
	AbstractEmploee::Set();
	SetSubordinates();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FINK

void Fink::SetReportsTo()
{
	std::cout << "Enter who reports to: ";
	getline(std::cin, reports_to_);
}

const std::string& Fink::reports_to() const
{
	return reports_to_;
}

void Fink::ShowReportsTo() const
{
	std::cout << "reports to: " << reports_to_ << std::endl;
}

Fink::Fink() : AbstractEmploee(), reports_to_("unknown")
{

}

Fink::Fink(const std::string& name, const std::string& surname, const std::string& job, const std::string& reports_to) : AbstractEmploee(name, surname, job), reports_to_(reports_to)
{

}

Fink::Fink(const AbstractEmploee& emp, const std::string& reports_to) : AbstractEmploee(emp), reports_to_(reports_to)
{

}

Fink::Fink(const Fink& f) : AbstractEmploee(f), reports_to_(f.reports_to())
{

}

Fink::~Fink()
{

}

void Fink::Show() const
{
	AbstractEmploee::Show();
	ShowReportsTo();
}

void Fink::Set()
{
	AbstractEmploee::Set();
	SetReportsTo();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//HIGH FINK

HighFink::HighFink() : AbstractEmploee(), Manager(), Fink()
{

}

HighFink::HighFink(const std::string& name, const std::string& surname, const std::string& job, std::string& reports_to, int subordinates) : AbstractEmploee(name, surname, job),
Manager(name, surname, job, subordinates), Fink(name, surname, job, reports_to)
{

}

HighFink::HighFink(const AbstractEmploee& emp, const std::string& reports_to, int subordinates) : AbstractEmploee(emp), Manager(emp, subordinates), Fink(emp, reports_to)
{

}

HighFink::HighFink(const Fink& f, int subordinates) : AbstractEmploee(f), Manager(f, subordinates), Fink(f)
{

}

HighFink::HighFink(const Manager& m, const std::string& reports_to) : AbstractEmploee(m), Manager(m), Fink(m, reports_to)
{

}

HighFink::HighFink(const HighFink& h) : AbstractEmploee(h), Manager(h), Fink(h)
{

}

HighFink::~HighFink()
{

}

void HighFink::Show() const
{
	AbstractEmploee::Show();
	ShowSubordinates();
	ShowReportsTo();
}

void HighFink::HighFink::Set()
{
	AbstractEmploee::Set();
	SetSubordinates();
	SetReportsTo();
}