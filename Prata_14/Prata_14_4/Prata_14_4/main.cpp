#include <iostream>
#include <string>
#include "my_classes.h"
#include "funcs.h"

const int size_of_arr = 4;

int main()
{
	Person* arr[size_of_arr];

	int identity;

	for (int i = 0; i < size_of_arr; ++i)
	{
		EnterIdentyfire(identity);

		bool want;
		std::string name;
		std::string surname;

		WantEnterFullName(want);
		
		if (want)
		{
			std::cout << "Enter a name: ";
			getline(std::cin, name);
			std::cout << "Enter a surname: ";
			getline(std::cin, surname);
		}


		switch (identity)
		{
			case 1:
			{
				std::cout << "creating PERSON" << std::endl;
				if (want) arr[i] = new Person(name, surname);
				else arr[i] = new Person();
				break;
			}
			case 3:
			{
				std::cout << "creating POCKER PLAYER" << std::endl;
				if (want) arr[i] = new PockerPlayer(name, surname);
				else arr[i] = new Person();
				break;
			}
			case 2:
			case 4:
			{
				if (want)
				{
					bool want_full_gunslinger;
					std::cout << "Do you want to enter prepare time and rifle notches? 1 - yes, 0 - no : ";
					std::cin >> want_full_gunslinger;

					if (want_full_gunslinger)
					{
						double tt;

						int notches;

						EnterTimeAndNotches(tt, notches);

						if (identity == 2) { std::cout << "creating GUNSLINGER" << std::endl;          arr[i] = new Gunslinger(name, surname, tt, notches); }
						else { std::cout << "creating BAD DUDE" << std::endl;         arr[i] = new BadDude(name, surname, tt, notches); }
					}

				}
				else
				{
					if (identity == 2) { std::cout << "creating GUNSLINGER" << std::endl;       arr[i] = new Gunslinger(); }
					else { std::cout << "creating BAD DUDE" << std::endl;        arr[i] = new BadDude(); }
				}
				break;
			}
		}
	}

	for (int i = 0; i < size_of_arr; ++i)
	{
		std::cout << "  *   *   *" << std::endl;
		arr[i]->Show();
	}
		

	for (int i = 0; i < size_of_arr; ++i)
		delete arr[i];

	return 0;
}