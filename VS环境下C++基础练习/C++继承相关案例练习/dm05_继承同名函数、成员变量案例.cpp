#include <iostream>
using namespace std;

class A
{
public:
	int b;
	int c;
public:
	void get()
	{
		cout << "Parent b = " << b << endl;
	}
	void print()
	{
		cout << "AAAAA" << endl;
	}
};

class B :public A
{
public:
	int b;
	int c;
public:
	void get_child()
	{
		cout << "Child b = " << b << endl;
	}
	void print()
	{
		cout << "BBBB" << endl;
	}

};

int main()
{
	B b1;     
	b1.print();     //默认是子类的构造函数
	b1.A::print();
	b1.B::print();
	system("pause");
	return 0;
}

//int main()
//{
//	B b1;
//	b1.b = 1;       //默认情况下，修改的是B类的b;
//	b1.get_child();
//	b1.A::b = 100;  //得标明域，修改的是A类的b
//	b1.get();
//	system("pause");
//	return 0;
//}