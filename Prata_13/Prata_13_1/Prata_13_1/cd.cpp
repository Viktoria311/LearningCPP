#include <iostream>
#include <string>
#include "cd.h"


CD::CD(const std::string& s1, const std::string& s2, int n, double x) : performers_(s1), label_(s2)
{
	selections_ = n;
	playtime_ = x;
}

CD::CD(const CD& d)
{
	performers_ =d.performers_;
	label_ = d.label_;
	selections_ = d.selections_;
	playtime_ = d.playtime_;
}

CD::CD()
{
	performers_ = "some";
	label_ = "some";
	selections_ = 0;
	playtime_ = 0.0;
}

CD::~CD()
{

}

void CD::Report() const // выводит все данные о компакт диске
{
	std::cout << "Performer: " << performers_ << std::endl;
	std::cout << "Label: " << label_ << std::endl;
	std::cout << "Selections: " << selections_ << std::endl;
	std::cout << "Playtime: " << playtime_ << " min" << std::endl;
}

CD& CD::operator=(const CD& d)
{
	if (this == &d) return *this;
	else
	{
		performers_ = d.performers_;
		label_ = d.label_;
		selections_ = d.selections_;
		playtime_ = d.playtime_;

		return *this;
	}
}

std::ostream& operator<<(std::ostream& os, const CD& cd)
{
	os << "Performer: " << cd.performers_ << std::endl;
	os << "Label: " << cd.label_ << std::endl;
	os << "Selections: " << cd.selections_ << std::endl;
	os << "Playtime: " << cd.playtime_ << " min" << std::endl;

	return os;
}


Classic::Classic(const std::string& song, const std::string& s1, const std::string& s2, int n, double x) : CD(s1, s2, n, x), main_song_(song)
{

}

Classic::Classic() : CD()
{

}

Classic::~Classic()
{

}

void Classic::Report() const
{
	this->CD::Report();
	std::cout << "Main song: " << main_song_ << std::endl;
}

Classic& Classic::operator=(const Classic& d)
{
	if (this == &d) return *this;
	else
	{
		performers_ = d.performers_;
		label_ = d.label_;
		selections_ = d.selections_;
		playtime_ = d.playtime_;
		main_song_ = d.main_song_;

		return *this;
	}
}

std::ostream& operator<<(std::ostream& os, const Classic& classic)
{
	(operator<<(os, (CD)classic)) << "Main song: " << classic.main_song_ << std::endl;
	return os;
}