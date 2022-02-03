#include <iostream>
#include <string>
#include <cctype>

void changeToUpper(std::string& str);

int main()
{
	bool again;
	std::string my_string;
	bool wantToUpper;

	do
	{
		std::cout << "Enter your string: ";
		getline(std::cin, my_string);

		std::cout << "Do you want to upper case of your string? 1 - yes, 0 - no\n";
		std::cin >> wantToUpper;
		if (wantToUpper)
		{
			changeToUpper(my_string);
			std::cout << "Your string: " << my_string << std::endl;
		}

		while (std::cin.get() != '\n') continue;

		std::cout << "Do you want to enter another string and repeat this loop? 1 - yes, 0 - no\n";
		std::cin >> again;
		while (std::cin.get() != '\n') continue;

	} while (again);
	std::cout << "Bye!\n";

	return 0;
}

void changeToUpper(std::string& str)
{
	for (std::string::iterator i = str.begin(); i != str.end(); ++i)
		*i = toupper(*i);
}
