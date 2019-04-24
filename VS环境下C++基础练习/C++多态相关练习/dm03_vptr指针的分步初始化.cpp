#include <iostream>
using namespace std;

//多态的重要意义：是设计模式的基础，是框架的基石

//构造函数中调用虚函数会发生多态吗？
//vptr指针的分步初始化
//1、执行父类的构造函数的时候，c1.vptr指向父类的虚函数表
//	当父类的构造函数运行完毕后，会把c1.vptr指向子类的虚函数表
//2、结论：子类的c1.vptr指针分步完成

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		print();                     //父类调用的是父类的虚函数，牵扯到vptr指针的分步初始化
	}
	virtual void print()          
	{                              
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

void HowToPlay(Parent *base)  
{                           
	base->print();           
}                            

int main()
{
	Child c1;        //定义一个子类对象，在这个过程中，在父类构造函数中
	system("pause"); //调用虚函数print(),虽然在初始化子类，但是任然是调用父类的print()函数
	return 0;
}

