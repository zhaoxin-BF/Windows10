#include<stdio.h>
#include<iostream>

int main()//��������ӡ�������
{
	int rows, i, j;
	long long coef = 1;
	scanf_s("%d", &rows);
	//��������
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j <= i; j++)//��n�е�������n�����j<=i
		{
			//��һ��Ϊ1����һ��Ϊ1
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef*(i - j + 1) / j;//���һ��ÿһ��i=j,�����ڶ��У�coef=j������������
			printf("%d ", coef);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
