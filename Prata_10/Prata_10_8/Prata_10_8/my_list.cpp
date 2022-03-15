#include <iostream>
#include "my_list.h"

MyList::MyList()
{
	count_ = 0;
	first_ = last_= nullptr;
}

MyList::~MyList()
{
	if (count_ != 0)
	{
		element* tail_of_list = first_->next_;
		while (tail_of_list != nullptr)
		{
			delete first_;
			first_ = tail_of_list;
			tail_of_list = first_->next_;
		}
		delete first_;
	}
}

int MyList::Count() const
{
	return count_;
}

void MyList::Add(int value)
{
	element* x = new element(value);

	if (count_ != 0)
	{
		last_->next_ = x;
		last_ = x;
	} else first_ = last_ = x; 

	++count_;
} 
void MyList::AddAfter(int count, int value)
{
	if (count > count_)
	{
		std::cout << "there are fewer items in the list. This is why we add this element to the end of list." << std::endl;
		this->Add(value);
	}
	else if (count == count_) this->Add(value);
	else
	{
		element* el = new element(value);

		element* tail_of_list;

		element* x = first_;

		for (int i = 1; i < count; ++i)
			x = x->next_;
		tail_of_list = x->next_;
		x->next_ = el;
		el->next_ = tail_of_list;

		++count_;
	}
}

void MyList::DeleteFirst()
{
	if (this->IsEmpty())
		std::cout << "Sorry the list is empty. There is no elements to delete." << std::endl;
	else
	{
		element* x = first_;

		first_->var_ = (first_->next_)->var_;
		first_ = first_->next_;
		delete x;
		--count_;
	}
}

void MyList::DeleteLast()
{
	if (this->IsEmpty())
		std::cout << "Sorry the list is empty. There is no elements to delete." << std::endl;
	else 
	{
		element* x = first_;

		for (int i = 1; i < count_ - 1; ++i)
			x = x->next_;

		delete x->next_;
		x->next_ = nullptr;
		last_ = x;
		--count_;
	}
	
}
void MyList::Delete(int count)
{
	if (this->IsEmpty())
		std::cout << "Sorry the list is empty." << std::endl;
	else
	{
		if (count > count_) std::cout << "Sorry there isn`t an element from the place " << count << " in this list." << std::endl;
		else if (count == 1) DeleteFirst();
		else if (count == count_) DeleteLast();
		else
		{
			element* x = first_;

			for (int i = 1; i < count - 1; ++i)
				x = x->next_;
			element* tail_of_list = x->next_->next_;
			delete x->next_;
			x->next_ = tail_of_list;
			--count_;
		}
	}
}

bool MyList::IsEmpty() const
{
	return count_ == 0;
}

void MyList::Do(somefunc_t somefunc)
{
	element* x = first_;
	do
	{
		somefunc(x->var_);
		x = x->next_;
	} while (x != NULL);
}

bool MyList::Swap(int count1, int count2)
{
	if (count1 > count_ || count2 > count_)
	{
		std::cout << "Sorry but you entered counts incorrectly." << std::endl;
		return false;
	}
	else
	{
		element* x = first_;
		for (int i = 1; i < count1 - 1; ++i)
			x = x->next_;

		element* y = first_;
		for (int i = 1; i < count2 - 1; ++i)
			y = y->next_;

		int i = x->next_->var_;
		x->next_->var_ = y->next_->var_;
		y->next_->var_ = i;
		return true;
	}
}
void MyList::ShowAll() const
{
	if (this->IsEmpty())
		std::cout << "Sorry the list is empty." << std::endl;
	else
	{
		element* x = first_;

		for (int i = 1; i < count_; ++i)
		{
			std::cout << i << " element: " << x->var_ << std::endl;
			x = x->next_;
		}
		std::cout << count_ << " element: " << x->var_ << std::endl;
	}
}

void MyList::ShowElement(int count) const
{
	element* x = first_;
	for (int i = 1; i < count; ++i)
		x = x->next_;
	std::cout << count << " element: " << x->var_ << std::endl;
}