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

MyString::MyString(const MyString& s)
{
	m_len = s.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, s.m_p);
}

MyString::~MyString()
{
	if (m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
		m_p = NULL;
	}
}

/////////////////////////////重载等号操作符 s4 = "12346456"
MyString& MyString::operator=(const char* p)
{
	//把旧内存释放掉
	if (m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}

	//根据p分配内存
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
MyString& MyString::operator = (const MyString& s)
{
	if (m_p != NULL)
	{
		m_len = 0;
		delete[] m_p;
	}

	//根据s分配内存
	m_len = s.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, s.m_p);

	return *this;
}
char& MyString::operator[](int index)
{
	return m_p[index];
}

/////////////////////////重载 == ！= 操作符
bool MyString::operator == (const char* p)const
{
	if (p == NULL)
	{
		if (m_len == 0)
			return true;
		else
			return false;
	}
	else
	{
		if (m_len == strlen(p))
			return !strcmp(m_p,p);//等于返回0，大于返回>0,小于返回<0
		
	}
	return false;
}
bool MyString::operator== (const MyString& s)const
{
	if (m_len != s.m_len)
	{
		return false;
	}
	return !strcmp(m_p,s.m_p);
}
bool MyString::operator!= (const char* p)const
{
	return !(*this == p);
}
bool MyString::operator!= (const MyString& s)const
{
	return !(s == *this);
}

////////////////////////重载 > < 号操作符 if(s3 < "bbb")
int MyString::operator< (const char* p) const
{
	if (strcmp(this->m_p, p) < 0)
		return 1;
	else
		return 0;
}
int MyString::operator> (const char* p) const
{
	if (strcmp(this->m_p, p) > 0)
		return 1;
	else
		return 0;
}
int MyString::operator< (const MyString& s) const
{
	if (strcmp(this->m_p, s.m_p) < 0)
		return 1;
	else
		return 0;
}
int MyString::operator> (const MyString& s) const
{
	if (strcmp(this->m_p, s.m_p) > 0)
		return 1;
	else
		return 0;
}

//////////////////////////////////重载输入输出操作
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

