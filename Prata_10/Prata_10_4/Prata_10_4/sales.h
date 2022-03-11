#ifndef SALES_H_
#define SALES_H_

#include <array>
#include <vector>

namespace SALES
{
	const int QUARTERS = 4;
	class Sales
	{
	private:
		std::array<double, QUARTERS> sales;
		double average;
		double max;
		double min;
	public:
		Sales(std::vector<double>& vec);
		Sales();
	   ~Sales();
	    void ShowSales() const;
		void ShowAverage() const;
		void ShowMax() const;
		void ShowMin() const;
		void Show() const;

	};
}

#endif