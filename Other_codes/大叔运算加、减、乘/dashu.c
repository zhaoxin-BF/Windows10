#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//最大数长度
#define MAX 200

void init(int *a);	//读入输入的大整数,a[0]存储大整数的长度
void deal_arry(int *arry);//对数组进位整理
void add(int *a, int *b, int *c);//加法（打印）
int compare(int *a, int *b);//比较两个数组表示的整数的大小,a>b返回1，否则返回0，2表示相同
void subABigerB(int *a, int *b, int *c);//减法（A比B大）
void sub(int *a, int *b, int *c);//减法（打印）通过比较A,B传到subAbigerB做减法
void mul(int *a, int *b);//乘法（打印）
void menu();//菜单
void yunsuan();//运算开始



//读入输入的大整数,a[0]存储大整数的长度
void init(int *a)
{
	unsigned int i, len;
	char s[MAX];
	scanf("%s", &s);
	a[0] = strlen(s);

	for (i = 0; i<a[0]; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			a[a[0] - i] = s[i] - '0';
		else
		{
			printf("输入出错!");
			exit(0);
		}
	}
}

//对数组进位整理
void deal_arry(int *arry)
{
	int i, j, k, tmp;
	for (k = 1; k < arry[0]; k++)
	{
		if (arry[k]>9)
		{
			tmp = arry[k] / 10;
			arry[k] = arry[k] % 10;
			arry[k + 1] += tmp;
		}
	}
}

//加法（打印）
void add(int *a, int *b, int *c)
{
	int k = 0, i;

	c[0] = a[0];
	if (b[0] > c[0])
		c[0] = b[0];
	for (i = 1; i <= c[0]; i++)
	{
		c[i] = a[i] + b[i];
	}
	if (c[i] > 9)
	{
		c[0]++;
	}
	deal_arry(c);
	//打印
	for (i = c[0]; i>0; i--)
	{
		printf("%d", c[i]);
	}
}

//比较两个数组表示的整数的大小,a>b返回1，否则返回0
int compare(int *a, int *b)
{
	int i = 0;
	if (a[0] > b[0])
		return 1;
	if (a[0] == b[0])
	{
		for (i = 0; i<a[0]; i++)
		{
			if (a[a[0] - i] > b[b[0] - i])
				return 1;
			if (a[a[0] - i] < b[b[0] - i])
				return 0;
		}
		if (i == a[0])
			return 2;
	}
	return 0;
}


//减法（A比B大）
void subABigerB(int *a, int *b, int *c)
{
	int i, j;
	int count = 1;
	for (i = 1; i < a[0] + 1; i++)
	{
		if (a[i] >= b[i])
		{
			c[i] = a[i] - b[i];
		}
		else
		{
			while (a[i + 1] == 0)
			{
				i++;
				count++;
			}

			a[i + 1]--;
			for (j = 1; j < count; j++)
			{
				i = (i + 1 - j);
				a[i] = 9;
			}
			i = i - 1;
			c[i] = a[i] + 10 - b[i];
		}
	}
	c[0] = a[0];
}

//减法（打印）通过比较A,B传到subAbigerB做减法
void sub(int *a, int *b, int *c)
{
	int i;
	for (i = 0; i<MAX; i++)
	{
		c[i] = 0;
	}
	if (compare(a, b) == 1)
	{
		subABigerB(a, b, c);

		//打印
		i = c[0];
		while (c[i] == 0)
			i--;
		for (; i>0; i--)
		{
			printf("%d", c[i]);
		}
	}
	else if (compare(a, b) == 0)
	{
		subABigerB(b, a, c);

		//打印
		i = c[0];
		while (c[i] == 0)
			i--;
		printf("-");
		for (; i>0; i--)
		{
			printf("%d", c[i]);
		}
	}
	else if (compare(a, b) == 2)
		//打印
		printf(" 0 ");
}

//乘法（打印）
void mul(int *a, int *b)
{
	int k = 0, i, c[MAX], max_len;
	int f = 0, j;
	int tmp;

	memset(c, 0, sizeof(c));

	for (i = 0; i < a[0]; i++)
	{
		for (j = 0; j < b[0]; j++)
		{
			c[i + j + 1] += a[i + 1] * b[j + 1];
		}
	}

	c[0] = i + j + 1;
	deal_arry(c);

	while (c[c[0]] == 0)
	{
		c[0]--;
	}

	//打印
	for (i = c[0]; i>0; i--)
	{
		printf("%d", c[i]);
	}
}

//菜单
void menu()
{
	printf("--------------------------------\n");
	printf("    欢 迎 来 到 大 数 运 算！   \n");
	printf("   当前仅支持加法、减法、乘法！ \n");
}


//运算开始
void yunsuan()
{
	int a[MAX], b[MAX], c[MAX];
	//清零
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	printf("请输入 a ：");
	init(a);
	printf("请输入 b ：");
	init(b);
	printf("\n");

	//加法
	printf("   a + b = ");
	add(a, b, c);
	printf("\n\n");

	//乘法
	printf("   a X b = ");
	mul(a, b);
	printf("\n\n");

	//减法
	printf("   a - b =");
	sub(a, b, c);
	printf("\n\n");


}

int main()
{
	int i, x;
	menu();
	do
	{
		printf("--------------------------------\n");
		printf("    是  否  进  行  运  算？    \n");
		printf("       1.YES        2.NO        \n");
		printf("--------------------------------\n");
		scanf("%d", &x);
		if (x == 1)
		{
			yunsuan();
		}
		else
		{
			if (x == 2)
			{
				exit(1);
			}
		}
	} while (1);

	system("pause");
	return 0;
}