#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	if (argc == 1 || argc == 2)
	{
		std::cout << "There aren`t enought arguments" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::ifstream fin(argv[1]);
	std::ofstream fout(argv[2]);

	if (!fin.is_open() || !fout.is_open())
	{
		std::cout << "Not all files are open. Bye";
		exit(EXIT_FAILURE);
	}

	char ch;

	while (fin.get(ch) && ch != '\n')
		fout << ch;

	std::cout << "The end of file. Bye" << std::endl;

	fin.close();
	fout.close();

	return 0;
}
