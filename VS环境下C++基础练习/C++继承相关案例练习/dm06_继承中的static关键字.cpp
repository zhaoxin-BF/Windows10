#include <iostream>
using namespace std;

class A
{
public:
	static int a;
	int b;
public:
	void get()
	{
		cout << "Parent b = " << b << endl;
	}
	void print()
	{
		cout << "AAAAA" << endl;
	}
};

int A::a = 100;  //��仰���Ǽ򵥵ı�����ֵ����Ҫ���Ǹ���C++����������Ҫ���ҷ����ڴ棬��Ȼ�ᱨ��

class B :private A
{
public:
	int b;
	int c;
public:
	void get_child()
	{
		cout << "Child b = " << b << endl;
		cout << "Parent a = " << a << endl;
	}
	void print()
	{
		cout << "BBBB" << endl;
	}

};

//1�� static�ؼ��� ��ѭ ������ķ��ʿ��ư���

//2�� static���εı������Ǽ򵥵ĸ�ֵ������Ҫ��ǰ�����ڴ�

//3�� A������ӹ��캯��һ��Ҫ�����public�������ڵ���ģʽ�£�Ҫ��A��Ĺ��캯������Ϊ˽�е�

int main()
{
	A a1;
	a1.print();

	B b1;
	b1.get_child();
	system("pause");
	return 0;
}

int main01()
{
	//B b1;
	system("pause");
	return 0;
}