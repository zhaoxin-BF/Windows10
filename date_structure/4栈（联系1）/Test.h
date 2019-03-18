#ifndef __Test_h_
#define __Test_h_

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef int Datatype;
typedef struct Stack
{
	Datatype* _array;
	int _capacity;
	int _top;
}Stack;

void InitStack(Stack* s);
void PushBackStack(Stack* s,Datatype data);
void PopBackStack(Stack* s);
void Checkcapacity(Stack* s);
int SizeStack(Stack* s);
void PrintStack(Stack s);

#endif
void InitStack(Stack* s)
{
	s->_array = (Datatype*)malloc(3 * sizeof(Datatype));
	s->_capacity = 3;
	s->_top = -1;
}

void PushBackStack(Stack* s, Datatype data)
{
	s->_top++;
	if (s->_top == s->_capacity)
		Checkcapacity(&s);

	s->_array[s->_top] = data;
}

void PopBackStack(Stack* s)
{
	s->_top--;
}

void Checkcapacity(Stack* s)
{
	if (s->_top + 1 == s->_capacity)
	{
		int Newcapacity = s->_capacity * 2;
		Datatype* tmp = (Datatype*)malloc(Newcapacity*sizeof(Datatype));
		if (tmp == NULL)
			return;

		memcpy(tmp,s->_array,s->_capacity*sizeof(Datatype));

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
	for (i = s._top; i >=0; i--)
	{
		printf("%d\n", s._array[i]);
	}
}