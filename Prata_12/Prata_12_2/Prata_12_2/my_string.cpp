#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include "my_string.h"


int MyString::num_stings_ = 0;

MyString::MyString()
{
	len_ = 0;
	str_ = new char[1];
	str_[0] = '\0';
	++num_stings_;
}

MyString::MyString(const char* str)
{
	len_ = strlen(str);
	str_ = new char[len_ + 1];
	strncpy(str_, str, len_);
	str_[len_] = '\0';
	
	++num_stings_;
}

MyString::MyString(const MyString& obj)
{
	len_ = obj.len_;
	str_ = new char[obj.len_ + 1];
	strncpy(str_, obj.str_, len_);
	str_[len_] = '\0';
	
	++num_stings_;
}

MyString::~MyString()
{
	delete[] str_;
	--num_stings_;
}

void MyString::StringLow()
{
	for (int i = 0; i < len_; ++i)
		str_[i] = tolower(str_[i]);
}

void MyString::StringUp()
{
	for (int i = 0; i < len_; ++i)
		str_[i] = toupper(str_[i]);
}

int MyString::has(char ch) const
{
	int quantity = 0;

	for (int i = 0; i < len_; ++i)
		if (str_[i] == ch) ++quantity;
	return quantity;
}

int MyString::HowMany()
{
	return num_stings_;
}

MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj) return *this;
	else
	{
		len_ = obj.len_;
		delete[] str_;
		str_ = new char[len_ + 1];
		strncpy(str_, obj.str_, len_);
		str_[len_] = '\0';
		
		return *this;
	}
}

MyString& MyString::operator=(const char* str)
{
	if ( strcmp(this->str_, str) == 0) return *this;
	else
	{
		len_ = strlen(str);
		delete[] str_;
		str_ = new char[len_ + 1];
		strncpy(str_, str, len_);
		str_[len_] = '\0';
		
		return *this;
	}
}

MyString& MyString::operator+(const MyString& obj)
{
	this->len_ += obj.len_;
	char* some_str = new char[len_ + 1];
	strncpy(some_str, str_, len_);
	delete[] str_;
	strcat_s(some_str, len_, obj.str_);
	str_ = new char[len_ + 1];
	strncpy(str_, some_str, len_);
	str_[len_] = '\0';
	delete[] some_str;

	return *this;
}

MyString& MyString::operator+(const char* str)
{
	this->len_ += strlen(str);
	char* some_str = new char[len_ + 1];
	strncpy(some_str, str_, len_);
	delete[] str_;
	strcat_s(some_str, len_, str);
	some_str[len_ + 1] = '\0';
	str_ = new char[len_ + 1];
	strncpy(str_, some_str, len_);
	str_[len_] = '\0';
	delete[] some_str;

	return *this;
}

char& MyString::operator[](int i)
{
	return str_[i];
}

const char& MyString::operator[](int i) const
{
	return str_[i];
}

MyString operator+(const char* str, const MyString& obj)
{
	int len_some_str = obj.len_;
	len_some_str += strlen(str);
	char* some_str = new char[len_some_str + 1];
	strncpy(some_str, str, len_some_str);
	strcat_s(some_str, len_some_str, obj.str_);
	some_str[len_some_str] = '\0';
	MyString z(some_str);
	delete[] some_str;

	return z;
}

bool operator<(const MyString& obj1, const MyString& obj2)
{
	return obj1.len_ < obj2.len_;
}

bool operator>(const MyString& obj1, const MyString& obj2)
{
	return obj1.len_ > obj2.len_;
}

bool operator==(const MyString& obj1, const MyString& obj2)
{
	return obj1.len_ == obj2.len_;
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	os << obj.str_;

	return os;
}

std::istream& operator>>(std::istream& is, MyString& obj)
{
	/*char buffer[MyString::CINLIM];
	is.get(buffer, MyString::CINLIM);
	if (is) 
	{
		obj.str_ = buffer;
	}
	while (is && is.get() != '\n') continue;*/
	/////////////////////////////////////////////////

	char buffer[MyString::CINLIM];
	is.getline(buffer, MyString::CINLIM);
	obj = buffer;
	
	return is;
}