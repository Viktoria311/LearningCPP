#include <iostream>
#include <fstream>
#include <cmath>
#include "vect.h"

const double Rad_to_deg = 45.5 / std::atan(1.0);

void Vect::set_mag()
{
	mag = std::sqrt(x * x + y * y);
}

void Vect::set_ang()
{
	if (x == 0.0 && y == 0.0) ang = 0.0;
	else ang = std::atan2(y, x);
}

void Vect::set_x()
{
	x = mag * std::cos(ang);
}

void Vect::set_y()
{
	y = mag * std::sin(ang);
}

Vect::Vect()
{
	x = y = mag = ang = 0.0;
	mode = RECT;
}

Vect::Vect(double n1, double n2, Mode form)
{
	mode = form;
	if (form == RECT)
	{
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	}
	else if (form == POL)
	{
		mag = n1;
		ang = n2 / Rad_to_deg;
		set_x();
		set_y();
	}
	else
	{
		std::cout << "Incorrect 3rd argument to Vector()";
		std::cout << "vect set to 0" << std::endl;
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
}

void Vect::reset(double n1, double n2, Mode form)
{
	mode = form;
	if (form == RECT)
	{
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	}
	else if (form == POL)
	{
		mag = n1;
		ang = n2 / Rad_to_deg;
		set_x();
		set_y();
	}
	else
	{
		std::cout << "Incorrect 3rd argument to Vector()";
		std::cout << "vect set to 0" << std::endl;
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
}

void Vect::polar_mode()
{
	mode = POL;
}

void Vect::rect_mode()
{
	mode = RECT;
}

Vect Vect::operator+(const Vect& b) const
{
	return Vect(x + b.x, y + b.y);
}

Vect Vect::operator-(const Vect& b) const
{
	return Vect(x - b.x, y - b.y);
}

Vect Vect::operator-() const
{
	return Vect(-x, -y);
}

Vect Vect::operator*(double n) const
{
	return Vect(n * x, n * y);
}

Vect operator*(double n, const Vect& a)
{
	return a * n;
}

std::ostream& operator<<(std::ostream& os, const Vect& v)
{
	if (v.mode == Vect::RECT)
		os << "(x,y) = (" << v.x << ", " << v.y << ")";
	else if (v.mode == Vect::POL)
		os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
	else os << "Vect object mode is invalid";
	return os;
}