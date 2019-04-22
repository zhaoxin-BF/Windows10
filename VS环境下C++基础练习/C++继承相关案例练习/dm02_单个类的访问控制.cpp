#include <iostream>
using namespace std;

//public:在类的内部使用，在类的外部都能使用
//protected：修饰的成员变量方法，在类的内部使用，在继承的子类中可用
//private:在类的内部使用，不能再类的外部使用
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
//		a = 0; //正确
//		b = 0; //正确
//		c = 0; //错误
//	}
//protected:
//private:
//};
//
//
//int main()
//{
//	Child2 t1, t2;
//	//私有继承的，一概不能再外面被调用
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
		b = 0;//保护继承的只能在类内被调用，不能再类外调用
		c = 0;//错误
	}
protected:
private:
};


int main()
{
	Child1 t1, t2;
	//t1.a = 10;
	//保护继承，的类的变量，只能在类的内部使用，不能再类的外部使用

	//t1.b = 20;
	//保护的，只能在类的内部使用，不能再类的外部使用 
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
//	//保护的，只能在类的内部使用，不能再类的外部使用 
//	cout << "Hello ..." << endl;
//	system("pause");
//	return 0;
//}