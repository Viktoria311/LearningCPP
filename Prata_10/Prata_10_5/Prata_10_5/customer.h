#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

const int LIMIT = 35;

struct customer
{
	char fullname[LIMIT];
	double payment;
	customer();
	customer(const std::string& name, double payment = 0.0);
	customer(const customer& m);
	void operator=(const customer& m);
	double GetPayment() const;
};

#endif
