#include <iostream>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void func_print(box my_box);
void func_set(box* p_my_box);

int main()
{
	bool again;
	do
	{
		box box1;
		std::cout << "Enter a maker of the box: ";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin.getline(box1.maker, 40);

		std::cout << "Enter a height of the box: ";
		while (!(std::cin >> box1.height)) std::cin.clear();
		std::cin.clear();

		std::cout << "Enter a width of the box: ";
		while (!(std::cin >> box1.width)) std::cin.clear();
		std::cin.clear();

		std::cout << "Enter a length of the box: ";
		while (!(std::cin >> box1.length)) std::cin.clear();
		std::cin.clear();

		std::cout << "Enter a volume of the box: ";
		while (!(std::cin >> box1.volume)) std::cin.clear();
		std::cin.clear();

		func_print(box1);

		std::cout << "Do yo want to set volume as a multiply of 3 another fields of structure? 1 - yes, 0 - no";
		std::cout << std::endl;
		bool set_volume;
		std::cin >> set_volume;
		if (set_volume)
		{
			func_set(&box1);
			func_print(box1);
		}

		std::cout << "Do yo want one more loop? 1 - yes, 0 - no";
		std::cout << std::endl;
		std::cin >> again;
		std::cin.clear();
	} while (again);

	std::cout << "Bye";

	return 0;
}
void func_print(box my_box)
{
	std::cout << "All data of the struct:" << std::endl;
	std::cout << "maker " << my_box.maker << std::endl;
	std::cout << "height " << my_box.height << std::endl;
	std::cout << "width " << my_box.width << std::endl;
	std::cout << "length " << my_box.length << std::endl;
	std::cout << "volume " << my_box.volume << std::endl;
}

void func_set(box* p_my_box)
{
	p_my_box->volume = p_my_box->height * p_my_box->width * p_my_box->length;
}
