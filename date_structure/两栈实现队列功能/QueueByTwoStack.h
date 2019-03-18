#ifndef __QueueByTwoStack_h_
#define __QueueByTwoStack_h_

#include"Stack.h"
#include<assert.h>

typedef struct Queue
{
	Stack _t1;
	Stack _t2;
}Queue;

void QueueByTwoStackInit(Queue* q);
void QueueByTwoStackPush(Queue* q, TypeData data);
void QueueByTwoStackPop(Queue* q);
TypeData QueueByTwoStackFront(Queue* q);
TypeData QueueByTwoStackBack(Queue* q);
int QueueByTwoStackSize(Queue* q);
void PrintQueueByTwoStack(Queue* q);

#endif

void QueueByTwoStackInit(Queue* q)
{
	InitStack(&q->_t1);
	InitStack(&q->_t2);
}

void QueueByTwoStackPush(Queue* q, TypeData data)
{
	PushbackStack(&q->_t1, data);
}

void QueueByTwoStackPop(Queue* q)
{
	assert(q);
	if (!StackEmpty(&q->_t2))
	{
		while (StackEmpty(&q->_t1))
		{
			PushbackStack(&q->_t2, StackTop(&q->_t1));
			PopbackStack(&q->_t1);
		}
	}

	PopbackStack(&q->_t2);

}
TypeData QueueByTwoStackFront(Queue* q)
{
	if (!StackEmpty(&q->_t2))
	{
		while (StackEmpty(&q->_t1))
		{
			PushbackStack(&q->_t2, StackTop(&q->_t1));
			PopbackStack(&q->_t1);
		}
	}
	return StackTop(&q->_t2);
}
TypeData QueueByTwoStackBack(Queue* q)
{
	if (StackEmpty(&q->_t1))
		return StackTop(&q->_t1);
	else
		return StackBack(&q->_t2);
}
int QueueByTwoStackSize(Queue* q)
{
	return SizeStack(&q->_t1) + SizeStack(&q->_t2);
 }
void PrintQueueByTwoStack(Queue* q)
{

		PrintStack(q->_t2);

		if (StackEmpty(&q->_t1))
		{
			StackDestory(&q->_t2);
			while (StackEmpty(&q->_t1))
			{
				PushbackStack(&q->_t2, StackTop(&q->_t1));
				PopbackStack(&q->_t1);
			}
			PrintStack(q->_t2);
		}
		printf("\n");
}