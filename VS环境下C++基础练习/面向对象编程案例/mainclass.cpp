#include <iostream>

using namespace std;

#include "AdvCircle.h"
#include "MyPoint.h"

int main()
{
	AdvCircle c1;
	MyPoint p1;

	c1.setCircle(1, 1, 1);
	p1.setPoint(2, 1.1);

	//��Բ��1�� ����Բ��0��

	int tag = c1.judgeCP(p1);
	if (tag == 1)
	{
		cout << "��Բ���ڣ�" << endl;
	}
	else if (tag == -1)
	{
		cout << "��Բ���⣡" << endl;
	}
	else
		cout << "��Բ�ϣ�" << endl;

	system("pause");
	return 0;
}