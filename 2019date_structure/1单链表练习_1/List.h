#ifndef __LIST__H_
#define __LIST__H_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct Node
{
	DataType _data;
	struct Node* _PNext;
}Node,*PNode;

void InitList(PNode* pHead);
void PushBack(PNode* pHead,DataType data);
void PopBack(PNode* pHead);
PNode BuyNode(DataType data);
void PrintList(PNode pHead);

void RList(PNode* pHead);

#endif

void InitList(PNode* pHead)
{
	*pHead = NULL;
}

PNode BuyNode(DataType data)
{
	PNode NewNode = (PNode)malloc(sizeof(Node));
	if (NULL == NewNode)
		return NULL;

	NewNode->_PNext = NULL;
	NewNode->_data = data;

	return NewNode;
}

void PushBack(PNode* pHead, DataType data)
{
	PNode PNewNode = NULL;
	assert(pHead);

	PNewNode = BuyNode(data);

	if (NULL == *pHead)
		*pHead = PNewNode;
	else
	{
		PNode pCur = *pHead;
		while (pCur->_PNext)
		{
			pCur = pCur->_PNext;
		}
		pCur->_PNext = PNewNode;
	}
}

void PopBack(PNode* pHead)
{
	assert(pHead);
	if (NULL == *pHead)
		return;
	else if ((*pHead)->_PNext == NULL)
	{
			free(*pHead);
			*pHead == NULL;
	}
	else
	{
		PNode pCur = *pHead;
		while (pCur->_PNext->_PNext)
			pCur = pCur->_PNext;

		free(pCur->_PNext);
		pCur->_PNext = NULL;
	}
}

void RList(PNode* pHead)
{
	PNode p1 , p2 , p3 ;
	p1 = *pHead;
	p2 = p1->_PNext;
	p3 = p2;

	p1->_PNext = NULL;

	while (p3)
	{
		p3 = p3->_PNext;
		p2->_PNext = p1;
		p1 = p2;
		p2 = p3;
	}
	*pHead = p1;
}

void PrintList(PNode pHead)
{
	PNode pCur = pHead;
	while (pCur)
	{
		printf(" %d ->",pCur->_data);
		pCur = pCur->_PNext;
	}
	printf(" NULL\n");
}