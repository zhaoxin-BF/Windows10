#ifndef __Stack_h_
#define __Stack_h_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

typedef int TypeData;
typedef struct Stack
{
	TypeData* _array;
	int _top;
	int _capacity;
}Stack;

void InitStack(Stack* s);
void PushbackStack(Stack* s, TypeData data);
void PopbackStack(Stack* s);
TypeData StackTop(Stack* s);
TypeData StackBack(Stack* s);
void Checkcapacity(Stack* s);
int SizeStack(Stack* s);
void PrintStack(Stack s);
int StackEmpty(Stack* s);
void StackDestory(Stack* s);


#endif

void InitStack(Stack* s)
{
	s->_array = (TypeData*)malloc(3 * sizeof(TypeData));
	s->_capacity = 3;
	s->_top = -1;
}

void PushbackStack(Stack* s, TypeData data)
{
	s->_top++;
	if (s->_top == s->_capacity - 1)
		Checkcapacity(s);

	s->_array[s->_top] = data;
}

void PopbackStack(Stack* s)
{
	s->_top--;
}

// »ñÈ¡Õ»¶¥ÔªËØ
TypeData StackTop(Stack* s)
{
	assert(StackEmpty(s));
	return s->_array[s->_top];
}

TypeData StackBack(Stack* s)
{
	assert(StackEmpty(s));
	return s->_array[0];
}
void Checkcapacity(Stack* s)
{
	if (s->_top == s->_capacity - 1)
	{
		int Newcapacity = s->_capacity * 2;
		TypeData* tmp = (TypeData*)malloc(Newcapacity*sizeof(TypeData));
		if (tmp == NULL)
			return;

		memcpy(tmp, s->_array, s->_capacity*sizeof(TypeData));

		s->_array = tmp;
		s->_capacity = Newcapacity;
	}
}

int SizeStack(Stack* s)
{
	return s->_top + 1;
}

void PrintStack(Stack s)
{
	int i;
	for (i = s._top; i >= 0; i--)
	{
		printf("%d ", s._array[i]);
		s._top--;
	}
}

int StackEmpty(Stack* s)
{
	if (s->_top == -1)
		return 0;
	else
		return 1;
}

void StackDestory(Stack* s)
{
	s->_top = -1;
}