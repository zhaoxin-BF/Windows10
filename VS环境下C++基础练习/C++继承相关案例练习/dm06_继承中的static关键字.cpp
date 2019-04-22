#include <iostream>
using namespace std;

class A
{
public:
	static int a;
	int b;
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

int A::a = 100;  //这句话不是简单的变量赋值，重要的是告诉C++编译器，你要给我分配内存，不然会报错

class B :private A
{
public:
	int b;
	int c;
public:
	void get_child()
	{
		cout << "Child b = " << b << endl;
		cout << "Parent a = " << a << endl;
	}
	void print()
	{
		cout << "BBBB" << endl;
	}

};

//1、 static关键字 遵循 派生类的访问控制案例

//2、 static修饰的变量不是简单的赋值，而是要提前分配内存

//3、 A类中添加构造函数一定要定义成public，除非在单例模式下，要把A类的构造函数定义为私有的

int main()
{
	A a1;
	a1.print();

	B b1;
	b1.get_child();
	system("pause");
	return 0;
}

int main01()
{
	//B b1;
	system("pause");
	return 0;
}