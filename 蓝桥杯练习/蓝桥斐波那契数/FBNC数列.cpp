#include<iostream>

using namespace std;

int main()
{
	int n;
	int array[3] = { 0 };
	cin >> n;
	int i = 0;
	for (i = 0; i <= n; i++)
	{
		if (i == 0)
			array[i] = 0;
		if (i == 1)
			array[i] = 1;
		else
			array[(3 + i) % 3] = (array[(3 + i - 2) % 3] + array[(3 + i - 1) % 3]) % 10007;
	}
	cout << array[(3 + n) % 3] << endl;
	system("pause");
}