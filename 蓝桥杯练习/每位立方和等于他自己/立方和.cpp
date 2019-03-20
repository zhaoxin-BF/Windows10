#include<iostream>

using namespace std;

int main()
{
	int i;
	for (i = 100; i <= 999; i++)
	{
		int b = i / 100, s = i % 100 / 10, g = i % 10;
		if (b*b*b + s*s*s + g*g*g == i)
			cout << i << endl;
	}
	system("pause");
	return 0;
}