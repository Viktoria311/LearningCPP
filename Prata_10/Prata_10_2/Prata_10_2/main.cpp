#include <iostream>
#include <vector>
#include "functions.h"
#include "person.h"

int main()
{
	char* first_name = new char[Person::Limit()];

	std::string last_name;

	std::vector<Person> people(3);

	EnterFirstName(first_name, Person::Limit());
	EnterLastName(last_name);
	people[0] = Person(const_cast<const std::string&>(last_name), const_cast<const char*>(first_name));
	EnterLastName(last_name);
	people[1] = Person(last_name);
	people[2] = Person();

	Show(people, &Person::Show, &Person::FormalShow);

	delete[] first_name;

	return 0;
}