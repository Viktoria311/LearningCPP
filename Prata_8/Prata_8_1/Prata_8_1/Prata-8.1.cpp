#include <iostream>
#include <string>

void my_func(const std::string* st, int n = 0);

int main()
{
	std::string str;
	std::cout << "Enter you string: ";
	getline(std::cin, str);
	bool many_times;
	bool want_again;
	do
	{
		std::cout << "Enter 1 if you want  to see your string as much as the function my_func was called." << std::endl;
		std::cout << "Enret 0 if you want to see you string 1 time." << std::endl;
		std::cin >> many_times;
		std::cin.clear();
		std::cin.ignore(20, '\n');

		if (many_times)  my_func(&str, many_times);
		else  my_func(&str);

		std::cout << "Do you want this loop again? 1 - yes, 0 - no" << std::endl;
		std::cin >> want_again;
		std::cin.clear();
		std::cin.ignore(20, '\n');

	}while(want_again);
	
	return 0;
}

void my_func(const std::string* st, int n)
{
	static int count = 0;
	if ( n == 0)
		std::cout << *st << std::endl;
	else if (n != 0)
	{
		for (int i = 0; i < count; ++i)
			std::cout << *st << std::endl;
	}
	

	++count;
	std::cout << "the function my_func was called " << count << " times in this program." << std::endl;
}