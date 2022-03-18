#ifndef FUNCS_H_
#define FUNCS_H_

#include <iostream>
#include <vector>
#include "stonewt.h"

void AddOtherElements(std::vector<Stonewt>& arr, int quantity);

template<typename T>
void EnterValue(T& some);
 
template<typename T>
void ShowResults(const std::vector<Stonewt>& arr, T some);

#include "my_templates.h"

#endif