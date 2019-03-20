#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	vector<int> v;
	int i,n;
	for (i = 0;; i++)
	{
		cin >> n;
		if (n == 0)
			break;
		v.push_back(n);
	}
	sort(v.begin(), v.end(),cmp);
	cout << v[1]<<endl;
	system("pause");
	return 0;
}