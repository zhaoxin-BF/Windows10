#include <iostream>

using namespace std;

#include "MyTeacher.h"

int maintest1()
{
	MyTeacher t1;
	t1.setAge(36);
	cout << "age = " << t1.getAge() << endl;
	system("pause");
	return 0;
}