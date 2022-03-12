#include <iostream>
#include <array>
#include <vector>
#include "sales.h"

namespace SALES
{
	void Sales::SetSales(const std::vector<double>& vec)
	{
		if (vec.empty())
		{
			for (int i = 0; i < QUARTERS; ++i)
				sales[i] = 0.0;
		} else
		{
			for (int i = 0; i < QUARTERS && i < vec.size(); ++i)
				sales[i] = vec[i];

			if (vec.size() < QUARTERS)
				for (int i = vec.size(); i < QUARTERS; ++i)
					sales[i] = 0.0;
		}
	}

	void Sales::SetSales()
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
	}

	void Sales::SetMaxMin(const std::vector<double>& vec)
	{
		if (vec.empty()) max = min = 0.0;
		else
		{
			min = vec[0];

			max = vec[0];

			for (int i = 1; i < vec.size(); ++i)
			{
				if (max < vec[i]) max = vec[i];
				if (min > vec[i]) min = vec[i];
			}
		}
	}

	void Sales::SetMaxMin(const std::array<double, QUARTERS>& arr)
	{
		min = sales[0];

		max = sales[0];

		for (int i = 1; i < sales.size(); ++i)
		{
			if (min > sales[i]) min = sales[i];
			if (max < sales[i]) max = sales[i];
		}
	}
	void Sales::SumAverage(const std::vector<double>& vec)
	{

		average = 0.0;

		if (!vec.empty())
		{
			for (int i = 0; i < vec.size(); ++i)
				average += vec[i];
			average /= vec.size();
		}
	}
	void Sales::SumAverage(const std::array<double, QUARTERS>& arr)
	{
		average = 0.0;

		for (int i = 0; i < arr.size(); ++i)
				average += arr[i];
		average /= arr.size();
	
	}
	Sales::Sales(const std::vector<double>& vec)
	{
		SetSales(vec);
		SetMaxMin(vec);
		SumAverage(vec);
	}

	Sales::Sales()
	{
		SetSales();
		SetMaxMin(sales);
		SumAverage(sales);
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