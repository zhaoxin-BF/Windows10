#include <iostream>
using namespace std;


//子类先调用父类的构造函数
//子类先调用自己的析构函数，再调用父类的析构函数
class Object
{
public:
	Object(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Obj构造函数调用执行" << "a" << a << "b" << b << endl;
	}
	~Object()
	{
		cout << "Obj析构函数" << endl;
	}
protected:
	int a;
	int b;
};

class Parent : public Object
{
public:
	Parent(char *p) : Object(1,2)
	{
		this->p = p;
		cout << "parent 构造函数！" <<p<< endl;
	}
	~Parent()
	{
		cout << "Parent 析构函数！" << p << endl;
	}
protected:
	char *p;
};

class Child : public Parent
{
public:
	Child(char *p) : Parent(p), obj1(3, 4), obj2(5,6)
	{
		this->myp = p;
		cout << "Child 构造函数！" << myp << endl;
	}

	~Child()
	{
		cout << "Child 析构函数！" << myp << endl;
	}
private:
	char *myp;
	Object obj1;
	Object obj2;
};

void playobj()
{
	Child c1("继承测试");
}

int main()
{
	playobj();
	system("pause");
	return 0;
}

/*//结果

1、先调用老祖宗的
//Obj构造函数调用执行a1b2

2、再调用亲爹的
//parent 构造函数！继承测试

3、再调用组合对象的
//Obj构造函数调用执行a3b4
//Obj构造函数调用执行a5b6

4、最后调用自己的构造函数
//Child 构造函数！继承测试*/

/*析构相反
Child 析构函数！继承测试
Obj析构函数
Obj析构函数
Parent 析构函数！继承测试
Obj析构函数*/