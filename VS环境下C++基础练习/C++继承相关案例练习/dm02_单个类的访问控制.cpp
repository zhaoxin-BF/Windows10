#include <iostream>
using namespace std;

//public:������ڲ�ʹ�ã�������ⲿ����ʹ��
//protected�����εĳ�Ա����������������ڲ�ʹ�ã��ڼ̳е������п���
//private:������ڲ�ʹ�ã�����������ⲿʹ��
class Parent
{
public:
	int a;
protected:
	int b;
private:
	int c;
public:
	void printT()
	{
		cout << "printT" << endl;
	}
	
};

//class Child2 : private Parent
//{
//public:
//	void useVar()
//	{
//		a = 0; //��ȷ
//		b = 0; //��ȷ
//		c = 0; //����
//	}
//protected:
//private:
//};
//
//
//int main()
//{
//	Child2 t1, t2;
//	//˽�м̳еģ�һ�Ų��������汻����
//	t1.a = 10;
//	t1.b = 20;
//	t1.c = 30;
//	cout << "Hello ..." << endl;
//	system("pause");
//	return 0;
//}

class Child1 : protected Parent
{
public:
	void useVar()
	{
		a = 0;
		b = 0;//�����̳е�ֻ�������ڱ����ã��������������
		c = 0;//����
	}
protected:
private:
};


int main()
{
	Child1 t1, t2;
	//t1.a = 10;
	//�����̳У�����ı�����ֻ��������ڲ�ʹ�ã�����������ⲿʹ��

	//t1.b = 20;
	//�����ģ�ֻ��������ڲ�ʹ�ã�����������ⲿʹ�� 
	cout << "Hello ..." << endl;
	system("pause");
	return 0;
}


//class Child : public Parent
//{
//public :
//	void useVar()
//	{
//		a = 0;
//		b = 0;
//		//c = 0;
//	}
//protected:
//private:
//};
//
//
//int main()
//{
//	Parent t1, t2;
//	t1.a = 10;
//	//t1.b = 20;
//	//�����ģ�ֻ��������ڲ�ʹ�ã�����������ⲿʹ�� 
//	cout << "Hello ..." << endl;
//	system("pause");
//	return 0;
//}