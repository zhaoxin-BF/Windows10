#include <iostream>
using namespace std;

//��̬����Ҫ���壺�����ģʽ�Ļ������ǿ�ܵĻ�ʯ

//���캯���е����麯���ᷢ����̬��
//vptrָ��ķֲ���ʼ��
//1��ִ�и���Ĺ��캯����ʱ��c1.vptrָ������麯����
//	������Ĺ��캯��������Ϻ󣬻��c1.vptrָ��������麯����
//2�����ۣ������c1.vptrָ��ֲ����

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		print();                     //������õ��Ǹ�����麯����ǣ����vptrָ��ķֲ���ʼ��
	}
	virtual void print()          
	{                              
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

void HowToPlay(Parent *base)  
{                           
	base->print();           
}                            

int main()
{
	Child c1;        //����һ�������������������У��ڸ��๹�캯����
	system("pause"); //�����麯��print(),��Ȼ�ڳ�ʼ�����࣬������Ȼ�ǵ��ø����print()����
	return 0;
}

