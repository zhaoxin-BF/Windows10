#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> v;
	string s;
	int size = 0;
	for (;;)
	{
		cin >> s;
		v.push_back(s);
		size++;
		if (getchar() == '\n')
			break;
	}
	for (; size - 1 >= 0; size--)
	{
		cout << v[size - 1] << " ";
	}
}