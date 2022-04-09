#ifndef MY_TEMPLATES_H_
#define MY_TEMPLATES_H_

#include "my_classes.h"

template <typename T>
class Queue
{
	private:
		struct Node
		{
			T x;
			Node* next;
		};
		Node* first;
		Node* last;
		int size_of_queue;
		const int max_size;
	public:
		Queue(int size = 10);
		~Queue();
		bool isempty() const;
		bool isfull() const;
		int size() const;
		bool add(const T& z);
		bool delete_element(T& z);
};

template <typename T>
Queue<T>::Queue(int m_size) : max_size(m_size)
{
	first = last = nullptr;
	size_of_queue = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	Node* c;
	while (first != nullptr)
	{
		c = first;
		first = first->next;
		delete c;
	}
}

template <typename T>
bool Queue<T>::isempty() const
{
	return size_of_queue == 0;
}

template <typename T>
bool Queue<T>::isfull() const
{
	return size_of_queue == max_size;
}

template <typename T>
int Queue<T>::size() const
{
	return size_of_queue;
}

template <typename T>
bool Queue<T>::add(const T& z)
{
	if (isfull()) return false;

	Node* d = new Node;
	d->x = z;
	d->next = nullptr;
	if (isempty()) first = d;
	else last->next = d;
	last = d;

	++size_of_queue;

	return true;
}

template <typename T>
bool Queue<T>::delete_element(T& z)
{
	if (isempty()) return false;

	z = first->x;
	--size_of_queue;
	Node* zz = first;
	first = first->next;
	delete zz;
	if (size_of_queue == 0)
		last = nullptr;
	
	return true;
}

#endif