#ifndef __StackByTwoQueue_h_
#define __StackByTwoQueue_h_

#include"Queue.h"

typedef struct Stack
{
	Queue _q1;
	Queue _q2;
}Stack;

void StackByTwoQueueInit(Stack* stq);
void StackByTwoQueuPush(Stack* stq,DataType data);
void StackByTwoQueuePop(Stack* stq);

DataType StackByTwoQueueTop(Stack* stq);
DataType StackByTwoQueueBack(Stack* stq);
DataType SizeStack(Stack* stq);

void PrintStackByTwoQueueBack(Stack* stq);


#endif

void StackByTwoQueueInit(Stack* stq)
{
	QueueInit(&stq->_q1);
	QueueInit(&stq->_q2);
}

void StackByTwoQueuPush(Stack* stq, DataType data)
{
	assert(stq);
	if (QueueEmpty(&stq->_q1) && QueueEmpty(&stq->_q2))
		QueuePush(&stq->_q1,data);
	else
	{
		if (QueueEmpty(&stq->_q1))
		{
			QueuePush(&stq->_q2, data);
		}
		else
			QueuePush(&stq->_q1, data);
	}
}
void StackByTwoQueuePop(Stack* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->_q1))
	{
		while (QueueSize(&stq->_q2) != 1)
		{
			QueuePush(&stq->_q1, QueueFront(&stq->_q2));
			QueuePop(&stq->_q2);
		}
		QueuePop(&stq->_q2);
	}
	else
	{
		while (QueueSize(&stq->_q1) != 1)
		{
			QueuePush(&stq->_q2, QueueFront(&stq->_q1));
			QueuePop(&stq->_q1);
		}
		QueuePop(&stq->_q1);
	}
}

DataType StackByTwoQueueTop(Stack* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->_q1))
		return QueueBack(&stq->_q2);
	return QueueBack(&stq->_q1);
}

DataType StackByTwoQueueBack(Stack* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->_q1))
		return QueueFront(&stq->_q2);
	return QueueFront(&stq->_q1);
}
DataType SizeStack(Stack* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->_q1))
		return QueueSize(&stq->_q2);
	return QueueSize(&stq->_q1);
}

void PrintStackByTwoQueueBack(Stack* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->_q1))
		PrintQueue(&stq->_q2);
	else
		PrintQueue(&stq->_q1);
}