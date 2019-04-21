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

	//在圆形1， 不再圆形0；

	int tag = c1.judgeCP(p1);
	if (tag == 1)
	{
		cout << "在圆形内！" << endl;
	}
	else if (tag == -1)
	{
		cout << "在圆形外！" << endl;
	}
	else
		cout << "在圆上！" << endl;

	system("pause");
	return 0;
}