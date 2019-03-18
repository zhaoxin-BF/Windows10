#include<iostream>

using namespace std;



void hannuo(int n, char src, char dst, char mid)
{
	if (n == 1)
		cout << src << "->" << dst << endl;
	else
	{
		hannuo(n-1,src,mid,dst);
		cout << src << "->" << dst << endl;
		hannuo(n-1,mid,dst,src);
	}
}
int main()
{
	hannuo(2, 'A', 'C', 'B');
	system("pause");
	return 0;
}