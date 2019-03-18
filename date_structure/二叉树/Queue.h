#ifndef __Queue_h_
#define __Queue_h_

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef struct BintryTreeNode* _QTDataType;

typedef struct Node
{
	_QTDataType _data;
	struct Node* _pNext;
}Node, *PNode;


typedef struct Queue
{
	PNode _pHead;
	PNode _pTail;
}Queue;



void QueueInit(Queue* q);
void QueueDestry(Queue* q);

void QueuePush(Queue* q, _QTDataType data);
void QueuePop(Queue* q);
_QTDataType QueueFront(Queue* q);
_QTDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
PNode BuyNode(_QTDataType data);
void PrintQueue(Queue q);


#endif 

PNode BuyNode(_QTDataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;

	return pNewNode;
}

void QueueDestry(Queue* q)
{
	while (q->_pHead)
	{
		free(q->_pHead);
		q->_pHead = q->_pHead->_pNext;
	}

}


void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = q->_pTail = NULL;
}

void QueuePush(Queue* q, _QTDataType data)
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

_QTDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_pHead->_data;
}

_QTDataType QueueBack(Queue* q)
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
		++count;
		pCur = pCur->_pNext;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	if (QueueSize(q) == 0)
		return 0;
	return 1;
}

void PrintQueue(Queue* q)
{
	PNode pCur = q->_pHead;
	while (pCur)
	{
		printf("%d ", pCur->_data);
		pCur = pCur->_pNext;
	}
}