#include <iostream>
#include "my_stack.h"

MyStack::MyStack(int n)
{
	if (n > 10)
	{
		std::cout << "More than 10" << std::endl;
		pitems = new unsigned long[MAX];
		size = MAX;
	}
	else if (n <= 0)
	{
		std::cout << "Less than 1 element" << std::endl;
		pitems = new unsigned long[MAX];
		size = MAX;
	}
	else pitems = new unsigned long[n];

	size = n;
	top = -1;
}

MyStack::MyStack(const MyStack& st)
{
	pitems = new unsigned long[st.size];

	for (int i = 0; i <= st.top; ++i)
		pitems[i] = st.pitems[i];
	size = st.size;
	top = st.top;
}

MyStack::~MyStack()
{
	delete[] pitems;
}

bool MyStack::isempty() const
{
	return top == -1;
}

bool MyStack::isfull() const
{
	return top == size - 1;
}

void MyStack::show() const
{
	if (this->isempty()) std::cout << "Stack is empty " << std::endl;
	else
	{
		if (this->isfull())  std::cout << "Stack is full" << std::endl;
		for (int i = 0; i <= top; ++i)
			std::cout << i + 1 << " element: " << pitems[i] << std::endl;
	}
		
}

bool MyStack::push(const unsigned long& item)
{
	if (this->isfull()) return false;
	else
	{
		pitems[++top] = item;
		return true;
	}
}

bool MyStack::pop(unsigned long& item)
{
	if (this->isempty()) return false;
	else
	{
		item = pitems[top--];
		return true;
	}
}

MyStack& MyStack::operator=(const MyStack& st)
{
	if (this == &st) return *this;
	else
	{
		delete[] pitems;
		pitems = new unsigned long[st.size];
		for (int i = 0; i <= st.top; ++i)
			pitems[i] = st.pitems[i];
		size = st.size;
		top = st.top;

		return *this;
	}
}