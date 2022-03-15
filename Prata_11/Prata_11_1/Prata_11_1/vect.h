#ifndef VECT_H_
#define VECT_H_

#include <iostream>


class Vect
{
public:
	enum Mode { RECT, POL };
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vect();
		Vect(double n1, double n2, Mode form = RECT);
	   ~Vect(){}
		void reset(double n1, double n2, Mode form = RECT);
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
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