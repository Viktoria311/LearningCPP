#ifndef BANC_ACCOUNT_H
#define BANC_ACCOUNT_H

#include <string>

class BancAccount
{
	private:
		std::string name_;
		std::string account_number_;
		double balance_;
	public:
		BancAccount(const std::string& name = "Customer", const std::string& account_number = "0000 0000 0000 0000", double balance = 0.0);
	   ~BancAccount();
	    void WithdrawMoney(double sum);
		void PutMoney(double sum);
		void ShowBancAccount() const;
		void ShowBalance() const;
		bool IsEmpty() const;
		bool CanWithdrawMoney(double sum);
};

#endif
