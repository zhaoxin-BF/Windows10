#include <iostream>
using namespace std;

//重写，重载，重定义
//重写发生在2个类之间
//重载必须发生在一个类之间

//重写分为2类(子类和父类之间  )
//1、虚函数重写  （使用virtual声明之后能够产生多态）
//多态是在运行期间根据对象的类型来选择调用函数

//2、非虚函数重写（如果不使用virtual，那叫重定义）

//3、子类无法重载父类的函数，将会发生覆盖，可以使用域名来使用
class Parent
{
	//这三个函数都是重载关系
public:
	int abc()                  //重定义
	{
		cout << "abc" << endl;
	}
	virtual void func()
	{
		cout << "Parent func() do..." << endl;
	}
	virtual void func(int i)
	{
		cout << "Parent func(int i) do" << i << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "Parent func(int i, int j) do..." << i << " " << j << endl;
	}
};

class Child :public Parent
{
public:
	int abc()                     //重定义
	{                             //子类无法重载父类的函数，将发生覆盖
		cout << "abc" << endl;
	}
	virtual void func(int i, int j) //加virtual的重名函数叫 重写（虚函数重写）
	{
		cout << "Child func(int i, int j) do..." << endl;
	}
	virtual void func(int i, int j, int k)
	{
		cout << "Child func(int i, int j, int k)" << endl;
	}
};

int main()
{
	Child c1;

	c  1.func();//C++在子类中看到了func()函数的名字，只会子类中找func()函数，由于子类中不含func()函数，所以报错

	system("pause");
	return 0;
}