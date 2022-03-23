#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "my_stock.h"

MyStock::MyStock()
{
	company_ = new char[8];//выделяем память на 1 больше, чес символов
	strncpy(company_, "no name", 7);//копируем все символы
	company_[7] = '\0';// зануляем 
	shares_ = 0;
	share_val_ = 0.0;
	total_val_ = 0.0;
}

MyStock::MyStock(const char* company, long n, double pr)
{
	company_ = new char[strlen(company) + 1];//выделяем память на 1 больше, чес символов
	strncpy(company_, company, strlen(company));//копируем все символы
	company_[strlen(company)] = '\0';// зануляем 

	if (n < 0)
	{
		std::cout << "Number of shares can`t be negative; "
				  << company_ << " shares set to 0." << std::endl;
		shares_ = 0;
	} else shares_ = n;

	share_val_ = pr;
	set_tot();
}

MyStock::~MyStock()
{
	delete[] company_;
}

void MyStock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can`t be negative. "
				  << "Transaction is aborted." << std::endl;
	}
	else
	{
		shares_ += num;
		share_val_ = price;
		set_tot();
	}
}

void MyStock::sell(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can`t be negative. "
			<< "Transaction is aborted." << std::endl;
	}
	else if (num > shares_)
	{
		std::cout << "Number of shares purchased can`t be negative. "
				  << "Transaction is aborted." << std::endl;
	} 
	else
	{
		shares_ -= num;
		share_val_ = price;
		set_tot();
	}
}

void MyStock::update(double price)
{
	share_val_ = price;
	set_tot();
}

void MyStock::show() const
{
	std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::streamsize prec = std::cout.precision(3);
	std::cout << "Company: " << company_
			  << "Shares: " << shares_ << share_val_;
	std::cout << "Share Price: $" << share_val_;
	std::cout.precision(2);
	std::cout << "Total Worth: $" << total_val_ << '\n';
	std::cout.setf(orig, std::ios_base::floatfield);
	std::cout.precision(prec);
}

const MyStock& MyStock::topval(const MyStock& s) const
{
	if (s.total_val_ > total_val_) 
		return s;
	else
		return *this;
}

std::ostream& operator<<(std::ostream& os, const MyStock& st)
{
	std::ios_base::fmtflags orig = os.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::streamsize prec = os.precision(3);
	os << "Company: " << st.company_
		<< "Shares: " << st.shares_ << st.share_val_;
	os << " Share Price: $" << st.share_val_;
	os.precision(2);
	os << " Total Worth: $" << st.total_val_ << '\n';
	os.setf(orig, std::ios_base::floatfield);
	os.precision(prec);

	return os;
}