#ifndef MY_CLASSES_
#define MY_CLASSES_

#include <string>
#include <valarray>
#include "my_templates.h"

class Cool_Pair : public Pair<std::valarray<int>, std::valarray<int>>
{
public:
	Cool_Pair(int q, const int* years, const int* bottles) : Pair(q, years, bottles) { }
	Cool_Pair(int q = 0) : Pair(q) { }
	int size() const;
	void GetBottles();
	int sum() const;
	int years(int i) const;
	int bottles(int i) const;
	void Show() const;
};

class Wine
{
private:
	std::string name_;
	Cool_Pair p_;
public:
	Wine(const std::string& name, int q, const int* y, const int* b);
	Wine(const std::string& name, int q);
	~Wine() { }
	void GetBottles();
	const std::string& Label() const;
	int sum() const;
	void Show() const;
};

#endif