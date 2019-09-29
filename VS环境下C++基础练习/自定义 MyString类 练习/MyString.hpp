#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>
using namespace std;

class MyString {

	friend ostream& operator<<(ostream& cout, MyString& s);
	friend istream& operator>>(istream& cin, MyString& s);

public:
	MyString();
	MyString(int n);
	MyString(const char* p);
	MyString(const MyString&);
	~MyString();

public://重载等号=操作符
	MyString& operator=(const char* p);
	MyString& operator = (const MyString & s);
	char& operator[](int index);

public://重载 == ！= 操作符
	bool operator== (const char* p)const;
	bool operator== (const MyString& s)const;
	bool operator!= (const char* p)const;
	bool operator!= (const MyString& s)const;


public://重载 > < 小于号操作符
	int operator< (const char* p) const;
	int operator< (const MyString& s)const;
	int operator> (const char* p) const;
	int operator> (const MyString& s)const;
private:
	int m_len;
	char *m_p;
};

#endif