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

class Child : public Parent        //�������ʹ�û���ġ������С������к����ͳ�Ա����
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