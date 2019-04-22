#include <iostream>

using namespace std;

class B
{
public:
	B()
	{
		cout << "B的构造函数" << endl;
	}
public:
	int b;
};

class B1 : virtual public B
{
public:
	B1()
	{
		cout << "B1的构造函数" << endl;
	}
public:
	int b1;
};

class B2 : virtual public B             //虚继承，共同老祖宗就不会被多次初始化了
{                                       //多继承始终会存在问题，虚继承只能解决有共同老祖宗的情况
public:
	B2()
	{
		cout << "B2的构造函数" << endl;
	}
public:
	int b2;
};

class C : public B1, public B2
{
public:
	C()
	{
		cout << "C的构造函数" << endl;
	}
public:
	int c;
};

int main()
{
	C c1;
	c1.b = 100;
	cout << c1.b << endl;
	system("pause");
	return 0;
}