#ifndef FUNCS_H_
#define FUNCS_H_

#include <vector>
#include <string>
#include "plorg.h"

std::string EnterName();
void AddObject(std::vector<Plorg>& vec_of_plorgs);
int EnterCI();
void DoYouWantToChangeCI(std::vector<Plorg>& vec_of_plorgs);
void ShowAllObjects(const std::vector<Plorg>& vec_of_plorgs);
void MainLoop(std::vector<Plorg>& vec_of_plorgs);

#endif