#ifndef __Lise_h_
#define __Lise_h_

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct Node
{
	DataType _data;
	struct Node* _pNext;
}Node, *PNode;

//////////////////////////////////////////////////////

void SListInit(PNode* pHead);
void SListPushBack(PNode* pHead, DataType data);
void SListPopBack(PNode* pHead);
PNode BuySListNode(DataType data);
void PrintSList(PNode*pHead);
void RetSList(PNode* pHead);//链表逆至——方法一
void TRetSlist(PNode* pHead);//链表逆至——方法二




#endif
////////////////////////////////////////////////////

//链表逆至——方法一
void RetSList(PNode* pHead)
{
	PNode pCur = *pHead;
	PNode p1 = *pHead;
	PNode p2 = *pHead;
	int i, j, size = 1;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
		size++;
	}
	*pHead = pCur;
	p2 = pCur;
	for (i = size - 1; i > 0; i--)
	{
		pCur = p1;
		for (j = 0; j < i-1; j++)
		{
			pCur = pCur->_pNext;
		}
		p2->_pNext = pCur;
		p2 = p2->_pNext;
	}
	p1->_pNext = NULL;
}

//单链表逆至——方法二

void TRetSlist(PNode* pHead)
{
	PNode p1,p2,p3;
	p1 = *pHead;
	p2 = p1->_pNext;
	p3 = p2;
	p1->_pNext = NULL;
	while (p3)
	{
		p3 = p3->_pNext;
		p2->_pNext = p1;
		p1 = p2;
		p2 = p3;
	}
	*pHead = p1;
}
void SListInit(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;

}

void SListPushBack(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);

	pNewNode = BuySListNode(data);
	//空链表
	if (NULL == *pHead)
		*pHead = pNewNode;
	else
	{
		//非空两边
		PNode pCur = *pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;

		pCur->_pNext = pNewNode;
	}


}


void SListPopBack(PNode* pHead)
{
	assert(pHead);
	if (NULL == *pHead)
		return;
	else if (NULL == (*pHead)->_pNext)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pCur = *pHead;
		while (pCur->_pNext->_pNext)
			pCur = pCur->_pNext;

		free(pCur->_pNext);
		pCur->_pNext = NULL;
	}
}

PNode BuySListNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
		return NULL;

	pNewNode->_pNext = NULL;
	pNewNode->_data = data;

	return pNewNode;
}
void PrintSList(PNode *pHead)
{
	PNode pCur = *pHead;
	assert(pHead);
	while (pCur)
	{
		printf("%d->",pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}



