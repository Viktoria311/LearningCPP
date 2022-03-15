#ifndef FUNCS_H_
#define FUNCS_H_

#include <iostream>
#include "my_list.h"

int EnterNumber();
int EnterCount();
void DoubleTheSize(int& var);
void IncreaceByTen(int& var);
void ReduceByThree(int& var);
void AddingFunc(MyList& first_list);
void AddingLoop(MyList& my_list);
void DelettingFunc(MyList& first_list);
void DelettingLoop(MyList& first_list);
void Change(MyList& first_list, somefunc_t somefunc);
void ChangingFunc(MyList& first_list);
void ChangingLoop(MyList& first_list);
void SwapingLoop(MyList& first_list);

#endif