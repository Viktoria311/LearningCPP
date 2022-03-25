#include <iostream>
#include "my_stack.h"


int main()
{
	MyStack first_stack(5);
	MyStack secomd_stack;
	unsigned long a;
	unsigned long b = 1003;
	unsigned long c = 23433;
	unsigned long d = 43234;
	unsigned long e = 3663;

	first_stack.push(b);
	first_stack.push(c);
	first_stack.push(d);
	first_stack.push(e);
	std::cout << "First tack:" << std::endl;
	first_stack.show();
	std::cout << "Second stack:" << std::endl;
	secomd_stack = first_stack;
	secomd_stack.pop(a);
	secomd_stack.show();

	return 0;
}