#include <iostream>
using namespace std;


class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	void print()          
	{                             
		cout << "我是爹！" << endl;
	}
private:
	int a;
};

class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "我是爹1！" << endl;
	}
private:
	int a;
};


int main()
{                           
	printf("sizeof(parent)%d\n", sizeof(Parent));
	printf("sizeof(parent1)%d\n", sizeof(Parent1));
	system("pause");
	return 0;
}
/*sizeof(parent)4
sizeof(parent1)8*/  //结果；证明vptr指针占4字节