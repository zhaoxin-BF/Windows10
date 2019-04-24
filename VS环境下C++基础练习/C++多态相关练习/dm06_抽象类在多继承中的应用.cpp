#include <iostream>

using namespace std;

class Interface1
{
public:
	virtual int add(int a, int b) = 0;
	virtual void print() = 0;
};

class Interface2
{
public:
	virtual int mult(int a, int b) = 0;
	virtual void print() = 0;
};

class Parent
{
public:
	int getA()
	{
		a = 0;
		return a;
	}
private:
	int a;
	int b;
};

class Child : public Parent, public Interface1, public Interface2
{
public:
	virtual int add(int a, int b)
	{
		cout << "Child add() 已经执行" << endl;
		return 0;
	}
	virtual void print()
	{
		cout << "Child print() 已经执行" << endl;
	}

	virtual int mult(int a, int b)
	{
		cout << "Child mult() 已经执行" << endl;
		return 0;
	}
};


int main()
{
	Child c1;
	c1.print();

	Interface1 *it1 = &c1;
	it1->add(1,2);
	it1->print();

	Interface2 *it2 = &c1;
	it2->mult(3,6);
	it2->print();


	system("pause");
	return 0;
}