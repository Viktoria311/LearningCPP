#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Port.h"

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strncpy(brand, br, strlen(br));
	brand[strlen(br)] = '\0';

	strncpy(style, st, strlen(st));
	if (strlen(st) >= 20)
		style[20] = '\0';

	bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strncpy(brand, p.brand, strlen(p.brand));
	brand[strlen(p.brand)] = '\0';

	strncpy(style, p.style, strlen(p.style));
	if (strlen(p.style) >= 20)
		style[20] = '\0';

	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;
	else
	{
		delete[] brand;
		brand = new char[strlen(p.brand) + 1];
		strncpy(brand, p.brand, strlen(p.brand));
		brand[strlen(p.brand)] = '\0';

		strncpy(style, p.style, strlen(p.style));
		if (strlen(p.style) >= 20)
			style[20] = '\0';

		bottles = p.bottles;

		return *this;
	}
}

Port& Port::operator+=(int b)
{
	this->bottles += b;
	return *this;
}

Port& Port::operator-=(int b)
{
	this->bottles -= b;
	return *this;
}

void Port::Show() const
{
	std::cout << "Brand: " << this->brand << std::endl;
	std::cout << "Kind: " << this->style << std::endl;
	std::cout << "Bottles: " << this->bottles << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VintagePort::VintagePort() : Port("none", "vintage")
{
	nickname = new char[5];
	strncpy(nickname, "some", 4);
	nickname[4] = '\0';
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strncpy(nickname, nn, strlen(nn));
	nickname[strlen(nn)] = '\0';
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strncpy(nickname, vp.nickname, strlen(vp.nickname));
	nickname[strlen(vp.nickname)] = '\0';
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return *this;
	else
	{
		this->Port::operator=(vp);
		delete[] nickname;
		nickname = new char[strlen(vp.nickname) + 1];
		strncpy(nickname, vp.nickname, strlen(vp.nickname));
		nickname[strlen(vp.nickname)] = '\0';
		year = vp.year;
		return *this;
	}
}

void VintagePort::Show() const
{
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	operator<<(os, (const Port& )vp) << ", " << vp.nickname << ", " << vp.year;
	return os;
}