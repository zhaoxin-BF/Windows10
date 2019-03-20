#include<stdio.h>
#include<iostream>
#include<list>
#include<string>
#include<vector>

using namespace std;

int main()
{
	char arr[26] = { '0' };
	for (size_t i = 0; i <= 25; i++)
	{
		arr[i] = 'A' + i;
	}
	int n, m, j, k,tmp,count = 0;
	cin >> n >> m;

	for ( j = 0; j < n; j++)
	{
		tmp = j;
		if (n <= m)
		{
			for (; j>0; j--)
			{
				cout << arr[j];
			}
		}
		else
		{
			count = 0;
			for (; j>0&&count<m; j--)
			{
				cout << arr[j];
				count++;
			}
		}
		for ( k = 0; k < m-tmp; k++)
		{
			cout << arr[k];
		}
		cout << endl;
		j = tmp;
	}
	system("pause");
	return 0;
}