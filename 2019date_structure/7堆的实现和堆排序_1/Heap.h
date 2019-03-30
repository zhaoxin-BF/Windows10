#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int _HPDataType;

typedef struct Heap
{
	_HPDataType* _array;
	int _size;
	int _capacity;
}Heap;

void Swap(_HPDataType* x, _HPDataType* y);
void AdjustDown(_HPDataType* a, int n, int root);

void InitHeap(Heap* hp, _HPDataType* a, int n);

#endif

void Swap(_HPDataType* x, _HPDataType* y)
{
	*x = *x - *y;
	*y = *x + *y;
	*x = *y - *x;
}

void AdjustDown(_HPDataType* a, int n, int root)

{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(_HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	assert(a);
	while (child>0 && child < n)
	{
		if (a[child] < a[child - 1])
		{
			child--;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = (parent + 1) * 2;
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
	//for (i = (n - 2) / 2; i >= 0; i--)
	//{
	//	AdjustDown(hp->_array, hp->_size, i);
	//}
	for (i = n - 1; i >= 0; i--)
	{
		AdjustUp(hp->_array, hp->_size, i);
	}
}


void SortHeap(Heap* hp)
{
	int size = hp->_size;
	while (size>0)
	{
		size--;
		Swap(&hp->_array[0], &hp->_array[size]);
		if (size == 1)
			break;
		AdjustDown(hp->_array, size, 0);
	}
}

void Print(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}