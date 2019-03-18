#ifndef __Heap_h_
#define __Heap_h_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int _HPDataType;

typedef struct Heap
{
	_HPDataType* _array;
	int _size;
	int _capacity;
}Heap;

void Swap(_HPDataType* x, _HPDataType* y);
void AdjustDown(_HPDataType* a,int n,int root);
void AdjustUp(_HPDataType* a,int n,int child);

void InitHeap(Heap* hp,_HPDataType* a,int n);
void DestoryHeap(Heap* hp);

void PushHeap(Heap* hp,_HPDataType x);
void PopHeap(Heap* hp);

_HPDataType TopHeap(Heap* hp);

int SizeHeap(Heap* hp);
int isEmptyHeap(Heap* hp);

void SortHeap(Heap* hp);

#endif

void Swap(_HPDataType* x, _HPDataType* y)
{
	_HPDataType tmp = *x;
	 *x = *y;
	 *y = tmp;
}

void AdjustDown(_HPDataType* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	assert(a);
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(_HPDataType * a, int n, int child)
{
	int parent = (child - 1) / 2;
	assert(a);
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void InitHeap(Heap* hp, _HPDataType* a, int n)
{
	int i;
	assert(hp && a);
	hp->_array = (_HPDataType*)malloc(sizeof(_HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	for (i = 0; i < n; i++)
	{
		hp->_array[i] = a[i];
	}
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_array,hp->_size,i);
	}

	//for (i = n-1; i >= 0; i--)
	//{
	//	AdjustUp(hp->_array,hp->_size,i);
	//}
}

void DestoryHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_capacity = 0;
	hp->_size = 0;
}

void PrintfHeap(Heap* hp)
{
	int i;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ",hp->_array[i]);
	}
	printf("\n");
}

void PushHeap(Heap* hp, _HPDataType x)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		hp->_array = (_HPDataType*)realloc(hp->_array, sizeof(_HPDataType)*hp->_capacity * 2);
		hp->_capacity *= 2;
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_array, hp->_size, hp->_size - 1);
}
void PopHeap(Heap* hp)
{
	assert(hp);
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size -= 1;
	AdjustDown(hp->_array, hp->_size, 0);
}

_HPDataType TopHeap(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int isEmptyHeap(Heap* hp)
{
	if (hp->_size == 0)
		return 0;
	return 1;
}

void SortHeap(Heap* hp)
{
	assert(hp);

	int i;
	for (i = 1; i < hp->_size;i++)
	{
		Swap(&hp->_array[0], &hp->_array[hp->_size - i]);
		AdjustDown(hp->_array,hp->_size-i,0);
	}
}