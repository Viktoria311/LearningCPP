#ifndef MY_LIST_H_
#define MY_LIST_H_

typedef void (*somefunc_t)(int& v);

struct element
{
	int var_;
	element* next_;
	element(int var, element* next = NULL)
	{
		var_ = var;
		next_ = next;
	}
};

class MyList
{
private:
	int count_ = 0;
	element* first_;
	element* last_;

public:
	MyList();
	int Count() const;
	void Add(element* obj_new);
	void AddAfter(int count, element* obj_new);
	bool IsEmpty() const;
	void Do(somefunc_t somefunc);
	void DeleteFirst();
	void DeleteLast();
	void Delete(int count);
	void Swap(int count1, int count2);
	void ShowAll() const;
	void ShowElement(int count) const;

};

#endif
