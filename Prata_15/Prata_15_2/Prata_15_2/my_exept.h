#ifndef MY_EXEPT_H_
#define MY_EXEPT_H_

#include <stdexcept>
#include <typeinfo>
#include <iostream>
#include <string>

class bad_hmean : public std::logic_error
{
private:
	double v1;
	double v2;
public:
	bad_hmean( double a = 0.0, double b = 0.0, std::string s = "bad_hmean exception") : logic_error(s), v1(a), v2(b) { }
	void mess() const;
	const char* what() const noexcept override; // —ŒŒ¡Ÿ¿≈“ »Ãﬂ ‘”Õ ÷»» » —”“‹ œ–Œ¡À≈Ã€
};

class bad_gmean : public std::logic_error
{
public:
	double v1;
	double v2;
	const char* mess() const;
	bad_gmean( double a = 0.0, double b = 0.0, std::string s = "bad_gmean exception") : logic_error(s), v1(a), v2(b) { }
	const char* what() const noexcept override; // —ŒŒ¡Ÿ¿≈“ »Ãﬂ ‘”Õ ÷»» » —”“‹ œ–Œ¡À≈Ã€
};

inline void bad_hmean::mess() const
{
	std::cout << "arguments a = -b" << std::endl;
}
inline const char* bad_hmean::what() const noexcept
{
	return " bad_hmean::what() :  arguments a = -b";
}

inline const char* bad_gmean::mess() const
{
	return "arguments should be >= 0";
}

inline const char* bad_gmean::what() const noexcept
{
	return " bad_gmean::what() : arguments a = -b ";
}


#endif
