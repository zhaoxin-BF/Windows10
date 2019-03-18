#ifndef __Queue_h_
#define __Queue_h_

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct Node
{
	DataType _data;
	struct Node* _pNext;
}Node,*PNode;


typedef struct Queue
{
	PNode _pHead;
	PNode _pTail;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q,DataType data);
void QueuePop(Queue* q);

DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);

int QueueSize(Queue* q);
int QueueEmpty(Queue* q);

PNode BuyNode(DataType data);
void PrintQueue(Queue* q);

#endif

void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = q->_pTail = NULL;
}
void QueuePush(Queue* q, DataType data)
{
	assert(q);
	if (NULL == q->_pHead)
	{
		q->_pHead = q->_pTail = BuyNode(data);
	}
	else
	{
		q->_pTail->_pNext = BuyNode(data);
		q->_pTail = q->_pTail->_pNext;
	} 
}
void QueuePop(Queue* q)
{
	PNode pDelNode = q->_pHead;
	if (pDelNode)
	{
		q->_pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}

DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_pHead->_data;
}

DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_pTail->_data;
}

int QueueSize(Queue* q)
{
	int count = 0;
	PNode pCur = q->_pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	if (q->_pHead == NULL)
		return 0;
	return 1;
}

PNode BuyNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;

	return pNewNode;
}


void PrintQueue(Queue* q)
{
	PNode pCur = q->_pHead;
	while (pCur)
	{
		printf("%d ",pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}