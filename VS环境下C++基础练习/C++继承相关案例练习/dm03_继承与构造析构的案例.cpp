#include <iostream>
using namespace std;


//子类先调用父类的构造函数
//子类先调用自己的析构函数，再调用父类的析构函数
class Parent
{
public:
	Parent(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "parent 构造函数！" << endl;
	}
	~Parent()
	{
		cout << "Parent 析构函数！" << endl;
	}
private:
	int a;
	int b;
};

class Child : public Parent
{
public:
	Child(int a, int b, int c) : Parent(a, b)
	{
		this->c = c;
		cout << "Child 构造函数！" << endl;
	}

	~Child()
	{
		cout << "Child 析构函数！" << endl;
	}
private:
	int c;
};


void playObj()
{
	Child c1(1, 2, 3);
}
int main()
{
	playObj();
	system("pause");
	return 0;
}