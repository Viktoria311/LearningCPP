#include <iostream>
#include <array>
#include <vector>
#include "sales.h"

namespace SALES
{
	Sales::Sales(std::vector<double>& vec)
	{
		if (vec.size() == QUARTERS)
		{
			average = 0.0;

			max = vec.at(0);

			min = vec.at(0);

			for (int i = 0; i < vec.size(); ++i)
			{
				sales[i] = vec[i];
				average += vec[i];
				if (vec.at(i) > max) max = vec.at(i);
				if (vec.at(i) < min) min = vec.at(i);
			}
			average /= vec.size();
		} else 
		{
			for (int i = 0; i < QUARTERS && i < vec.size(); ++i)
				sales[i] = vec[i];

			average = vec.at(0);

			max = vec.at(0);

			min = vec.at(0);

			for (int i = 1; i < vec.size(); ++i)
			{
				average += vec.at(i);
				if (vec.at(i) > max) max = vec.at(i);
				if (vec.at(i) < min) min = vec.at(i);
			}
			average /= vec.size();
		}
	}

	Sales::Sales()
	{
		std::cout << "Enter sales for " << QUARTERS << " quarters:" << std::endl;
		for (int i = 0; i < QUARTERS; ++i)
		{
			while (!(std::cin >> sales[i]))
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Try again to enter sales of " << i + 1 << " quarter: ";
			}
		}
		double min = sales[0];

		double max = sales[0];

		double average = sales[0];

		for (int i = 1; i < sales.size(); ++i)
		{
			if (min > sales[i]) min = sales[i];
			if (max < sales[i]) max = sales[i];
			average += sales[i];
		}

		min = min;
		max = max;
		average = average / sales.size();
	}

	Sales::~Sales(){}

	void Sales::ShowSales() const
	{
		std::cout << "sales: ";
		for (int i = 0; i < sales.size(); ++i)
			std::cout << sales.at(i) << " ";
		std::cout << std::endl;
	}

	void Sales::ShowAverage() const
	{
		std::cout << "average: " << average << std::endl;
	}

	void Sales::ShowMax() const
	{
		std::cout << "max: " << max << std::endl;
	}

	void Sales::ShowMin() const
	{
		std::cout << "min: " << min << std::endl;
	}

	void Sales::Show() const
	{
		this->ShowSales();
		this->ShowAverage();
		this->ShowMax();
		this->ShowMin();
	}
	
}