#ifndef __QUEUE_H__
#define __QUEUE_H__

#include<stdio.h>
#include<malloc.h>

typedef int DataType;

typedef struct Node
{
	DataType _data;
	struct Node* _pNext;
}Node,*PNode;

typedef struct Queue
{
	PNode _Qhead;
	PNode _Qtail;
}Queue;

void InitQueue(Queue* q);
void PushQueue(Queue* q,DataType data);
void PopQueue(Queue* q);
PNode BuyNode(DataType data);
int SizeQueue(Queue* q);
int EmptyQueue(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
void PrintQueue(Queue* q);

#endif

void InitQueue(Queue* q)
{
	q->_Qhead = NULL;
	q->_Qtail = NULL;
}

void PushQueue(Queue* q,DataType data)
{
	if (q->_Qhead == NULL)
	{
		q->_Qhead = q->_Qtail = BuyNode(data);
	}
	else
	{
		q->_Qtail->_pNext = BuyNode(data);
		q->_Qtail = q->_Qtail->_pNext;
	}
}

void PopQueue(Queue* q)
{
	if (q->_Qhead != NULL)
	{
		PNode DelNode = NULL;
		DelNode = q->_Qhead;
		q->_Qhead = q->_Qhead->_pNext;
		free(DelNode);
	}
}

PNode BuyNode(DataType data)
{
	PNode NewNode = (PNode)malloc(sizeof(Node));
	NewNode->_data = data;
	NewNode->_pNext = NULL;
	return NewNode;
}

int SizeQueue(Queue* q)
{
	int size = 0;
	PNode pCur = q->_Qhead;
	while (pCur != NULL)
	{
		size++;
		pCur = pCur->_pNext;
	}
	return size;
}

int EmptyQueue(Queue* q)
{
	if (q->_Qhead == NULL)
		return 1;
	else
		return 0;
}
DataType QueueFront(Queue* q)
{
	return q->_Qhead->_data;
}

DataType QueueBack(Queue* q)
{
	return q->_Qtail->_data;
}

void PrintQueue(Queue* q)
{
	PNode pCur = q->_Qhead;
	while (pCur != NULL)
	{
		printf("%d ", pCur->_data);
		pCur = pCur->_pNext;
	}
}