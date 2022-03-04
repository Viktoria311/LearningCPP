#include <iostream>
#include "banc_account.h"
#include "functions.h"


int main()
{
	BancAccount my_account;
	
	InitAccount(my_account);

	my_account.ShowBancAccount();

	//this function offers to withdraw money
	OfferToWithdrawMoney(my_account, &BancAccount::ShowBalance, EnterSum, &BancAccount::CanWithdrawMoney, &BancAccount::WithdrawMoney, &BancAccount::IsEmpty);

	//this function offers to put money
	OfferToPutMoney(my_account, &BancAccount::ShowBalance, EnterSum, &BancAccount::PutMoney);

	return 0;
} 