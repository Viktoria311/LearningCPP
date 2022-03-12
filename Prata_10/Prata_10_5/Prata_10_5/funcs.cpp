#include <iostream>
#include "stack.h"
#include "customer.h"

void welcome()
{
	std::cout << "Welcome to program!" << std::endl;
	std::cout << "A Stack with size 10 has created. Let`s work with it!" << std::endl;
}

void main_loop(Stack& my_stack)
{
	customer deleted_customer("no name");

	double intermediate_sum = 0.0;

	bool want;

	do
	{
		std::cout << "Do you want to add customer to the stack? 1 - yes, 0 - no";
		std::cin >> want;
		if (want)
			my_stack.Push(customer());

		std::cout << "Do you want to delete customer from the stack? 1 - yes, 0 - no";
		if (want)
		{
			my_stack.Pop(deleted_customer);
			intermediate_sum += deleted_customer.GetPayment();
		}

		std::cout << "Do you want this loop again? 1 - yes, 0 - quit";
		std::cin >> want;
	} while (want);
}