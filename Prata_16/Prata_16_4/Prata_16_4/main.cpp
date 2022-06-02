#include <iostream>
#include <algorithm>
#include <iterator>

int reduce(long ar[], int n)
{
	std::sort(ar, ar + n);

	auto element_end = std::unique(ar, ar + n);

	int unique_count = 0;

	for (decltype(element_end) i = ar; i != element_end; ++i)
	{
		++unique_count;
	}
	
	return unique_count;
}

int main()
{
	long my_array[] = { 122, 284, 34, 4354,563, 32, 33, 455, 284, 4354 };

	unsigned int array_size = sizeof(my_array) / sizeof(long);

	std::cout << "Look at the array:" << std::endl;

	std::ostream_iterator<long, char> my_out(std::cout, " ");

	std::copy(my_array, my_array + array_size, my_out);
	
	int unique_elements_quantity = reduce(my_array, array_size);

	std::cout << std::endl << "There are " << unique_elements_quantity << " unique element in the array. Look at them: " << std::endl;

	std::copy(my_array, my_array + unique_elements_quantity, my_out);

	return 0;
}