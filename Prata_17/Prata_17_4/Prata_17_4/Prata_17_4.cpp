#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

int main()
{
	std::ifstream fin1("file1.txt", std::ios::in);
	std::ifstream fin2("file2.txt", std::ios::in);
	std::ofstream fout("file3.txt", std::ios::out | std::ios::app);


	if (fin1.is_open() && fin2.is_open() && fout.is_open())
	{
		std::string some_string;

		while (!(fin1.eof()) || !(fin2.eof()))
		{
			if (!fin1.eof())
			{
				getline(fin1, some_string);
				fout << some_string << " ";
			}

			if (!fin2.eof())
			{
				getline(fin2, some_string);
				fout << some_string;
			}
			fout << std::endl;
		}

		fin1.close();
		fin2.close();
		fout.close();
	}
	else
	{
		std::cout << "Not all files are opened. Exit program" << std::endl;
		exit(EXIT_FAILURE);
	}


	return 0;
}
