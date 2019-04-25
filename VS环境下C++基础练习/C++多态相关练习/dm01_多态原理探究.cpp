#include <iostream>
using namespace std;

//多态成立的三个条件，
//1、要有继承；2、虚函数重写；3、父类指针指向子类对象
//重点是要用父类的指针去指向子类对象，才能实现多态，不能用子类的指针去当作多态调用的参数

//////////////////////例子
/*
void HowToPlay(Parent *base)
{
	base->print();
}
*/

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()            //写了virtual 的地方，C++编译器第一个会做手脚的地方
	{                               //虚函数表
		cout << "我是爹！" << endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "我是儿子！" << endl;
	}
private:
	int b;
};
                              //动态链编、迟绑定，c++编译器在运行时才去判断虚函数
void HowToPlay(Parent *base)  //父类和子类分别有vptr指针，指向该对象的虚函数表——》查找函数的入口地址
{                             //C++编译器根本不需要区分是父类的还是子类的对象
	base->print();            //第二个编译器会动手脚的地方
}                             //传来子类，输出子类的print,父类输出父类的print

int main()
{                             //定义对象的时候提前布局，
	Parent p1;                //第三个编译器会动手脚的地方，用类定义对象的时候
	Child c1;                 //用类定义对象的时候，C++编译器会在对象中添加一个vptr指针
	                          //每个对象中都有一个vptr指针，指向虚函数表
	HowToPlay(&p1);
	HowToPlay(&c1);

	//system("pause");
	return 0;
}
