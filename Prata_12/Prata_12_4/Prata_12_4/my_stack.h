#ifndef MY_STACK_H_
#define MY_STACK_H_


class MyStack
{
	private:
		enum { MAX = 10};
		unsigned long* pitems;
		int size; //количество выделенных €чеек пам€ти
		int top; //индекс вершины стека
	public:
		MyStack(int n = 10);
		MyStack(const MyStack& st);
	   ~MyStack();
		bool isempty() const;
		bool isfull() const;
		void show() const;
		bool push(const unsigned long& item);
		bool pop(unsigned long& item);
		MyStack& operator=(const MyStack& st);

};

#endif