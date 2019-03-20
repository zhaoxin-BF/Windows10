#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	int i,n,m,count =0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> m;
		v.push_back(m);
	}
	int index;
	cin >> index;
	for (i = 0; i < n; i++)
	{
		if (v[i] == index)
		{
			cout << i + 1;
			count++;
			break;
		}
	}
	if (count == 0)
	{
		cout << -1;
	}
	system("pause");
}