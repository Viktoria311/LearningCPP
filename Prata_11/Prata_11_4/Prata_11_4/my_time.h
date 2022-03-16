#ifndef MY_TIME_H
#define MY_TIME_H

class MyTime
{
	private:
		int hours;
		int minutes;
	public:
		MyTime();
		MyTime(int h, int m = 0);
	   ~MyTime();
	    void AddMin(int m);
	    void AddHr(int h);
		void Reset(int h = 0, int m = 0);
		friend MyTime operator+(const MyTime& t1, const MyTime& t2);
		friend MyTime operator-(const MyTime& t1, const MyTime& t2);
		friend MyTime operator*(const MyTime& t, double n);
		friend std::ostream& operator<<(std::ostream& os, const MyTime& t);
};

#endif
