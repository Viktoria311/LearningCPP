#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "classes.h"


MyABC::MyABC(int r)
{
	rating = r;
}

void MyABC::Show() const
{
	std::cout << "Rating: " << rating << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BaseDMA::BaseDMA(int r, const char* c) : MyABC(r)
{
	label_ = new char[strlen(c) + 1];
	strncpy(label_, c, strlen(c));
	label_[strlen(c)] = '\0';
}

BaseDMA::BaseDMA(const BaseDMA& b) : MyABC(b)
{
	label_ = new char[strlen(b.label_) + 1];
	strncpy(label_, b.label_, strlen(b.label_));
	label_[strlen(b.label_)] = '\0';
}

BaseDMA::~BaseDMA()
{
	delete[] label_;
}

BaseDMA& BaseDMA::operator=(const BaseDMA& b)
{
	if (this == &b) return *this;
	else
	{
		delete[] label_;
		MyABC::operator=(b);
		label_ = new char[strlen(b.label_) + 1];
		strncpy(label_, b.label_, strlen(b.label_));
		label_[strlen(b.label_)] = '\0';
		return *this;
	}
}

void BaseDMA::Show() const
{
	MyABC::Show();
	std::cout << "Label: " << label_ << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LacksDMA::LacksDMA(int r, const char* c) : MyABC(r)
{
	strncpy(color, c, strlen(c));
	if (strlen(c) < MAX)
	{
		color[strlen(c)] = '\0';
	}
	else 
	{
		color[MAX] = '\0';
	}
	
}

void LacksDMA::Show() const
{
	MyABC::Show();
	std::cout << "Color: " << color << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HasDMA::HasDMA(int r, const char* c) : MyABC(r)
{
	style_ = new char[strlen(c) + 1];
	strncpy(style_, c, strlen(c));
	style_[strlen(c)] = '\0';
}

HasDMA::HasDMA(const HasDMA& h)
{
	style_ = new char[strlen(h.style_) + 1];
	strncpy(style_, h.style_, strlen(h.style_));
	style_[strlen(h.style_)] = '\0';

}

HasDMA::~HasDMA()
{
	delete[] style_;
}

HasDMA& HasDMA::operator=(const HasDMA& h)
{
	if (this == &h) return *this;
	else
	{
		delete[] style_;
		style_ = new char[strlen(h.style_) + 1];
		strncpy(style_, h.style_, strlen(h.style_));
		style_[strlen(h.style_)] = '\0';
		return *this;
	}
}

void HasDMA::Show() const
{
	MyABC::Show();
	std::cout << "Style: " << style_ << std::endl;
}