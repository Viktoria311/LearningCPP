#include <iostream>
#include <string>
#include "banc_account.h"
#include "functions.h"

void InitAccount(BancAccount& my_acc)
{
	std::string customer_name;

	std::string customer_account_number;
	
	double customer_balance;

	std::cout << "Enter your name: ";
	getline(std::cin, customer_name);
	std::cout << "Enter your account number: ";
	getline(std::cin, customer_account_number);
	std::cout << "How many money do you have on your card? ";
	while (!(std::cin >> customer_balance))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter your balance: ";
	}
	 my_acc = BancAccount(customer_name, customer_account_number,  customer_balance);
}

double EnterSum()
{
	double sum;

	while (!(std::cin >> sum))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter the sum: ";
	}
	return sum;
}

void OfferToWithdrawMoney(BancAccount& my_acc)
{
	//this function offers to withdraw money
	bool want_withdraw;

	std::cout << "Do you want to withdraw money? 1 - yes, 0 - no" << std::endl;
	std::cin >> want_withdraw;
	std::cin.ignore(100, '\n');
	do
	{
		if (  my_acc.IsEmpty()  )
		{
			std::cout << "Sorry, but your account is empty" << std::endl;
			break;
		}
		if (want_withdraw)
		{
			std::cout << "Enter a sum which you want to withdraw: ";
			double sum_to_withdraw = EnterSum();
			if (my_acc.IsEmpty())
			{
				std::cout << "Sorry, but your account is empty" << std::endl;
				break;
			}
			else if (my_acc.CanWithdrawMoney(sum_to_withdraw))
			{
				my_acc.WithdrawMoney(sum_to_withdraw);
				my_acc.ShowBalance();
			}
			else
			{
				std::cout << "Sorry, but your account has insufficient funds. Try to withdray lesser amount" << std::endl;
				my_acc.ShowBalance();
			}

			std::cout << "Do you want to withdraw money again? 1 - yes, 0 - no" << std::endl;
			std::cin >> want_withdraw;
		}
	} while (  !(my_acc.IsEmpty() ) && want_withdraw);

}

void OfferToPutMoney(BancAccount& my_acc)
{
	//this function offers to put  money
	bool want_put_money;

	std::cout << "Do you want to put money? 1 - yes, 0 - no" << std::endl;
	std::cin >> want_put_money;
	std::cin.ignore(100, '\n');
	do
	{
		std::cout << "Enter a sum which you want to put: ";
		double sum_to_put = EnterSum();
		my_acc.PutMoney(sum_to_put);
		my_acc.ShowBalance();
		std::cout << "Do you want to put money again? 1 - yes, 0 - no" << std::endl;
		std::cin >> want_put_money;
	} while (want_put_money);
}