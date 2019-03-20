#include<stdio.h>
#include<iostream>

int main()//按行数打印杨辉三角
{
	int rows, i, j;
	long long coef = 1;
	scanf_s("%d", &rows);
	//控制行数
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j <= i; j++)//第n行的数字有n项，所以j<=i
		{
			//第一行为1，第一列为1
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef*(i - j + 1) / j;//最后一个每一行i=j,倒数第二行（coef=j）等于列数，
			printf("%d ", coef);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
