#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "banc_account.h"


void InitAccount(BancAccount& my_acc);
double EnterSum();
void OfferToWithdrawMoney(BancAccount& my_acc);
void OfferToPutMoney(BancAccount& my_acc);

#endif