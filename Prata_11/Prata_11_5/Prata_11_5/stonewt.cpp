#include <iostream>
#include "stonewt.h"


Stonewt::Stonewt()
{
	pds_left = pounds = stone = 0;
	mode = Stonewt::St;
}

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int (lbs) % Lbs_per_stn;
	pounds = lbs;
	mode = Stonewt::DoublePounds;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = Stonewt::St;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& obj)
{
	os << obj.stone << " stone, " << obj.pds_left << " pounds";

	return os;
}

Stonewt Stonewt::operator+(const Stonewt& obj) const
{
	double pounds_ = this->pounds + obj.pounds;	

	return Stonewt(pounds_);
}

Stonewt Stonewt::operator-(const Stonewt& obj) const
{
	double pounds_;

	if (this->pounds >= obj.pounds)
		pounds_ = this->pounds - obj.pounds;
	else pounds_ = obj.pounds - this->pounds;

	return Stonewt(pounds_);
}

Stonewt Stonewt::operator*(double n) const
{
	double pounds_ = this->pounds * n;
	return Stonewt(pounds_);
}