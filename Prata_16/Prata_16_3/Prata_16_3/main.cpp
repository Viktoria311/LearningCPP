#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>


int main()
{
	std::ifstream fin;
	fin.open("my_file.txt");

	if (!fin.is_open())
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		std::vector<std::string> wordlist;

		std::copy(std::istream_iterator<std::string, char>(fin), std::istream_iterator<std::string, char>(), wordlist.begin());

		if (!wordlist.size())
		{
			std::cout << "There aren`t words in file" << std::endl;
		}
		else
		{
			std::ostream_iterator<std::string, char> out_iter(std::cout, " ");

			std::cout << "Look at words from the file: " << std::endl;
			std::copy(wordlist.begin(), wordlist.end(), out_iter);
		}
		
		fin.close();
	}

	return 0;
}