
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

	Manager m1(101, "����", 30000), m2(102, "������", 35400);
	HourlyWorker h1(103, "����ɽ", 250, 50), h2(104, "������", 300, 45);
	PieceWorker p1(105, "����", 8, 2000), p2(106, "ʯ��", 10, 1500);

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

	cout << "���汱�壬����������ϣ�" << endl;
	system("pause");
	return 0;
}