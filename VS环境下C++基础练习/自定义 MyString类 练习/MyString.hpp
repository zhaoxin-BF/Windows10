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

public://���صȺ�=������
	MyString& operator=(const char* p);
	MyString& operator = (const MyString & s);
	char& operator[](int index);

public://���� == ��= ������
	bool operator== (const char* p)const;
	bool operator== (const MyString& s)const;
	bool operator!= (const char* p)const;
	bool operator!= (const MyString& s)const;


public://���� > < С�ںŲ�����
	int operator< (const char* p) const;
	int operator< (const MyString& s)const;
	int operator> (const char* p) const;
	int operator> (const MyString& s)const;
private:
	int m_len;
	char *m_p;
};

#endif