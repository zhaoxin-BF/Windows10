
#include <iostream>
#include "Manager.h"
#include "HourlyWoeker.h"
#include "PieceWorker.h"
using namespace std;

void display(Employee *base)
{
	base->print();
}

int main()
{

	Manager m1(101, "赵鑫", 30000), m2(102, "李苏亚", 35400);
	HourlyWorker h1(103, "吴青山", 250, 50), h2(104, "李昆洪", 300, 45);
	PieceWorker p1(105, "雷添", 8, 2000), p2(106, "石万虎", 10, 1500);

	//display(&m1);
	//display(&m2);
	//display(&h1);
	//display(&h2);
	//display(&p1);
	//display(&p2);

	Employee *base;
	base = &m1;
	base->print();

	base = &m2;
	base->print();

	cout << "报告北峰，程序运行完毕！" << endl;
	system("pause");
	return 0;
}