#include <iostream>
using namespace std;

//��д�����أ��ض���
//��д������2����֮��
//���ر��뷢����һ����֮��

//��д��Ϊ2��(����͸���֮��  )
//1���麯����д  ��ʹ��virtual����֮���ܹ�������̬��
//��̬���������ڼ���ݶ����������ѡ����ú���

//2�����麯����д�������ʹ��virtual���ǽ��ض��壩

//3�������޷����ظ���ĺ��������ᷢ�����ǣ�����ʹ��������ʹ��
class Parent
{
	//�����������������ع�ϵ
public:
	int abc()                  //�ض���
	{
		cout << "abc" << endl;
	}
	virtual void func()
	{
		cout << "Parent func() do..." << endl;
	}
	virtual void func(int i)
	{
		cout << "Parent func(int i) do" << i << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "Parent func(int i, int j) do..." << i << " " << j << endl;
	}
};

class Child :public Parent
{
public:
	int abc()                     //�ض���
	{                             //�����޷����ظ���ĺ���������������
		cout << "abc" << endl;
	}
	virtual void func(int i, int j) //��virtual������������ ��д���麯����д��
	{
		cout << "Child func(int i, int j) do..." << endl;
	}
	virtual void func(int i, int j, int k)
	{
		cout << "Child func(int i, int j, int k)" << endl;
	}
};

int main()
{
	Child c1;

	c  1.func();//C++�������п�����func()���������֣�ֻ����������func()���������������в���func()���������Ա���

	system("pause");
	return 0;
}