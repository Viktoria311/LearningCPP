#include <iostream>
#include <set>
#include <fstream>
#include <cstdlib>
#include <string>


int main()
{
	std::ifstream mat_fin("mat.dat", std::ios::in);
	std::ifstream pat_fin("pat.dat", std::ios::in);
	std::ofstream matnpat_fout("matnpat.dat", std::ios::out);

	if (mat_fin.is_open() && pat_fin.is_open() && matnpat_fout.is_open())
	{
		std::string some_friend;

		std::set<std::string> mat_set;

		std::set<std::string> pat_set;

		std::set<std::string> own_set;

		while (!(mat_fin.eof()))
		{
			getline(mat_fin, some_friend);
			mat_set.insert(some_friend);
		}
		
		std::cout << "Mat`s friends:" << std::endl;
		for (auto it = mat_set.begin(); it != mat_set.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		while (!(pat_fin.eof()))
		{
			getline(pat_fin, some_friend);
			pat_set.insert(some_friend);
		}

		std::cout << "Pat`s friends:" << std::endl;
		for (auto it = pat_set.begin(); it != pat_set.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		own_set = mat_set;

		for (auto it = pat_set.begin(); it != pat_set.end(); ++it)
			own_set.insert(*it);

		for (auto it = own_set.begin(); it != own_set.end(); ++it)
			matnpat_fout << *it << std::endl;

		mat_fin.close();
		pat_fin.close();
		matnpat_fout.close();
	}
	else
	{
		std::cout << "Not all files are opened." << std::endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}
