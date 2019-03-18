#ifndef __Stack_h_
#define __Stack_h_

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
void NewCapacity(Stack* s);
void PushStack(Stack* s, DataType data);
void PopStack(Stack* s);
int TopStack(Stack* s);
void PrintStack(Stack* s);

#endif

void InitStack(Stack* s)
{
	s->_array = (DataType*)malloc(3 * sizeof(DataType));
	s->_Capacity = 3;
	s->_top = -1;
}

void NewCapacity(Stack* s)
{
	int newcapacity = s->_Capacity * 2;
	DataType* pTmp = (DataType*)malloc(newcapacity*sizeof(DataType));

	memcpy(pTmp, s->_array, s->_Capacity*(sizeof(DataType)));
	free(s->_array);

	s->_array = pTmp;
	s->_Capacity = newcapacity;
}

void PushStack(Stack* s,DataType data)
{
	s->_top++;
	if (s->_top < s->_Capacity)
		s->_array[(s->_top)] = data;
	else
	{
		NewCapacity(s);
		s->_array[(s->_top)] = data;
	}
}


void PopStack(Stack* s)
{
	s->_top--;
}

int TopStack(Stack* s)
{
	return s->_top;
}

void PrintStack(Stack* s)
{
	int i;
	for (i = 0; i <= s->_top; i++)
	{
		printf("%d ",s->_array[i]);
	}
	printf("\n");
}



















//#ifndef __STACK_h_
//#define __STACK_h_
//
//#include<stdio.h>
//
//typedef int DataType;
//#define Stack_Size 50
//
//
//typedef struct Stack
//{
//	DataType _array[Stack_Size];
//	int _top;
//}Stack;
//
//void InitStack(Stack* s);
//void PushStack(Stack* s, DataType data);
//void PopStack(Stack* s);
//int TopStack(Stack* s);
//void PrintStack(Stack* s);
//
//
//#endif
//
//void InitStack(Stack* s)
//{
//	s->_top = -1;
//}
//
////ÈëÕ»
//void PushStack(Stack* s, DataType data)
//{
//	s->_top++;
//	s->_array[s->_top] = data;
//}
//
//void PopStack(Stack* s)
//{
//	printf("%d \n", s->_array[s->_top]);
//	s->_top--;
//}
//
//int TopStack(Stack* s)
//{
//	return s->_top;
//}
//
//void PrintStack(Stack* s)
//{
//	int i;
//	for (i = 0; i <= s->_top; i++)
//	{
//		printf("%d ", s->_array[i]);
//	}
//	printf("\n");
//}
//
//#include"Stack.h"
//
//int main()
//{
//	Stack s;
//	InitStack(&s);
//	PushStack(&s, 1);
//	PushStack(&s, 2);
//	PushStack(&s, 3);
//	PushStack(&s, 4);
//	PushStack(&s, 5);
//
//	PopStack(&s);
//	printf("top = %d\n", TopStack(&s));
//
//	PrintStack(&s);
//	getchar();
//	return 0;
//}
