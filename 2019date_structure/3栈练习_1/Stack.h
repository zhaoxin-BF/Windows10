#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	int _top;
	int _Capacity;
}Stack;

void InitStack(Stack* s);
void PushStack(Stack* s,DataType data);
void PopStack(Stack* s);
void NewCapacity(Stack* s);
int TopStack(Stack* s);
void PrintStack(Stack* s);

#endif

void InitStack(Stack* s)
{
	s->_array = (DataType*)malloc(sizeof(DataType)* 3);
	s->_Capacity = 3;
	s->_top = -1;
}

void PushStack(Stack* s, DataType data)
{
	s->_top++;
	if (s->_top < s->_Capacity)
	{
		s->_array[s->_top] = data;
	}
	else
	{
		NewCapacity(s);
		s->_array[s->_top] = data;
	}
}

void PopStack(Stack* s)
{
	if (s->_top > -1)
	{
		s->_top--;
	}
}

void NewCapacity(Stack* s)
{
	int newCapacity = s->_Capacity * 2;
	DataType Newarray = (DataType*)malloc(sizeof(DataType)*newCapacity);

	memcpy(Newarray,s->_array,sizeof(DataType)*s->_Capacity);
	free(s->_array);

	s->_array = Newarray;
	s->_Capacity = newCapacity;
}


int TopStack(Stack* s)
{
	return s->_array[s->_top];
}


void PrintStack(Stack* s)
{
	while (s->_top > -1)
	{
		printf("%d ", s->_array[s->_top--]);
	}
	printf("\n");
}