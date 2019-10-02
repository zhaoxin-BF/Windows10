#ifndef __MyString_H__
#define __MyString_H__


#include <iostream>
using namespace std;

class MyString 
{
	friend ostream& operator<<(ostream& cout, MyString& s);
	friend istream& operator>>(istream& cin, MyString& s);
public:
	MyString();
	MyString(int n);
	MyString(const char* p);
	MyString(const MyString& p);
	~MyString();

	//���ظ�ֵ�ͷ�����
	MyString& operator=(const char* p);
	MyString& operator=(const MyString& p);
	char& operator[](int index);

	//���ص��ںţ������ں�
	bool operator==(const char* p)const;
	bool operator==(const MyString& p)const;
	bool operator!=(const char* p)const;
	bool operator!=(const MyString& p)const;

	//���ش���С�ں�
	int operator<(const char* p)const;
	int operator<(const MyString& p)const;
	int operator>(const char* p)const;
	int operator>(const MyString& p)const;
private:
	char* m_p;
	int m_len;
};

#endif