//��10�Ľ׳�
//#include"stdio.h"
//int main()
//{
//	int n;
//	n = jiechen(10);//���ú���jiechen��10�Ľ׳ˣ�����������ظ�n;
//	printf("%d",n);
//	getchar();
//	getchar();
//}
//
//int jiechen(int n)//����
//{
//	if (n > 1)
//	{
//		n = n * jiechen(n-1);
//	}
//	else n = 1;
//	return n;
//}

//100���ڵ�����
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

//��10������������
#include"stdio.h"
void main()
{
	printf("������10������");
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

//ת�þ���
//#include"stdio.h"
//void main()
//{
//	int a[4][4] = { 0 };
//	int b[4][4] = { 0 };
//	int i, j;
//	printf("������һ��4*4����������\n");
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

////��ӡ�������
//#include<stdio.h>
//int main()
//{
//	printYangHui();//
//	return 0;
//}
//int printYangHui()//��������ӡ�������
//{
//	int rows, coef = 1, space, i, j;
//	printf("����: ");
//	scanf_s("%d", &rows);
//
//	//��������
//	for (i = 0; i<rows; i++)
//	{
//		//��ӡ�ո�
//		for (space = 1; space <= rows - i; space++)
//			printf("  ");
//		//
//		for (j = 0; j <= i; j++)//��n�е�������n�����j<=i
//		{
//			//��һ��Ϊ1����һ��Ϊ1
//			if (j == 0 || i == 0)
//				coef = 1;
//			else
//				coef = coef*(i - j + 1) / j;//���һ��ÿһ��i=j,�����ڶ��У�coef=j������������
//			printf("%4d", coef);
//		}
//		printf("\n");
//	}
//	system("pause");
//}

//���ַ�������
//#include<string.h>
//void main()
//{
//	char a[100];
//	int i = 0;
//	printf("input string\n");
//	gets(a);
//	while (a[i] != '\0')
//		i++;
//	printf("��������ַ����ĳ���Ϊ%d\n", i);
//	system("pause");
//}

//��һά�������ֵ�����±�
//#include"stdio.h"
//void main()
//{
//	int a[] = { 1, 4, 7, 4, 8, 5, 2, 9, 1000 };//һ��9���������ֵΪ1000�����±�Ϊ8
//	int i, max;
//	max = 0;
//	for (i = 1; i < 9; i++)
//	{
//		if (a[max] < a[i])
//			max = i;
//	}
//	printf("���ֵ = %d\n�±�Ϊ = %d\n", a[max], max);
//	system("pause");
//}

//�ݹ鷴������ַ���
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
//	printf("\n���гɹ���\n");
//	system("pause");
//}


