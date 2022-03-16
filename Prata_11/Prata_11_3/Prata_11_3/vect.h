#ifndef VECT_H_
#define VECT_H_

#include <iostream>
#include <cstdlib>

class Vect
{
public:
	enum Mode { RECT, POL };
private:
	double x;
	double y;
	Mode mode;
public:
	Vect();
	Vect(double n1, double n2, Mode form = RECT);
	~Vect() {}
	void reset(double n1, double n2, Mode form = RECT);
	double xval() const { return x; }
	double yval() const { return y; }
	double magval() const
	{
		return std::sqrt(x * x + y * y);
	}
	double angval() const
	{
		if (x == 0.0 && y == 0.0) return 0.0;
		else return std::atan2(y, x);
	}
	void polar_mode();
	void rect_mode();
	Vect operator+(const Vect& b) const;
	Vect operator-(const Vect& b) const;
	Vect operator-() const;
	Vect operator*(double n) const;
	friend Vect operator*(double n, const Vect& a);
	friend std::ostream& operator<<(std::ostream& os, const Vect& v);
};


#endif