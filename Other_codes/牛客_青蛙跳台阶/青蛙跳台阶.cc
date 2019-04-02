#include <iostream>
#include <string>
using namespace std;

int num(int target)
{
	int a = 1;
	int b = 2;
	if (target <= 0)
	{
		return 0;
	}
	else if (target == 1)
	{
		return target;
	}
	else
	{
		for (int i = 2; i <= target; i++)
		{
			b = 2 * a;
			a = b;
		}
		return b;
	}
}

int main()
{
	int n;
	cin >> n;
	cout << num(n) << endl;
	system("pause");
	return 0;
}
