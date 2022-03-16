#include <iostream>
#include "my_time.h"

MyTime::MyTime()
{
	hours = minutes = 0;
}

MyTime::MyTime(int h, int m)
{
	hours = h;
	minutes = m;
}

MyTime::~MyTime()
{

}

void MyTime::AddMin(int m)
{
	minutes += m;
	hours += minutes % 60;
	minutes %= 60;
}
void MyTime::AddHr(int h)
{
	hours += h;
}

void MyTime::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

MyTime operator+(const MyTime& t1, const MyTime& t2)
{
	int m = t1.minutes + t2.minutes;
	int h = m / 60 + t1.hours + t2.hours;
	m %= 60;
	return MyTime(h, m);
}

MyTime operator-(const MyTime& t1, const MyTime& t2)
{
	if (t1.minutes >= t2.minutes) 
		return MyTime(t1.hours - t2.hours, t1.minutes - t2.minutes);
	else 
		return MyTime(t1.hours - t2.hours - 1, 60 + t1.minutes - t2.minutes);
}

MyTime operator*(const MyTime& t, double n)
{
	long int m = t.minutes * n + t.hours * 60 * n;
	int h = m / 60;
	m %= 60;
	return MyTime(h, m);
}

std::ostream& operator<<(std::ostream& os, const MyTime& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}