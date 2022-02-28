#include <iostream>
#include "sales.h"

namespace SALES
{
	void setSales(Sales& s, const double* ar, int n)
	{
		double min = ar[0];

		double max = ar[0];

		double average = ar[0];

		s.sales[0] = ar[0];

		for (int i = 1; i < n; ++i)
		{
			s.sales[i] = ar[i];
			if (min > ar[i]) min = ar[i];
			if (max < ar[i]) max = ar[i];
			average += ar[i];
		}

		if (n < QUARTERS)
			for (int i = n; i < QUARTERS; ++i) s.sales[i] = 0;

		s.min = min;
		s.max = max;
		s.average = average / n;
	}

	void setSales(Sales& s)
	{
		std::cout << "Enter sales for " << QUARTERS << " quarters:" << std::endl;
		for (int i = 0; i < QUARTERS; ++i)
		{
			while (!(std::cin >> s.sales[i]))
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Try again to enter sales of " << i + 1 << " quarter: ";
			}
		}
		double min = s.sales[0];

		double max = s.sales[0];

		double average = s.sales[0];

		for (int i = 1; i < QUARTERS; ++i)
		{
			if (min > s.sales[i]) min = s.sales[i];
			if (max < s.sales[i]) max = s.sales[i];
			average += s.sales[i];
		}

		s.min = min;
		s.max = max;
		s.average = average / QUARTERS;
	}

	void showSales(const Sales& s)
	{
		std::cout << std::endl << "sales:" << std::endl;

		for (int i = 0; i < QUARTERS; ++i)
			std::cout << i + 1 << ": " << s.sales[i] << std::endl;

		std::cout << "Min: " << s.min << std::endl;
		std::cout << "Max: " << s.max << std::endl;
		std::cout << "Average: " << s.average << std::endl;
	}
}
