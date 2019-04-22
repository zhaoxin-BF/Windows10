#include <iostream>

using namespace std;

class Parent
{
public:
	void print()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
protected:
private:
	int a = 1, b = 2;
};

class Child : public Parent        //子类可以使用基类的——所有——共有函数和成员变量
//class Child : protected Parent
//class Child : private Parent
{
public:
protected:
private:
	int c;
};

int main1()
{
	cout << "Hello ..." << endl;
	Child c;
	c.print();

	system("pause");
	return 0;
}