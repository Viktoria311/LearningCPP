#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main()
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// берем все из файла и записываем ввектор
	// закрываем файл fin
	std::vector<std::tm> my_vec;

	std::ifstream fin; // чтобы из файла выводить
	fin.open("pomodoro.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::tm a;
			fin >> a.tm_year;
			fin.get(); // отлов запятой или пробела
			fin >> a.tm_mday;
			fin.get(); // отлов запятой или пробела
			fin >> a.tm_mon;
			fin.get(); // отлов запятой или пробела
			fin >> a.tm_hour;
			fin.get(); // отлов запятой или пробела
			fin >> a.tm_min;
			fin.get(); // отлов символа новой строки
			fin >> a.tm_sec;
			fin.get();
			my_vec.push_back(a);
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			std::cout << "When: " << my_vec[my_vec.size() - 1].tm_mday << " day of " << 1 + my_vec[my_vec.size() - 1].tm_mon << " month." << std::endl
				<< "You was working for " << my_vec[my_vec.size() - 1].tm_hour << " hours " << my_vec[my_vec.size() - 1].tm_min << " minuts " << my_vec[my_vec.size() - 1].tm_sec << " seconds" << std::endl;
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		fin.close();
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// проверка что записалось в вектор
	for (int i = 0; i < my_vec.size(); ++i)
	{
		std::string my_month;
		switch (my_vec[i].tm_mon)
		{
		case 0: my_month = "January"; break;
		case 1: my_month = "Febriary"; break;
		case 2: my_month = "March"; break;
		case 3: my_month = "April"; break;
		case 4: my_month = "May"; break;
		case 5: my_month = "June"; break;
		case 6: my_month = "July";	break;
		case 7: my_month = "August"; break;
		case 8: my_month = "September";	break;
		case 9: my_month = "October"; break;
		case 10: my_month = "November";	break;
		case 11: my_month = "December"; break;
		}
		std::cout << "When: " << my_vec[i].tm_mday << " day of " << 1 + my_vec[i].tm_mon << " month." << std::endl
			<< "You was working for " << my_vec[i].tm_hour << " hours " << my_vec[i].tm_min << " minuts " << my_vec[i].tm_sec << " seconds" << std::endl;
		//std::cout << my_vec[i]->tm_mday << " " << my_month << " " << my_vec[i]->tm_hour << " " << my_vec[i]->tm_min << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// засекаем время таймера в цикле
	bool want_again;

	do
	{
		std::time_t now = time(0);
		std::tm tt;
		std::tm* t = localtime(&now); // инициализируем структуру временем
		tt.tm_year = t->tm_year;
		tt.tm_mon = t->tm_mon;
		tt.tm_mday = t->tm_mday;
		tt.tm_hour = t->tm_hour;
		tt.tm_min = t->tm_min;
		tt.tm_sec = t->tm_sec;
		tt.tm_wday = t->tm_wday;
		tt.tm_yday = t->tm_yday;
		std::cout << "You have just started working! The clock is ticking. " << std::endl;
		int start = clock();
		std::cout << "Push symbol to end a timer" << std::endl;
		// ждем пока пользователь нажмет кнопку
		std::cin.get();
		int end = clock();
		tt.tm_hour = ((end - start) / CLOCKS_PER_SEC) / (60 * 60);
		tt.tm_min = (((end - start) / CLOCKS_PER_SEC) / 60) % 60;
		tt.tm_sec = ((end - start) / CLOCKS_PER_SEC) - tt.tm_min * 60;
		my_vec.push_back(tt);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// сколько сейчас поработал
		std::cout << "TODAY:  " << my_vec[my_vec.size() - 1].tm_mday << " day of " << 1 + my_vec[my_vec.size() - 1].tm_mon << " month." << std::endl
			<< "NOW  you was working for " << my_vec[my_vec.size() - 1].tm_hour << " hours " << my_vec[my_vec.size() - 1].tm_min << " minuts " << my_vec[my_vec.size() - 1].tm_sec << " seconds" << std::endl;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// сколько работал за весь периуд
		for (int i = 0; i < my_vec.size(); ++i)
			std::cout << "When: " << my_vec[i].tm_mday << " day of " << 1 + my_vec[i].tm_mon << " month." << std::endl
			<< "You was working for " << my_vec[i].tm_hour << " hours " << my_vec[i].tm_min << " minuts " << my_vec[i].tm_sec << " seconds" << std::endl;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		std::cout << "Do you want to make working sprint again? 1 - yes, 0 - no : ";
		std::cin >> want_again;
		std::cin.get();

	} while (want_again);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// перед тем как записывать инфу в файл, соединим все спринты одного дня в один
	// НАДО С ИДИОМОЙ   ERASE   REMOVE
	std::cout << " LOOP  TO  ERASE  ELEMENT" << std::endl;

	for (std::vector<std::tm>::iterator i = my_vec.begin(); i != my_vec.end() - 1; )
	{
		if (i->tm_mon == (i + 1)->tm_mon && i->tm_mday == (i + 1)->tm_mday && i->tm_year == (i + 1)->tm_year)
		{

			i->tm_sec += (i + 1)->tm_sec;
			i->tm_min += (i + 1)->tm_min + i->tm_sec / 60;
			i->tm_sec %= 60;
			i->tm_hour += (i + 1)->tm_hour + i->tm_min / 60;
			i->tm_min %= 60;
			my_vec.erase(i + 1);

			////////////////////////////////////////////////////////////
			// показываем весь вектор после удаления элемента
			std::cout << " ERASE  ELEMENT" << std::endl;

			for (int i = 0; i < my_vec.size(); ++i)
				std::cout << my_vec[i].tm_mday << " day of " << 1 + my_vec[i].tm_mon << " month   " << std::endl
				<< my_vec[i].tm_hour << " hours " << my_vec[i].tm_min << " minuts " << my_vec[i].tm_sec << " seconds" << std::endl;
			////////////////////////////////////////////////////////////
		}
		else ++i;

	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// открываем файл для записи вовнутрь fout
	// записываем в файл
	// закрываем файл
	std::ofstream fout; // чтобы в файл вводить
	fout.open("pomodoro.txt");  // метод open() сотрет все содержимое в имеющемся файле
	for (int i = 0; i < my_vec.size(); ++i)
	{
		// выводим в консоль то, что хотим записать в файл
		std::cout << "When: " << my_vec[i].tm_mday << " day of " << 1 + my_vec[i].tm_mon << " month." << std::endl
			<< "You was working for " << my_vec[i].tm_hour << " hours " << my_vec[i].tm_min << " minuts" << std::endl;
		// записываем в файл
		fout << my_vec[i].tm_year << " " << my_vec[i].tm_mday << " " << my_vec[i].tm_mon << " " << my_vec[i].tm_hour << " " << my_vec[i].tm_min << " " << my_vec[i].tm_sec << std::endl;
	}

	fout.close();

	return 0;
}