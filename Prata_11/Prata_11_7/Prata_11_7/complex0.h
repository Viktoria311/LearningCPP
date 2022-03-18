#ifndef COMPLEX0_H_
#define COMPLEX0_H_

class Complex0
{
	private:
		double real_part_;
		double imaginary_part_;
	public:
		Complex0(double real_part = 0.0, double imaginary_part = 0.0);
	   ~Complex0(){}
	    void Show() const;
		Complex0 operator=(const Complex0& obj);
		Complex0 operator+(const Complex0& obj) const;
		Complex0 operator-(const Complex0& obj) const;
		Complex0 operator*(const Complex0& obj) const;
		friend Complex0 operator*(double n, const Complex0& obj);
		Complex0 operator*(double n) const;
		Complex0 operator~() const;
		bool operator==(const Complex0& obj) const;
		bool operator!=(const Complex0& obj) const;
		friend std::ostream&  operator<<(std::ostream& os, const Complex0& obj);
		friend std::istream&  operator>>(std::istream& is, Complex0& obj);
};

#endif
