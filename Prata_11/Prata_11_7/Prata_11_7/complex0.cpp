#include <iostream>
#include "complex0.h"


Complex0::Complex0(double real_part, double imaginary_part)
{
	real_part_ = real_part;
	imaginary_part_ = imaginary_part;
}

void Complex0::Show() const
{
	std::cout << "(" << real_part_ << "," << imaginary_part_ << "i)";
}

Complex0& Complex0::operator=(const Complex0& obj)
{
	if (*this == obj) return *this;
	else
	{
		this->real_part_ = obj.real_part_;
		this->imaginary_part_ = obj.imaginary_part_;
	}
	return *this;
}

Complex0 Complex0::operator+(const Complex0& obj) const
{
	return Complex0(this->real_part_ + obj.real_part_, this->imaginary_part_ + obj.imaginary_part_);
}

Complex0 Complex0::operator-(const Complex0& obj) const
{
	return Complex0(this->real_part_ - obj.real_part_, this->imaginary_part_ - obj.imaginary_part_);
}

Complex0 Complex0::operator*(const Complex0& obj) const
{
	return Complex0(this->real_part_ * obj.real_part_, this->imaginary_part_ * obj.imaginary_part_);
}

Complex0 operator*(double n, const Complex0& obj)
{
	return obj.operator*(n);
}

Complex0 Complex0::operator*(double n) const
{
	return Complex0(this->real_part_ * n, this->imaginary_part_ * n);
}

Complex0 Complex0::operator~() const
{
	return Complex0(this->real_part_, this->imaginary_part_ * -1);
}

bool Complex0::operator==(const Complex0& obj) const
{
	return (this->real_part_ == obj.real_part_ && this->imaginary_part_ == obj.imaginary_part_);
}

bool Complex0::operator!=(const Complex0& obj) const
{
	return this->operator==(obj) == false;
}

std::ostream& operator<<(std::ostream& os, const Complex0& obj)
{
	os << "(" << obj.real_part_ << "," << obj.imaginary_part_ << "i)";
	return os;
}

std::istream& operator>>(std::istream& is, Complex0& obj)
{
	double real_part;

	double imaginary_part;

	std::cout << "Enter a real part: ";

	if (!(is >> real_part))
	{
		char z;
		is.clear();
		is >> z;
		if (z == 'q' || z == 'Q')
			return is;
		is.ignore(100, '\n');
		std::cout << "Try to enter a real part again: ";
	}

	std::cout << "Enter an imaginary part ";
	if (!(is >> imaginary_part))
	{
		is.clear();
		is.ignore(100, '\n');
		std::cout << "Try to enter an imaginary part again: ";
	}
	obj = Complex0(real_part, imaginary_part);

	return is;
}