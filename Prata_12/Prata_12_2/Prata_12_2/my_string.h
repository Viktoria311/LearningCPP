#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <iostream>

class MyString
{
private:
	char* str_;
	int len_;
	static int num_stings_;
	static const int CINLIM = 80;
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& obj);
   ~MyString();
    int length() const { return len_; }
	void StringLow();
	void StringUp();
	int has(char ch) const;
	static int HowMany();
	MyString& operator=(const MyString& obj);
	MyString& operator=(const char* str);
	MyString& operator+(const MyString& obj);
	MyString& operator+(const char* str);
	friend MyString operator+(const char* str, const MyString& obj);
	char& operator[](int i);
	const char& operator[](int i) const;
	friend bool operator<(const MyString& obj1, const MyString& obj2);
	friend bool operator>(const MyString& obj1, const MyString& obj2);
	friend bool operator==(const MyString& obj1, const MyString& obj2);
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& obj);
};

#endif
