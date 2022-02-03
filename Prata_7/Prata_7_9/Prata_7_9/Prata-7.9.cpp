#include <iostream>

const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], const int n);
void display1(const student st);
void display2(const student* ps);
void display3(const student pa[], int n);
void display4(const student pa[], int n, void(*func)(const student* ps));

int main()
{
	int class_size;

	std::cout << "Enter class size: ";

	while (  !(std::cin >> class_size) )
	{
		std::cin.clear();

		std::cin.ignore(100, '\n');
	}
	student* ptr_stu = new student[class_size];

	int entered = getinfo(ptr_stu, class_size);

	for (int i = 0; i < entered; ++i)
	{
		display1(ptr_stu[i]);

		display2(&ptr_stu[i]);
	}

	display3(ptr_stu, entered);

	display4(ptr_stu, entered, display2);

	delete[] ptr_stu;

	std::cout << "Done\n";

	return 0;
}
int getinfo(student pa[], const int n)
{
	int i = 0;
	std::cout << "Enter a fullname of the first student: ";
	while (i < n  &&  std::cin.getline((pa + i)->fullname, SLEN) && (pa + i)->fullname[0] != '\n' )
	{
		std::cin.ignore(100, '\n');
		std::cout << "Enter " << (pa + i)->fullname << "`s hobby: ";
		while (!(std::cin.getline(  (pa + i)->hobby, SLEN)  )  )
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Error input. Enter again: ";
		}
		std::cout << "Enter " << (pa + i)->fullname << "`s OOP level: ";
		while (  !(std::cin >> (pa + i)->ooplevel )   )
		{
			std::cin.clear();
			std::cin.ignore(30, '\n');
			std::cout << "Error input. Enter again: ";
		}
		++i;
		if (i < n) std::cout << "Enter a fullname of the next student: ";
	}
	std::cin.clear();
	std::cin.ignore(100, '\n');
	return i;
}

void display1(const student st)
{
	std::cout << "fullname: " << st.fullname << std::endl;
	std::cout << "hobby: " << st.hobby << std::endl;
	std::cout << "OOP level: " << st.ooplevel << std::endl;
}

void display2(const student* ps)
{
	std::cout << "fullname: " << ps->fullname << std::endl;
	std::cout << "hobby: " << ps->hobby << std::endl;
	std::cout << "OOP level: " << ps->ooplevel << std::endl;
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << "fullname: " << (pa + i)->fullname << std::endl;
		std::cout << "hobby: " << (pa + i)->hobby << std::endl;
		std::cout << "OOP level: " << (pa + i)->ooplevel << std::endl;
	}
	std::cout << "A function  display3 ended its work." << std::endl;
}

void display4(const student pa[], int n,  void(*func)(const student* ps)   )
{
	for (int i = 0; i < n; ++i)
	{
		func((pa + i));
	}
	std::cout << "A function  display4 ended its work." << std::endl;
}