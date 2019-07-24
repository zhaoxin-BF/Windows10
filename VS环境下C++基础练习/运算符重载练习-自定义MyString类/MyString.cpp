#define _CRT_SECURE_NO_WARNINGS


#include "MyString.h"


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

MyString::MyString(const char *p)
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

//拷贝构造函数
//MyString s4 = s2;
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
		m_p = NULL;
		m_len = 0;
	}
}


//重载操作符
// s4 = "s2222222";
MyString& MyString::operator=(const char *p)
{
	//旧内存释放掉
	if (m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}
	//根据p 分配内存
	if ( p == NULL)
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

	return *this;
}

// s4 = s2;
MyString& MyString::operator=(const MyString &s)
{
	//1.旧内存释放掉
	if (s.m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}
	//2.根据p 分配内存
	m_len = s.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, s.m_p);

	return *this;
}

//重载[]输出
char& MyString::operator[] (int index)
{
	return m_p[index];
}



//友元函数，全局函数
//////////////////////////////////////////////
//重载<<输出
ostream& operator<< (ostream& cout, MyString &s)
{
	cout << s.m_p;
	return cout;
}

//////////////////////////////////////////////////
//重载>>输入操作符
istream& operator>> (istream& cin, MyString &s)
{
	cin >> s.m_p;
	return cin;
}






/////////////////////////////////////////////////////////////////
//重载 == != 操作符 
bool MyString::operator== (const char *p) const
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
		{
			return !strcmp(m_p, p);
		}
	}
	return false;

}

bool MyString::operator!= (const char *p) const
{
	return !(*this == p);
}

bool MyString::operator== (const MyString &s) const
{
	if (m_len != s.m_len)
	{
		return false;
	}
	return !strcmp(m_p, s.m_p);
}


bool MyString::operator!= (const MyString &s) const
{
	return !(*this == s);
}

//////////////////////////////////////////////////////////////
//重载 < > 操作符
//if (s3 < "bbb")
int MyString::operator< (const char *p) const
{
	if (strcmp(this->m_p, p) < 0)
		return 1;
	else
		return 0;
}
int MyString::operator> (const char *p) const
{
	if (strcmp(this->m_p, p) > 0)
		return 1;
	else
		return 0;
}
int MyString::operator< (const MyString &s) const
{
	if (strcmp(this->m_p, s.m_p) < 0)
		return 1;
	else
		return 0;
}
int MyString::operator> (const MyString &s) const
{
	if (strcmp(this->m_p, s.m_p) > 0)
		return 1;
	else
		return 0;
}

/////////////////////////////////////////////////////////
//重载右移操作符

