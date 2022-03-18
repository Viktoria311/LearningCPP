#ifndef COW_H_
#define COW_H_

#include <string>

class Cow
{
private:
	std::string name_;
	char* hobby_;
	double weight_;
public:
	Cow();
	Cow(const std::string& name, const char* hobby, double weight);
	Cow(const Cow& c);
   ~Cow();
    void ShowCow() const;
	Cow& operator=(const Cow& c);
};

#endif
