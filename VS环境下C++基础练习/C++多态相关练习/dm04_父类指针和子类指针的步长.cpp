#include <iostream>
using namespace std;

//父类指针和子类指针不一样长，所以不能通过简单的++操作来往后递推子类

//只有在子类不添加任何成员变量或者函数的时候，父类指针和子类指针长度才会一样
class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;             
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
	/*
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	}*/
	
	Child(int b = 0) :Parent(0)
	{
		//this->b = b;
	}
	virtual void print()
	{
		cout << "我是儿子！" << endl;
	}
private:
	//int b;
};


int main()
{
	Parent *pP = NULL;
	Child  *cP = NULL;
	Child array[] = { Child(1), Child(2), Child(3) };

	pP = array;
	cP = array;

	pP->print();
	cP->print();    //发生多态

	pP++;           //父类指针++操作后，会发生中断
	cP++;
	pP->print();
	cP->print();    //发生多态

	pP++;
	cP++;
	pP->print();
	cP->print();     //发生多态

	system("pause"); 
	return 0;
}

