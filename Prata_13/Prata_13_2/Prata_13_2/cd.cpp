#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "cd.h"


CD::CD(const char* s1, const char* s2, int n, double x)
{
	performers_ = new char[strlen(s1) + 1];
	strncpy(performers_, s1, strlen(s1));
	performers_[strlen(s1)] = '\0';
	label_ = new char[strlen(s2) + 1];
	strncpy(label_, s2, strlen(s2));
	label_[strlen(s2)] = '\0';
	selections_ = n;
	playtime_ = x;
}

CD::CD(const CD& d)
{
	performers_ = new char[strlen(d.performers_) + 1];
	strncpy(performers_, d.performers_, strlen(d.performers_));
	performers_[strlen(d.performers_)] = '\0';
	label_ = new char[strlen(d.label_) + 1];
	strncpy(label_, d.label_, strlen(d.label_));
	label_[strlen(d.label_)] = '\0';

	selections_ = d.selections_;
	playtime_ = d.playtime_;
}

CD::CD()
{
	performers_ = new char[strlen("some") + 1];
	strncpy(performers_, "some", strlen("some"));
	performers_[strlen("some")] = '\0';
	label_ = new char[strlen("some") + 1];
	strncpy(label_, "some", strlen("some"));
	label_[strlen("some")] = '\0';

	selections_ = 0;
	playtime_ = 0.0;
}

CD::~CD()
{
	delete[] performers_;
	delete[] label_;
}

void CD::Report() const
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
		delete[] performers_;
		delete[] label_;
		performers_ = new char[strlen(d.performers_) + 1];
		strncpy(performers_, d.performers_, strlen(d.performers_));
		performers_[strlen(d.performers_)] = '\0';
		label_ = new char[strlen(d.label_) + 1];
		strncpy(label_, d.label_, strlen(d.label_));
		label_[strlen(d.label_)] = '\0';

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


Classic::Classic(const char* song, const  char* s1, const char* s2, int n, double x) : CD(s1, s2, n, x)
{
	main_song_ = new char[strlen(song) + 1];
	strncpy(main_song_, song, strlen(song));
	main_song_[strlen(song)] = '\0';
}

Classic::Classic() : CD()
{
	main_song_ = new char[strlen("some") + 1];
	strncpy(main_song_, "some", strlen("some"));
	main_song_[strlen("some")] = '\0';
}

Classic::~Classic()
{
	delete[] main_song_;
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
		delete[] performers_;
		delete[] label_;
		delete[] main_song_;
		performers_ = new char[strlen(d.performers_) + 1];
		strncpy(performers_, d.performers_, strlen(d.performers_));
		performers_[strlen(d.performers_)] = '\0';
		label_ = new char[strlen(d.label_) + 1];
		strncpy(label_, d.label_, strlen(d.label_));
		label_[strlen(d.label_)] = '\0';

		selections_ = d.selections_;
		playtime_ = d.playtime_;

		main_song_ = new char[strlen(d.main_song_) + 1];
		strncpy(main_song_, d.main_song_, strlen(d.main_song_));
		main_song_[strlen(d.main_song_)] = '\0';
		
		return *this;
	}
}

std::ostream& operator<<(std::ostream& os, const Classic& classic)
{
	(operator<<(os, (CD)classic)) << "Main song: " << classic.main_song_ << std::endl;
	return os;
}