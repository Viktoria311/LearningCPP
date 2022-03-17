#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

class Stonewt
{
public:
	enum Mode { St, DoublePounds };
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
public:
	Stonewt();
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	~Stonewt() {}
	double ReturnPounds() const;
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& obj);
	Stonewt operator+(const Stonewt& obj) const;
	Stonewt operator-(const Stonewt& obj) const;
	Stonewt operator*(double n) const;
	bool operator>(const Stonewt& obj) const;
	bool operator<(const Stonewt& obj) const;
	bool operator==(const Stonewt& obj) const;
	bool operator!=(const Stonewt& obj) const;
	bool operator>=(const Stonewt& obj) const;
	bool operator<=(const Stonewt& obj) const;
	bool operator>(int st) const;
	bool operator<(int st) const;
	bool operator==(int st) const;
	bool operator!=(int st) const;
	bool operator>=(int st) const;
	bool operator<=(int st) const;
	bool operator>(double p) const;
	bool operator<(double p) const;
	bool operator==(double p) const;
	bool operator!=(double p) const;
	bool operator>=(double p) const;
	bool operator<=(double p) const;
};

#endif