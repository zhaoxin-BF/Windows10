#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		p = new char[20];
		strcpy(p, "obja");
		cout << "A" << endl;
	}
	virtual ~A()
	{
		delete[]p;
		cout << "A~" << endl;
	}
private:
	char *p;
};

class B : public A
{ 
public:
	B()
	{
		p = new char[20];
		strcpy(p, "objb");
		cout << "B" << endl;
	}
    ~B()
	{
		delete []p;
		cout << "B~" << endl;
	}
private:
	char *p;
};

class C : public B
{
public:
	C()
	{
		p = new char[20];
		strcpy(p, "objc");
		cout << "C" << endl;
	}
	~C()
	{
		delete[]p;
		cout << "C~" << endl;
	}
private:
	char *p;
};

//只执行了，父类自己的析构函数
//想通过父类指针，把所有的子类对象的析构函数都执行一遍
//只能定义虚析构函数，释放所有资源
void howtodelete(A *base)
{
	delete base;         //没有定义为虚析构函数，所有将不表现出多态
}

int main()
{
	C *myC = new C; //new delete 匹配
	howtodelete(myC);

	//delete myC;     //直接通过释放子类资源，则不需要写virtual
	system("pause");
	return 0;
}
