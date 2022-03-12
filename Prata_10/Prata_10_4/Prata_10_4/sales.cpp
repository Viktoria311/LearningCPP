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
			double min_ = vec[0];

			double max_ = vec[0];

			double average_ = vec[0];
			
			for (int i = 0; i < vec.size(); ++i)
			{
				sales[i] = vec[i];
				average_ += vec[i];
				if (max_ < vec[i]) max_ = vec[i];
				if (min_ > vec[i]) min_ = vec[i];
			}
			min = min_;
			max = max_;
			average = average_ / sales.size();
		} else if (vec.empty())
		{
			max = min = average = sales[3] = sales[2] = sales[1] = sales[0] = 0.0;
		} else
		{
			for (int i = 0; i < QUARTERS && i < vec.size(); ++i)
				sales[i] = vec[i];

			if (vec.size() < QUARTERS)
				for (int i = vec.size(); i < QUARTERS; ++i)
					sales[i] = 0.0;

			double min_ = vec[0];

			double max_ = vec[0];

			double average_ = vec[0];

			for (int i = 1; i < vec.size(); ++i)
			{
				average += vec.at(i);
				if (max_ < vec[i]) max_ = vec[i];
				if (min_ > vec[i]) min_ = vec[i];
			}
			min = min_;
			max = max_;
			average = average_ / sales.size();
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
		double min_ = sales[0];

		double max_ = sales[0];

		double average_ = sales[0];

		for (int i = 1; i < sales.size(); ++i)
		{
			if (min > sales[i]) min_ = sales[i];
			if (max < sales[i]) max_ = sales[i];
			average_ += sales[i];
		}
		min = min_;
		max = max_;
		average = average_ / sales.size();
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