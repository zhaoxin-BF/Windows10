#include <iostream>

using namespace std;

class B
{
public:
	B()
	{
		cout << "B�Ĺ��캯��" << endl;
	}
public:
	int b;
};

class B1 : virtual public B
{
public:
	B1()
	{
		cout << "B1�Ĺ��캯��" << endl;
	}
public:
	int b1;
};

class B2 : virtual public B             //��̳У���ͬ�����ھͲ��ᱻ��γ�ʼ����
{                                       //��̳�ʼ�ջ�������⣬��̳�ֻ�ܽ���й�ͬ�����ڵ����
public:
	B2()
	{
		cout << "B2�Ĺ��캯��" << endl;
	}
public:
	int b2;
};

class C : public B1, public B2
{
public:
	C()
	{
		cout << "C�Ĺ��캯��" << endl;
	}
public:
	int c;
};

int main()
{
	C c1;
	c1.b = 100;
	cout << c1.b << endl;
	system("pause");
	return 0;
}