#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout << "Parent a" << a <<endl;
	}
	
	virtual void print()
	{
		cout << "Parent 打印a = " << a << endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b) :Parent(10)
	{
		this->b = b;
		cout << "Child b" << b << endl;
	}
	void print()
	{
		cout << "Child 打印b = " << b << endl;
	}
private:
	int b;
};


int main()
{
	Parent *base = NULL;
	Parent p1(20);
	Child c1(30);
	base = &p1;
	base->print();//执行父类的打印函数

	base = &c1;
	base->print();//执行父类的打印函数


	system("pause");
	return 0;
}