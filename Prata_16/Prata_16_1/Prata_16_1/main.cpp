#include <iostream>
#include <string>
#include <cstring>

bool is_palindrom(const std::string& s);

int main()
{
	std::string my_string;

	bool want_again;

	do
	{
		std::cout << "Enter asentense or word to find out is your variant palindrom?" << std::endl;
		getline(std::cin, my_string);
		std::cout << "Is your frace a palindrom? " << ( is_palindrom(my_string) ? "yes" : "no") << std::endl;
		std::cout << "Do you want repeat this loop again? enter 1 or 0 : " << std::endl;
		std::cin >> want_again;
		std::cin.ignore(100, '\n');

	} while (want_again);
	

	return 0;
}

bool is_palindrom(const std::string& str)
{

	if (str.length() == 0) return false;
	else
	{
		std::string s = str;


		for (int i = 0; i < s.length(); )
		{
			s[i] = tolower(s[i]);

			if (!isalnum(s[i]) )
				s.erase(i, 1);
			else 
				++i;
		}

		std::string palindrom = s;
		
		for (int i = 0, j = palindrom.length(); i < j; ++i, --j)
			std::swap(palindrom[i], palindrom[j]);

		return s.compare(palindrom) == 0 ? 1 : 0;

		
	}
}