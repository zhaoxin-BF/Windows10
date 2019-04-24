#include <iostream>

using namespace std;

//抽象类，不能被实例化（Figer f;）
//纯虚函数的应用场景
//面向抽象类编程（面向一套预先定义好饿接口编程）

//解开耦合。。。模块的划分

class Figure                   
{
public:
	//约定一个统一的接口，让子类使用，让子类必须去实现
	virtual void getArea() = 0;//纯虚函数,
private:
};

class Circle : public Figure
{
public:
	Circle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "圆的面积:" << 3.14*a*a << endl;
	}
private:
	int a;
	int b;
};

class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "三角形的面积:" << a*b/2 << endl;
	}
private:
	int a;
	int b;
};

class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "四边形的面积:" << a*b << endl;
	}
private:
	int a;
	int b;
};

void objplay(Figure *base)
{
	base->getArea();//会发生多态
}

int main()
{

	Circle c1(10, 20);
	Tri t1(20, 30);
	Square s1(40, 50);
	//面向抽象类编程（面向一套预先定义好饿接口编程）


	objplay(&c1);
	objplay(&t1);
	objplay(&s1);
	system("pause");
	return 0;
}