
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


	//������������� �� ����[]
	//1.����=�Ų���
	 s4 = s2;
	 s4 = "s2222222";

	//MyString& operator=(const char *p);
	//MyString& operator=(const MyString &s);

	 //2.����[]����
	 s4[1] = '4';
	 printf("%c\n", s4[1]);
	 //char& operator[] (int index);

	 //3.��������<< ����
	 cout << s4 << endl;
	 //ostream& operator<< (ostream& cout, MyString &s);


	cout << "���汱�壬����������ϣ�" << endl;
	system("pause");
	return 0;
}


//���� == �Ų���
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
		printf("��ȣ�\n");
	}
	else
	{
		printf("����ȣ�\n");
	}

	if (s3 == s2)
	{
		printf("��ȣ�\n");
	}
	else
	{
		printf("����ȣ�\n");
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
		printf("s3 ���� bbbb\n");
	}
	else
	{
		printf("s3 С�� bbbb\n");
	}


	if (s3 < s2)
	{
		printf("s3 С�� s2\n");
	}
	else
	{
		printf("s3 ���� s2\n");
	}

	system("pause");
	return;
}

void main()
{
	MyString s1(128);
	cout << "�����룺";

	cin >> s1 ;

	cout << s1 << endl;

	//istream& operator>> (istream& cin, MyString &s);



	system("pause");
	return;
}
