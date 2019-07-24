
#include <iostream>
using namespace std;
#include "MyString.h"



int main01()
{
	MyString s1;
	MyString s2("s2");
	MyString s2_2 = NULL;
	MyString s3 = s2;
	MyString s4;


	//测试运算符重载 和 重载[]
	//1.重载=号测试
	 s4 = s2;
	 s4 = "s2222222";

	//MyString& operator=(const char *p);
	//MyString& operator=(const MyString &s);

	 //2.重载[]测试
	 s4[1] = '4';
	 printf("%c\n", s4[1]);
	 //char& operator[] (int index);

	 //3.重载左移<< 测试
	 cout << s4 << endl;
	 //ostream& operator<< (ostream& cout, MyString &s);


	cout << "报告北峰，程序运行完毕！" << endl;
	system("pause");
	return 0;
}


//重载 == 号测试
int main02()
{
	MyString s1;
	MyString s2("s2");
	MyString s3 = s2;

	//bool operator== (const char *p);
	//bool operator== (const MyString &s);
	//bool operator!= (const char *p);
	//bool operator!= (const MyString &s);

	if (s2 == "s22222")
	{
		printf("相等！\n");
	}
	else
	{
		printf("不相等！\n");
	}

	if (s3 == s2)
	{
		printf("相等！\n");
	}
	else
	{
		printf("不相等！\n");
	}

	system("pause"); 
	return 0;
}

void main03()
{
	MyString s1;
	MyString s2("ccc");

	MyString s3 = s2;

	s3 = "ccc";

	//int operator< (const char *p);
	//int operator> (const char *p);
	//int operator< (const MyString &s);
	//int operator> (const MyString &s);
	if (s3 > "aaa")
	{
		printf("s3 大于 bbbb\n");
	}
	else
	{
		printf("s3 小于 bbbb\n");
	}


	if (s3 < s2)
	{
		printf("s3 小于 s2\n");
	}
	else
	{
		printf("s3 大于 s2\n");
	}

	system("pause");
	return;
}

void main()
{
	MyString s1(128);
	cout << "请输入：";

	cin >> s1 ;

	cout << s1 << endl;

	//istream& operator>> (istream& cin, MyString &s);



	system("pause");
	return;
}
