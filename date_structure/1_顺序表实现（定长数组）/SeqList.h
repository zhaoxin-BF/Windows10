#ifndef __SeqList_h_
#define __SeqList_h_

#include<stdio.h>

typedef int DataType;
#define MAX_SIZE 1000

typedef struct SeqList
{
	int _size;
	DataType _array[MAX_SIZE];
}SeqList,*PSeqList;


void InitSeqList(PSeqList ps);                         //初始化顺序表
void PushBackSeqList(PSeqList ps, DataType data);      //尾插顺序表
void PopBackSeqList(PSeqList ps);                      //尾删顺序表
void PrintSeqList(PSeqList ps);                        //打印顺序表
void PushFrontSeqList(PSeqList ps,DataType data);      //头插顺序表
void PopFrontSeqList(PSeqList ps);                     //头删顺序表
void InsertSeqList(PSeqList ps,DataType data,int size);//任意位置插入元素
void EarseSeqList(PSeqList ps,int size);               //任意位置删除元素
int SizeSeqList(PSeqList ps);                          //取顺序表元素个数
void ClearSeqList(PSeqList ps);                        //清空顺序表元素
void RemoveAllSeqList(PSeqList ps, DataType data);     //移除所有某元素
int EmptySeqList(PSeqList ps);                         //判空顺序表

#endif

void InitSeqList(PSeqList ps)
{
	if (ps == NULL)
		return;

	ps->_size = 0;
}

void PushBackSeqList(PSeqList ps, DataType data)
{
	if (ps == NULL)
		return;

	ps->_array[ps->_size] = data;
	ps->_size++;
}

void PopBackSeqList(PSeqList ps)
{
	ps->_size--;
}


void PrintSeqList(PSeqList ps)                        //打印顺序表
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ",ps->_array[i]);
	}

	if (ps->_size == 0)
		printf("顺序表内无元素！");

	printf("\n");
}


void PushFrontSeqList(PSeqList ps, DataType data)      //头插顺序表
{
	if (EmptySeqList(ps))
	{
		for (int i = ps->_size; i > 0; i--)
		{
			ps->_array[i] = ps->_array[i - 1];
		}
	}
	ps->_array[0] = data;
	ps->_size++;
}


void PopFrontSeqList(PSeqList ps)                     //头删顺序表
{
	if (ps->_size <= 1)
		ps->_size = 0;
	else
	{
		for (int i = 0; i < ps->_size-1; i++)
		{
			ps->_array[i] = ps->_array[i + 1];
		}
		ps->_size--;
	}
}


void InsertSeqList(PSeqList ps, DataType data, int size)//任意位置插入元素
{
	if (size == ps->_size+1)
		ps->_array[size-1] = data;
	else
	{
		for (int i = ps->_size; i >= size; i--)
		{
			ps->_array[i] = ps->_array[i - 1];
		}
	}
	ps->_array[size-1] = data;
	ps->_size++;
}


void EarseSeqList(PSeqList ps, int size)               //任意位置删除元素
{
	if (size <= ps->_size&& size >= 1)
	{
		for (int i = size - 1; i < ps->_size - 1; i++)
			ps->_array[i] = ps->_array[i + 1];
		ps->_size--;
	}
}


int SizeSeqList(PSeqList ps)                          //取顺序表元素个数
{
	return ps->_size;
}


void ClearSeqList(PSeqList ps)                        //清空顺序表元素
{
	ps->_size = 0;
}


void RemoveAllSeqList(PSeqList ps, DataType data)     //移除所有某元素
{
	int count = 0;
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
			count++;
		else
			ps->_array[i - count] = ps->_array[i];
	}
	ps->_size = ps->_size - count;

}


int EmptySeqList(PSeqList ps)                         //判空顺序表
{
	if (ps->_size == 0)
		return 0;

	return 1;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(PSeqList ps)
{
	int size = ps->_size;
	int i,j;

	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-1-i; j++)
		{
			if (ps->_array[j] < ps->_array[j + 1])
			{
				swap(&(ps->_array[j]), &(ps->_array[j + 1]));
			}
		}
	}
}

void SelectSort(PSeqList ps)
{
	int size = ps->_size;
	int min = 0;
	int i=0,j,n;

	for (; i < size--;i++)
	{
		for (j = 1; j < size+1; j++)
		{
			if (ps->_array[min] < ps->_array[j])
				min = j;
		}
		i = 0;
		j--;
		if (min != j)
			swap(&(ps->_array[min]),&(ps->_array[j]));
		min = 0;
	}
}