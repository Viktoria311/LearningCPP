#include <iostream>
#include "my_string.h"


int main()
{
	MyString s1(" and I am a C++ student.");
	MyString s2 = "Please enter your name: ";
	MyString name;
	std::cout << s2;
	std::cin >> name;
	s2 = "My name is " + name;
	std::cout << s2 << std::endl;
	s2 = s2 + s1;
	s2.StringUp();
	std::cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
		<< " 'A' characters in it.\n";
	s1 = "red";
	MyString rgb[3] = { MyString(s1), MyString("green"), MyString("blue") };
	std::cout << "Enter the name of a primary color for mixing light: ";
	MyString ans;
	bool success = false;
	while (std::cin >> ans)
	{
		ans.StringLow();
		for (int i = 0; i < 3; ++i)
		{
			if (ans == rgb[i])
			{
				std::cout << "That`s right!\n";
				success = true;
				break;
			}
		}
		if (success) break;
		else std::cout << "Try again!\n";
	}
	std::cout << "Bye!" << std::endl;
	return 0;
}