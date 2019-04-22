#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		p = new char[20];
		strcpy(p, "obja");
		cout << "A" << endl;
	}
	virtual ~A()
	{
		delete[]p;
		cout << "A~" << endl;
	}
private:
	char *p;
};

class B : public A
{ 
public:
	B()
	{
		p = new char[20];
		strcpy(p, "objb");
		cout << "B" << endl;
	}
    ~B()
	{
		delete []p;
		cout << "B~" << endl;
	}
private:
	char *p;
};

class C : public B
{
public:
	C()
	{
		p = new char[20];
		strcpy(p, "objc");
		cout << "C" << endl;
	}
	~C()
	{
		delete[]p;
		cout << "C~" << endl;
	}
private:
	char *p;
};

//ִֻ���ˣ������Լ�����������
//��ͨ������ָ�룬�����е�������������������ִ��һ��
//ֻ�ܶ����������������ͷ�������Դ
void howtodelete(A *base)
{
	delete base;         //û�ж���Ϊ���������������н������ֳ���̬
}

int main()
{
	C *myC = new C; //new delete ƥ��
	howtodelete(myC);

	//delete myC;     //ֱ��ͨ���ͷ�������Դ������Ҫдvirtual
	system("pause");
	return 0;
}
