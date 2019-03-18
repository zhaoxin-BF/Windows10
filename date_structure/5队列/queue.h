#ifndef __QUEUE_h_
#define __QUEUE_h_

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
PNode BuyNode(DataType data);
void PushQueue(Queue* q, DataType data);
void PopQueue(Queue* q);
void PrintQueue(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);

#endif

//��ʼ������
void InitQueue(Queue* q)
{
	q->_Qhead = q->_Qtail = NULL;
}

//��Ӳ���
void PushQueue(Queue* q, DataType data)
{
	if (q->_Qhead == NULL)
		q->_Qhead = q->_Qtail = BuyNode(data);
	else
	{
		q->_Qtail->_pNext = BuyNode(data);
		q->_Qtail = q->_Qtail->_pNext;
	}
}

//����
void PopQueue(Queue* q)
{
	PNode DelNode = NULL;
	DelNode = q->_Qhead;
	q->_Qhead = q->_Qhead->_pNext;
	free(DelNode);
}
//�����µĽڵ�
PNode BuyNode(DataType data)
{
	PNode newNode = (PNode)malloc(sizeof(Node));

	newNode->_data = data;
	newNode->_pNext = NULL;

	return newNode;
}

//��ӡ����
void PrintQueue(Queue* q)
{
	PNode pCur = NULL;
	pCur = q->_Qhead;
	while (pCur)
	{
		printf("%d--> ", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

DataType QueueFront(Queue* q)
{
	return q->_Qhead->_data;
}
DataType QueueBack(Queue* q)
{
	return q->_Qtail->_data;
}
int QueueSize(Queue* q)
{
	int count = 0;
	PNode PCur = NULL;
	PCur = q->_Qhead;
	while (PCur)
	{
		count++;
		PCur = PCur->_pNext;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	if (q->_Qhead == q->_Qtail)
		return 1;
	else
		return 0;
}