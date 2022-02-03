#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main()
{
	std::ofstream fout;

	fout.open("my_new_file.txt");

	if (!fout.is_open())  exit(EXIT_FAILURE);

	else {
		std::string my_string;

		std::cout << "Enter a text, 'q' to quit " << std::endl;

		std::string quit = "q";

		while(  getline(std::cin, my_string)   &&   my_string != quit )
		{
			fout << my_string;

			std::cout << "Enter a text, 'q' to quit " << std::endl;
		}

		fout.close();

		std::ifstream fin;

		fin.open("my_new_file.txt");

		if (!fin.is_open())   exit(EXIT_FAILURE);

		else {
			unsigned int count_of_symbols = 0;

			char one_char;

			while (!fin.eof())
			{
				fin.get(one_char);

				++count_of_symbols;
			}
		}
	}

	return 0;
}