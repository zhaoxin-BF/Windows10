
#include <iostream>
using namespace std;



int main()
{

	int sum = 0;
	int value = 0;

	while (cin>>value)
	{
		sum += value;
	}

	cout << "Sum is " << sum << endl;
	cout << "报告北峰，程序运行完毕！" << endl;
	system("pause");
	return 0;
}