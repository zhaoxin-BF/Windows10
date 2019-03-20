#include<iostream>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long sum = n + n*(n - 1) / 2.0;
	printf("%I64d",sum);
	system("pause");
}