#ifndef STACK_H_
#define STACK_H_

#include "customer.h"

extern const int LIMIT;

class Stack
{
	private:
		static const int MAX = 10;
		customer items[MAX];
		int top;
	public:
		Stack();
	   ~Stack(){}
	   bool IsEmpty() const;
	   bool IsFull() const;
	   bool Push(const customer& item);
	   bool Pop(customer& item);
};

#endif
