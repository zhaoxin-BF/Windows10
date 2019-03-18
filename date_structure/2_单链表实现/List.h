#ifndef __List_h_
#define __List_h_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node,*PNode;

//不带头结点的单链表
void SListInit(PNode* pHead);
void SListPushBack(PNode* pHead,DataType data);
void SListPopBack(PNode* pHead);
void SListPushFront(PNode* pHead,DataType data);
void SListPopFront(PNode* pHead);
PNode SlistFind(PNode pHead,DataType data);
void SlistInsert(PNode* pHead,PNode pos,DataType data);
void SListErase(PNode* pHead,PNode pos);
void SListDestroy(PNode* pHead);
void SListSize(PNode pHead);
void SListClear(PNode* pHead);
PNode BuySListNode(DataType data);
PNode SListBack(PNode pHead);                              // 找链表中最后一个节点的位置
void PrintSList(PNode pHead);

#endif

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

	if (NULL == *pHead)
		*pHead = pNewNode;

	else
	{
		PNode pCur = *pHead;
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}
void SListPopBack(PNode* pHead)
{
	assert(pHead);
	if (*pHead == NULL)
		return;
	else if (NULL== (*pHead)->_pNext)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pCur = *pHead;
		while (pCur->_pNext->_pNext)
		{
			pCur = pCur->_pNext;
		}

		free(pCur->_pNext);
		pCur->_pNext = NULL;
	}
}
void SListPushFront(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	pNewNode = BuySListNode(data);

	if (*pHead == NULL)
		*pHead = pNewNode;

	else
	{
		pNewNode->_pNext = *pHead;
		*pHead = pNewNode;
	}
	
}

void SListPopFront(PNode* pHead)
{
	if (*pHead == NULL)
		return;

	else
	{
		PNode pDelNode = *pHead;
		*pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}

PNode SlistFind(PNode pHead, DataType data);
void SlistInsert(PNode* pHead, PNode pos, DataType data);
void SListErase(PNode* pHead, PNode pos);
void SListDestroy(PNode* pHead);
void SListSize(PNode pHead);
void SListClear(PNode* pHead);
PNode BuySListNode(DataType data)
{
	PNode newNode = NULL;

	newNode = (PNode*)malloc(sizeof(PNode));
	if (newNode == NULL)
		return NULL;

	newNode->_data = data;
	newNode->_pNext = NULL;

	return newNode;
}

PNode SListBack(PNode pHead);

void PrintSList(PNode pHead)
{
	while (pHead)
	{
		printf("%d-->", pHead->_data);
		pHead = pHead->_pNext;
	}
	printf("NULL\n");
}