#include <iostream>
using namespace std;


//�����ȵ��ø���Ĺ��캯��
//�����ȵ����Լ��������������ٵ��ø������������
class Parent
{
public:
	Parent(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "parent ���캯����" << endl;
	}
	~Parent()
	{
		cout << "Parent ����������" << endl;
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
		cout << "Child ���캯����" << endl;
	}

	~Child()
	{
		cout << "Child ����������" << endl;
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