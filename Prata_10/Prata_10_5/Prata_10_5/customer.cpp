#include <iostream>
#include <string>
#include <cstring>
#include "customer.h"

extern const int LIMIT;

customer::customer()
{
	std::cout << "Enter customer`s fullname: ";
	std::cin.getline(fullname, LIMIT);
	std::cout << "Enter customer`s payment: ";
	while (!(std::cin >> payment))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try to enter payment again: ";
	}
}

customer::customer(const std::string& name, double payment_)
{
	strcpy_s(fullname, LIMIT, name.c_str());
	payment = payment_;
}

customer::customer(const customer& m)
{
	strcpy_s(fullname, LIMIT, m.fullname);
	payment = m.payment;
}

void customer::operator=(const customer& m)
{
	if (&m != this)
	{
		strcpy_s(fullname, LIMIT, m.fullname);
		payment = m.payment;
	}
}
double customer::GetPayment() const
{
	return payment;
}