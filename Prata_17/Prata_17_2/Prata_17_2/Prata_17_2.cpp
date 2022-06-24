#include <iostream>
#include <cstdlib>
#include <fstream>


int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "There is no file to open" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	std::ofstream fout(argv[1]);

	char ch;

	while (std::cin.get(ch) && ch != '\n')
		fout << ch;
	
	std::cin.ignore(100, '\n');

	fout.close();


	return 0;
}
