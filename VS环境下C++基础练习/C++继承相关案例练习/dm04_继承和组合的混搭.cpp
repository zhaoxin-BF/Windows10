#include <iostream>
using namespace std;


//�����ȵ��ø���Ĺ��캯��
//�����ȵ����Լ��������������ٵ��ø������������
class Object
{
public:
	Object(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Obj���캯������ִ��" << "a" << a << "b" << b << endl;
	}
	~Object()
	{
		cout << "Obj��������" << endl;
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
		cout << "parent ���캯����" <<p<< endl;
	}
	~Parent()
	{
		cout << "Parent ����������" << p << endl;
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
		cout << "Child ���캯����" << myp << endl;
	}

	~Child()
	{
		cout << "Child ����������" << myp << endl;
	}
private:
	char *myp;
	Object obj1;
	Object obj2;
};

void playobj()
{
	Child c1("�̳в���");
}

int main()
{
	playobj();
	system("pause");
	return 0;
}

/*//���

1���ȵ��������ڵ�
//Obj���캯������ִ��a1b2

2���ٵ����׵���
//parent ���캯�����̳в���

3���ٵ�����϶����
//Obj���캯������ִ��a3b4
//Obj���캯������ִ��a5b6

4���������Լ��Ĺ��캯��
//Child ���캯�����̳в���*/

/*�����෴
Child �����������̳в���
Obj��������
Obj��������
Parent �����������̳в���
Obj��������*/