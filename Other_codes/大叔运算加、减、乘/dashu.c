#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//���������
#define MAX 200

void init(int *a);	//��������Ĵ�����,a[0]�洢�������ĳ���
void deal_arry(int *arry);//�������λ����
void add(int *a, int *b, int *c);//�ӷ�����ӡ��
int compare(int *a, int *b);//�Ƚ����������ʾ�������Ĵ�С,a>b����1�����򷵻�0��2��ʾ��ͬ
void subABigerB(int *a, int *b, int *c);//������A��B��
void sub(int *a, int *b, int *c);//��������ӡ��ͨ���Ƚ�A,B����subAbigerB������
void mul(int *a, int *b);//�˷�����ӡ��
void menu();//�˵�
void yunsuan();//���㿪ʼ



//��������Ĵ�����,a[0]�洢�������ĳ���
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
			printf("�������!");
			exit(0);
		}
	}
}

//�������λ����
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

//�ӷ�����ӡ��
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
	//��ӡ
	for (i = c[0]; i>0; i--)
	{
		printf("%d", c[i]);
	}
}

//�Ƚ����������ʾ�������Ĵ�С,a>b����1�����򷵻�0
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


//������A��B��
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

//��������ӡ��ͨ���Ƚ�A,B����subAbigerB������
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

		//��ӡ
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

		//��ӡ
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
		//��ӡ
		printf(" 0 ");
}

//�˷�����ӡ��
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

	//��ӡ
	for (i = c[0]; i>0; i--)
	{
		printf("%d", c[i]);
	}
}

//�˵�
void menu()
{
	printf("--------------------------------\n");
	printf("    �� ӭ �� �� �� �� �� �㣡   \n");
	printf("   ��ǰ��֧�ּӷ����������˷��� \n");
}


//���㿪ʼ
void yunsuan()
{
	int a[MAX], b[MAX], c[MAX];
	//����
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	printf("������ a ��");
	init(a);
	printf("������ b ��");
	init(b);
	printf("\n");

	//�ӷ�
	printf("   a + b = ");
	add(a, b, c);
	printf("\n\n");

	//�˷�
	printf("   a X b = ");
	mul(a, b);
	printf("\n\n");

	//����
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
		printf("    ��  ��  ��  ��  ��  �㣿    \n");
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