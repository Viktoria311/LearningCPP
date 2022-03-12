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
		void SetSales(const std::vector<double>& vec);
		void SetSales();
		void SetMaxMin(const std::vector<double>& vec);
		void SetMaxMin(const std::array<double, QUARTERS>& arr);
		void SumAverage(const std::vector<double>& vec);
		void SumAverage(const std::array<double, QUARTERS>& arr);
	public:
		Sales(const std::vector<double>& vec);
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