/////输出二进制1的个数
#include <iostream>

using namespace std;

int main()
{
	int arr[1000] = { 0 };

	int n,i,r,count=0;
	cin >> n;
	for (i = 0;; i++)
	{
		r = n % 2;
		if (r == 1)
			count++;
		arr[i] = r;
		n = n / 2;
		if (n == 1)
		{
			break;
		}
	}
	cout << count + 1<<endl;
	system("pause");
	return 0;
}


/////输出1~4028  1的个数