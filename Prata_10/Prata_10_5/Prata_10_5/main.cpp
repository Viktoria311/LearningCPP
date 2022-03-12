#include <iostream>
#include "funcs.h"
#include "stack.h"
#include "customer.h"

extern const int LIMIT;

int main()
{
	Stack my_stack;

	welcome();
	main_loop(my_stack);

	return 0;
}