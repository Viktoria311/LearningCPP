#include <iostream>
#include "stack.h"
#include "customer.h"

extern const int LIMIT;

Stack::Stack()
{
	top = 0;
}

bool Stack::IsEmpty() const
{
	return top == 0;
}

bool Stack::IsFull() const
{
	return top == MAX;
}

bool Stack::Push(const customer& item)
{
	if (this->IsFull()) return false;
	else
	{
		items[top] = item;
		++top;
		return true;
	}
}

bool Stack::Pop(customer& item)
{
	if (this->IsEmpty()) return false;
	else
	{
		item = items[--top];
		return true;
	}
}