#include <iostream>
#include <string>

void strcout(const std::string str);

int main()
{
	std::string  input;
	std::cout << "Enter a line:" << std::endl;
	while (getline(std::cin, input) && input.compare("") != 0)
	{
		strcout(input);
		std::cout << "Enter next line (empty line to quit):" << std::endl;
	}
	std::cout << "Bye!" << std::endl;
	return 0;
}
void strcout(const std::string str)
{
	static int total = 0;
	int count = str.length();
	total += count;
    std::cout << count << " characters" << std::endl;
	std::cout << total << " characters total" << std::endl;
}