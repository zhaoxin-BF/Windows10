#include <iostream>

using namespace std;
class Cube
{
public:
	void setABC(int a = 0, int b = 0, int c = 0)
	{
		m_a = a, m_b = b, m_c = c;
	}
public:
	int getV()
	{
		m_v = m_a*m_b*m_c;
		return m_v;
	}

	int getS()
	{
		m_s = 2*(m_a*m_b + m_a*m_c + m_b*m_c);
		return m_s;
	}

	int judgeCube(Cube &v1, Cube &v2)
	{
		if (v1.getV() == v2.getV())
			return 1;
		else
		{
			return 0;
		}
	}

	int judgeCube(Cube &v2)//成员函数重载
	{
		if (this->getV() == v2.getV())
		{
			return 1;
		}
		else
			return 0;
	}

private:
	int m_a, m_b, m_c, m_v, m_s;
};



//int main()
//{
//	Cube v1, v2;
//	v1.setABC(1, 2, 3);
//	v2.setABC(4, 5, 6);
//	cout << "t1V = " << v1.getV() << endl;
//	cout << "t2V = " << v2.getV() << endl;
//
//	//判断两个立方体是否相等
//	//问题抛出冗余 v1.judgeCube(v1, v2);
//
//	if (v1.judgeCube(v2) == 1)
//	{
//		cout << "Yes!" << endl;
//	}
//	else
//		cout << "No!" << endl;
//	system("pause");
//	return 0;
//}

////全局函数
////1相等，0不相等
//int judgeCube(Cube v1, Cube v2)
//{
//	if (v1.getV() == v2.getV())
//		return 1;
//	else
//	{
//		return 0;
//	}
//}
//方法一：全局函数的调用
//int main()
//{
//	Cube v1, v2;
//	v1.setABC(1, 2, 3);
//	v2.setABC(4, 5, 6);
//	cout << "t1V = " << v1.getV() << endl;
//	cout << "t2V = " << v2.getV() << endl;
//
//	//判断两个立方体是否相等
//	if (judgeCube(v1, v2))
//	{
//		cout << "相等！" << endl;
//	}
//	else
//		cout << "不相等！" << endl;
//	system("pause");
//	return 0;
//}