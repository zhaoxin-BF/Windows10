//求10的阶乘
//#include"stdio.h"
//int main()
//{
//	int n;
//	n = jiechen(10);//调用函数jiechen求10的阶乘，并将结果返回给n;
//	printf("%d",n);
//	getchar();
//	getchar();
//}
//
//int jiechen(int n)//函数
//{
//	if (n > 1)
//	{
//		n = n * jiechen(n-1);
//	}
//	else n = 1;
//	return n;
//}

//100以内的素数
//#include"stdio.h"
//main()
//{
//	int i,j,count=0;
//	for (i = 2; i <= 100; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			if (i%j == 0)
//				count++;
//			if (count>1)
//				break;
//		}
//		if (count == 1)
//			printf("%d ",i);
//		count = 0;
//	}
//	system("pause");
//}

//对10个数进行排序
#include"stdio.h"
void main()
{
	printf("请输入10个整数");
	int a[10] = { 0 };
	int i,j,min,tmp;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d",&a[i]);
	}
	for (i = 0; i <= 8; i++)
	{
		min = i;
		for (j = i + 1; j <= 9; j++)
		{
			if (a[j]<a[min])
				min = j;
		}
		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
	system("pause");
}

//转置矩阵
//#include"stdio.h"
//void main()
//{
//	int a[4][4] = { 0 };
//	int b[4][4] = { 0 };
//	int i, j;
//	printf("请输入一个4*4的整数矩阵：\n");
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf_s("%d",&a[i][j]);
//		}
//	}
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			b[j][i] = a[i][j];
//		}
//	}
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ",b[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//}

////打印杨辉三角
//#include<stdio.h>
//int main()
//{
//	printYangHui();//
//	return 0;
//}
//int printYangHui()//按行数打印杨辉三角
//{
//	int rows, coef = 1, space, i, j;
//	printf("行数: ");
//	scanf_s("%d", &rows);
//
//	//控制行数
//	for (i = 0; i<rows; i++)
//	{
//		//打印空格
//		for (space = 1; space <= rows - i; space++)
//			printf("  ");
//		//
//		for (j = 0; j <= i; j++)//第n行的数字有n项，所以j<=i
//		{
//			//第一行为1，第一列为1
//			if (j == 0 || i == 0)
//				coef = 1;
//			else
//				coef = coef*(i - j + 1) / j;//最后一个每一行i=j,倒数第二行（coef=j）等于列数，
//			printf("%4d", coef);
//		}
//		printf("\n");
//	}
//	system("pause");
//}

//求字符串长度
//#include<string.h>
//void main()
//{
//	char a[100];
//	int i = 0;
//	printf("input string\n");
//	gets(a);
//	while (a[i] != '\0')
//		i++;
//	printf("你输入的字符串的长度为%d\n", i);
//	system("pause");
//}

//求一维数组最大值和其下标
//#include"stdio.h"
//void main()
//{
//	int a[] = { 1, 4, 7, 4, 8, 5, 2, 9, 1000 };//一共9个数，最大值为1000，其下标为8
//	int i, max;
//	max = 0;
//	for (i = 1; i < 9; i++)
//	{
//		if (a[max] < a[i])
//			max = i;
//	}
//	printf("最大值 = %d\n下标为 = %d\n", a[max], max);
//	system("pause");
//}

//递归反序输出字符串
//#include"stdio.h"
//void ret(char *str)
//{
//	if (*str != '\0')
//	{
//		ret(str + 1);
//	}
//
//	printf("%c ", *str);
//}
//int main()
//{
//	char a[20];
//	scanf_s("%s",a,20);
//	ret(a);
//	printf("\n运行成功！\n");
//	system("pause");
//}


