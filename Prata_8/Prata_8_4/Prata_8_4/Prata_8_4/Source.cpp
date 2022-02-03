#include <iostream>
#include <cstring>
struct stringy
{
	char* str;
	int ct;
 };

void set(stringy& my_struct, const char* p);
void show(const stringy& my_struct, int n = 1);
void show(const char* q, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn`t what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	delete[] beany.str;
	return 0;
}

void set(stringy& my_struct, const char* p)
{
	int size_of_p = strlen(p);
	char* p_str = new char[size_of_p + 1];
	for (int i = 0; i < size_of_p - 1; ++i)   
		p_str[i] = p[i];
	p_str[size_of_p - 1] = '\0';
	my_struct.str = p_str;
	my_struct.ct = size_of_p;
}
void show(const stringy& my_struct, int n )
{
	std::cout << "The string is: ";
	for(int i = 0; i < n; ++i)
		std::cout << my_struct.str << std::endl;
}
void show(const char* q, int n )
{
	std::cout << "I would say the string " << n;

	if (n == 1) std::cout << " time:" << std::endl;
	else std::cout << " times:" << std::endl;

	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < strlen(q); ++i)
			std::cout << q[i];
		std::cout << std::endl;
	}
			
}