#include <iostream>
using namespace std;

//��̬����������������
//1��Ҫ�м̳У�2���麯����д��3������ָ��ָ���������
//�ص���Ҫ�ø����ָ��ȥָ��������󣬲���ʵ�ֶ�̬�������������ָ��ȥ������̬���õĲ���

//////////////////////����
/*
void HowToPlay(Parent *base)
{
	base->print();
}
*/

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()            //д��virtual �ĵط���C++��������һ�������ֽŵĵط�
	{                               //�麯����
		cout << "���ǵ���" << endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "���Ƕ��ӣ�" << endl;
	}
private:
	int b;
};
                              //��̬���ࡢ�ٰ󶨣�c++������������ʱ��ȥ�ж��麯��
void HowToPlay(Parent *base)  //���������ֱ���vptrָ�룬ָ��ö�����麯�����������Һ�������ڵ�ַ
{                             //C++��������������Ҫ�����Ǹ���Ļ�������Ķ���
	base->print();            //�ڶ����������ᶯ�ֽŵĵط�
}                             //�������࣬��������print,������������print

int main()
{                             //��������ʱ����ǰ���֣�
	Parent p1;                //�������������ᶯ�ֽŵĵط������ඨ������ʱ��
	Child c1;                 //���ඨ������ʱ��C++���������ڶ��������һ��vptrָ��
	                          //ÿ�������ж���һ��vptrָ�룬ָ���麯����
	HowToPlay(&p1);
	HowToPlay(&c1);

	//system("pause");
	return 0;
}
