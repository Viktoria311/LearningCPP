#include <iostream>
#include <cmath>
#include "my_funcs.h"
#include "my_exept.h"

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a,b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
