#include<iostream>
using namespace std;

#define N 10000//ɸ������1�����ڵ��������� 
int p[N];
int main()
{
	int i, j, a, b, t;
	for (i = 2; i<N / 2; i++)
	{
		if (p[i]) continue;//�������μ�ɸ�� 
		for (j = 2 * i; j <= N; j += i)
		{
			p[j] = 1;
		}
	}
	cin >> a >> b;
	for (i = a; i <= b; i++)
	{
		t = i;
		printf("%d=", t);
		while (t)
		{
			for (j = 2; j*j <= t; j++)
			{
				if (!p[j] && !(t%j))
				{
					printf("%d*", j);
					t /= j;
					break;
				}
			}
			if (j*j>t)
			{
				printf("%d", t);
				break;
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}