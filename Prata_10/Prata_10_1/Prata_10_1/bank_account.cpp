#include <iostream>
#include <string>
#include "banc_account.h"


BancAccount::BancAccount(const std::string& name, const std::string& account_number, double balance)
{
	name_ = name;
	account_number_ = account_number;
	balance_ = balance;
}

BancAccount::~BancAccount()
{

}

void BancAccount::WithdrawMoney(double sum)
{
	balance_ -= sum;
}

void BancAccount::PutMoney(double sum)
{
	balance_ += sum;
}

void BancAccount::ShowBancAccount() const
{
	std::cout << "Customer name: " << name_ << std::endl;
	std::cout << "Account number: " << account_number_ << std::endl;
	std::cout << "Balance: " << balance_ << std::endl;
}

void BancAccount::ShowBalance() const
{
	std::cout << "Balance: " << balance_ << std::endl;
}

bool BancAccount::IsEmpty() const
{
	if (balance_ == 0.0) return true;
	else return false;
}

bool BancAccount::CanWithdrawMoney(double sum)
{
	if (sum <= balance_) return true;
	else return false;
}