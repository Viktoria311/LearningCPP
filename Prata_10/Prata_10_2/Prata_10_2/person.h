#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person
{
	private:
		static const int LIMIT = 25;
		std::string lname;
		char fname[LIMIT];
	public:
		Person();
		Person(const std::string& ln, const char* fn = "Heyyou");
	   ~Person() { }
	   void Show() const;
	   void FormalShow() const;
	   static const int Limit();
};

typedef void (Person::*Show_t)() const;

#endif