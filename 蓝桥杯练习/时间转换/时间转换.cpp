#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	int s, h, m;
	s = t % 60;
	m = t / 60;
	h = m / 60;
	m = m % 60;
	cout << h << ":" << m << ":" << s << endl;
	system("pause");
	return 0;
}