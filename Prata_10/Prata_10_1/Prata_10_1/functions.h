#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "banc_account.h"

typedef double (*EnterSum_t)();


void InitAccount(BancAccount& my_acc);
double EnterSum();


void OfferToWithdrawMoney(BancAccount& my_acc, Show_t ShowF, EnterSum_t EnterSumF, CanWithdrawMoney_t CanWithdrawNoneyF, WithdrawMoney_t WithdrawMoneyF, IsEmpty_t IsEmptyF);
void OfferToPutMoney(BancAccount& my_acc, Show_t ShowF,EnterSum_t EnterSumF, PutMoney_t PutMoneyF);

#endif