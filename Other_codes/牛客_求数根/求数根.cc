///ÇóÊı¸ù

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int a = 0;
		string::iterator it = s.begin();
		while (it != s.end())
		{
			a += (int)(*it - '0');
			it++;
		}
		int r, z;
		int sum = a;
		cout << sum << endl;
		while (sum>9)
		{
			z = sum;
			a = 0;
			while (z)
			{
				r = z % 10;
				z = z / 10;
				a = a + r;
			}
			sum = a;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}