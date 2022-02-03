#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

struct Patron
{
	std::string name;
	double sum;
};

int main()
{
	//читаем из файла
	std::ifstream fin;

	fin.open("patrons.txt");

	if ( !fin.is_open() ) exit(EXIT_FAILURE);

	unsigned int count;

	fin >> count;

	Patron * arr = new Patron[count];

	for (int i = 0; i < count; ++i)
	{
		getline(fin, (arr + i)->name);
		fin >> (arr + i)->sum;
	}

	fin.close();

	//отображение гранд и остальных

	unsigned int count_of_grand = 0;

	std::cout << "Grand Patrons"  << std::endl;

	for(int i = 0; i < count; ++i)
	{
		if (  (arr + i)->sum  >=  10000   )
		{
			++count_of_grand;
			std::cout << (arr + i)->name;
		}
	}

	if (count_of_grand == 0) std::cout << "none" << std::endl;

	std::cout << "Patrons" << std::endl;

	if (count == count_of_grand) std::cout << "none" << std::endl;

	else {

		for (int i = 0; i < count; ++i)
		
			if (  (arr + i)->sum  <  10000  )      std::cout << (arr + i)->name;
			
	}

	delete[] arr;

	return 0;
}
