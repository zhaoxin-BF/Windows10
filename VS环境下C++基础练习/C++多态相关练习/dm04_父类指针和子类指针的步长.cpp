#include <iostream>
using namespace std;

//����ָ�������ָ�벻һ���������Բ���ͨ���򵥵�++�����������������

//ֻ�������಻����κγ�Ա�������ߺ�����ʱ�򣬸���ָ�������ָ�볤�ȲŻ�һ��
class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;             
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
	/*
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	}*/
	
	Child(int b = 0) :Parent(0)
	{
		//this->b = b;
	}
	virtual void print()
	{
		cout << "���Ƕ��ӣ�" << endl;
	}
private:
	//int b;
};


int main()
{
	Parent *pP = NULL;
	Child  *cP = NULL;
	Child array[] = { Child(1), Child(2), Child(3) };

	pP = array;
	cP = array;

	pP->print();
	cP->print();    //������̬

	pP++;           //����ָ��++�����󣬻ᷢ���ж�
	cP++;
	pP->print();
	cP->print();    //������̬

	pP++;
	cP++;
	pP->print();
	cP->print();     //������̬

	system("pause"); 
	return 0;
}

