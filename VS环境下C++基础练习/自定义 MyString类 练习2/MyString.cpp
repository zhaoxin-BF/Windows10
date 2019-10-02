#define _CRT_SECURE_NO_WARNINGS
#include "MyString.hpp"

MyString::MyString()
{
	m_len = 0;
	m_p = new char[m_len + 1];
	strcpy(m_p, "");
}
MyString::MyString(int n)
{
	m_len = n;
	m_p = new char[m_len + 1];
	strcpy(m_p, "");
}
MyString::MyString(const char* p)
{
	if (p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
}
MyString::MyString(const MyString& p)
{
	m_len = p.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, p.m_p);
}
MyString::~MyString()
{
	if (m_p != NULL)
	{
		delete m_p;
		m_p = NULL;
		m_len = 0;
	}
}

//重载赋值和方括号
MyString& MyString::operator=(const char* p)
{
	//释放旧内存
	if (m_p != NULL)
	{
		delete m_p;
		m_len = 0;
	}

	//根据p开辟内存
	if (p != NULL)
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
	else
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	return *this;
}
MyString& MyString::operator=(const MyString & p)
{
	if (m_p != NULL)
	{
		m_len = 0;
		delete m_p;
	}

	//根据p的大小分配内存
	m_len = p.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, p.m_p);

	return *this;
}
char& MyString::operator[](int index)
{
	return m_p[index];
}

//重载等于号，不等于号
bool MyString::operator==(const char* p)const
{
	if (p == NULL)
	{
		if (m_len == NULL)
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		if (m_len == strlen(p))
			return !strcmp(m_p, p);//等于返回0，小于-1，大于1
	}
	return false;
}
bool MyString::operator==(const MyString& p)const
{
	if (m_len == p.m_len)
	{
		return !strcmp(m_p, p.m_p);
	}
	return false;
}
bool MyString::operator!=(const char* p)const
{
	return !(*this == p);
}
bool MyString::operator!=(const MyString& p)const
{
	return !(*this == p);
}

//重载大于小于号
int MyString::operator<(const char* p)const
{
	if (strcmp(m_p, p) < 0)
		return 1;
	else
		return 0;
}
int MyString::operator<(const MyString& p)const
{
	if (strcmp(m_p, p.m_p) < 0)
		return 1;
	else
		return 0;
}
int MyString::operator>(const char* p)const
{
	if (strcmp(m_p, p) > 0)
		return 1;
	else
		return 0;
}
int MyString::operator>(const MyString& p)const
{
	if (strcmp(m_p, p.m_p) > 0)
		return 1;
	else
	{
		return 0;
	}
}

ostream& operator<<(ostream& cout, MyString& s)
{
	cout << s.m_p;
	return cout;
}
istream& operator>>(istream& cin, MyString& s)
{
	cin >> s.m_p;
	return cin;
}