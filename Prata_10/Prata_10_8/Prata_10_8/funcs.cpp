#include <iostream>
#include "my_list.h"

int EnterNumber()
{
	int n;

	while (!(std::cin >> n))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Please try to enter again: ";
	}
	return n;
}

int EnterElement()
{
	std::cout << "Enter your element: ";
	return EnterNumber();
}

int EnterCount()
{
	int num;
	std::cout << "Enter a number of element: ";
	do
	{
		num = EnterNumber();
		if (num <= 0)
		{
			std::cout << "A number of element can`t be zero or less than zero." << std::endl;
			std::cout << "Try again to enter a number of element: ";
		}
	} while (num <= 0);
	
	return num;
}

void DoubleTheSize(int& var)
{
	var *= 2;
}

void IncreaceByTen(int& var)
{
	var += 10;
}

void ReduceByThree(int& var)
{
	var -= 3;
}

void AddingFunc(MyList& first_list)
{
	bool want;

	std::cout << "Do you want to add your element after a specific element? 1 - yes, 0- no  ";
	std::cin >> want;
	std::cin.ignore(100, '\n');
	if (want) first_list.AddAfter(EnterCount(), EnterElement());
	else first_list.Add(EnterElement());
}

void AddingLoop(MyList& first_list)
{
	bool want;
	//first add
	std::cout << "Let`s add some element to your list!" << std::endl;
	first_list.Add(EnterNumber());
	first_list.ShowAll();
	//other loop
	do
	{
		std::cout << "Do you want to add one more element to your list? 1 - yes, 0- no  ";
		std::cin >> want;
		std::cin.ignore(100, '\n');
		if (want) AddingFunc(first_list);
		
	} while (want);
}
void DelettingFunc(MyList& first_list)
{
	bool want;

	std::cout << "Do you want to to delete element of specific position? 1 - yes, 0 - no  ";
	std::cin >> want;
	std::cin.ignore(100, '\n');
	if (want) first_list.Delete(EnterCount());
	else
	{
		std::cout << "What element do you want to delete? 1 - first, 0 - last  ";
		std::cin >> want;
		std::cin.ignore(100, '\n');
		if (want) first_list.DeleteFirst();
		else first_list.DeleteLast();
	}
}
void DelettingLoop(MyList& first_list)
{
	bool want;

	do
	{
		std::cout << "Do you want to delete some element from your list? 1 - yes, 0 - no  ";
		std::cin >> want;
		std::cin.ignore(100, '\n');
		if (want) DelettingFunc(first_list);
	} while (want);
}
void Change(MyList& first_list, somefunc_t somefunc)
{
	bool want;

	std::cin >> want;
	std::cin.ignore(100, '\n');
	if (want)
	{
		first_list.Do(somefunc);
		first_list.ShowAll();
	}
}
void ChangingFunc(MyList& first_list)
{
	std::cout << "Do you want to double all elements from your list? 1 - yes, 0 - no  ";
	Change(first_list, DoubleTheSize);

	std::cout << "Do you want to increace by 10 every element from your list? 1 - yes, 0 - no  ";
	Change(first_list, IncreaceByTen);

	std::cout << "Do you want to reduce by 3 every element from your list? 1 - yes, 0 - no  ";
	Change(first_list, ReduceByThree);
}
void ChangingLoop(MyList& first_list)
{
	bool want;

	do
	{
		ChangingFunc(first_list);
		first_list.ShowAll();
		std::cout << "Do you want to change elements from your list one more round? 1 - yes, 0 - no  ";
		std::cin >> want;
		std::cin.ignore(100, '\n');
	} while (want);
}

void SwapingLoop(MyList& first_list)
{
	bool want;

	do
	{
		std::cout << "Do you want to swap 2 elements? 1 - yes, 0 - no  ";
		std::cin >> want;
		std::cin.ignore(100, '\n');
		if (want)
		{
			if (first_list.Count() <= 1) std::cout << "You can`t swap." << std::endl;
			else
			{
				std::cout << "There are " << first_list.Count() << " elements in this list." << std::endl;
				std::cout << "Enter counts of elements which you want to swap." << std::endl;
				int a = EnterCount();
				int b = EnterCount();
				std::cout << "Before swap:" << std::endl;
				first_list.ShowAll();
				while (!(first_list.Swap(a, b)));
				std::cout << "After swap:" << std::endl;
				first_list.ShowAll();
			}
			
		}
	} while(want);
	
}