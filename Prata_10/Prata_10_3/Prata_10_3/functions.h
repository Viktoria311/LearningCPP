#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <vector>
#include "golf.h"


bool HaveName(const Golf& g);
Golf Func(int size);
void AddGolf(std::vector<Golf>& my_vec);
void Show(const std::vector<Golf>& my_vec);

#endif