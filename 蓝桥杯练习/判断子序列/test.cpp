
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, i, shuzhi;
	cin >> num;
	vector<int> v;

	for (i = 0; i < num; i++)
	{
		cin >> shuzhi;
		v.push_back(shuzhi);
	}
	cout << "ÊäÈëÍê±Ï£¡" << endl;
	int size = 0,k =1;
	for (i = 0; i+2 < num; i++)
	{
		if ((v[i]<v[i + 1] && v[i + 1]>v[i + 2]) || (v[i] > v[i + 1] && v[i + 1] < v[i + 2]))
		{
			size++;
			i++;
		}
	}
	cout << size+1;
	system("pause");
	return 0;
}