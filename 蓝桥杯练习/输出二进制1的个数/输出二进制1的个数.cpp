/////���������1�ĸ���
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


/////���1~4028  1�ĸ���