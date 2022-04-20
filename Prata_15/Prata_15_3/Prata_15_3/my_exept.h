#ifndef MY_EXEPT_H_
#define MY_EXEPT_H_

#include <stdexcept>
#include <iostream>
#include <string>

class bad_mean : public std::logic_error
{
public:
	double v1;
	double v2;
	bad_mean(double a = 0.0, double b = 0.0, std::string s = "bad_hmean exception") : logic_error(s), v1(a), v2(b) { }
	virtual void mess() const { std::cout << "v1 = " << v1 << " v2 = " << v2 << std::endl; }
};


class bad_hmean : public  bad_mean
{
public:
	bad_hmean(double a = 0.0, double b = 0.0, std::string s = "bad_hmean exception") : bad_mean(a, b, s) { }
	void mess() const;
};

class bad_gmean : public  bad_mean
{
public:
	bad_gmean(double a = 0.0, double b = 0.0, std::string s = "bad_gmean exception") : bad_mean(a, b, s) { }
	void mess() const;
};

inline void bad_hmean::mess() const
{
	bad_mean::mess();
	std::cout << "arguments a = -b" << std::endl;
}

inline void bad_gmean::mess() const
{
	bad_mean::mess();
	std::cout << "arguments should be >= 0" << std::endl;
}

#endif