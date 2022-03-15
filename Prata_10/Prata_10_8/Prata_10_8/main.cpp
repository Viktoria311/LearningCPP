#include <iostream>
#include "my_list.h"
#include "funcs.h"


int main()
{
	MyList first_list;

	AddingLoop(first_list);
	DelettingLoop(first_list);
	ChangingLoop(first_list);
	SwapingLoop(first_list);
	
	std::cout << std::endl << "Bye!";

	return 0;
}