#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout << "Parent a" << a <<endl;
	}
	
	virtual void print()
	{
		cout << "Parent ��ӡa = " << a << endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b) :Parent(10)
	{
		this->b = b;
		cout << "Child b" << b << endl;
	}
	void print()
	{
		cout << "Child ��ӡb = " << b << endl;
	}
private:
	int b;
};


int main()
{
	Parent *base = NULL;
	Parent p1(20);
	Child c1(30);
	base = &p1;
	base->print();//ִ�и���Ĵ�ӡ����

	base = &c1;
	base->print();//ִ�и���Ĵ�ӡ����


	system("pause");
	return 0;
}