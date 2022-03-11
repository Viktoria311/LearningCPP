#include <iostream>
#include <vector>
#include "sales.h"
#include "funcs.h"

void Show(const std::vector<SALES::Sales>& my_vec_)
{
	for (std::vector<SALES::Sales>::const_iterator i = my_vec_.begin(); i != my_vec_.end(); ++i)
		i->Show();
}