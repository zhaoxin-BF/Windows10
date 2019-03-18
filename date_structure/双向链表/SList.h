#ifndef __SList_h_
#define __SList_h_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

typedef int SLDataType;
typedef struct SListNode
{
	SLDataType _data;
	struct SListNode* _prev;
	struct SListNode* _next;
}SListNode;

typedef struct List
{
	struct SListNode* _pHead;
}List;

void SListInit(List* lt);
void SListDestory(List* lt);
void SListPushBack(List* lt, SLDataType x);
void SListPushFront(List* lt, SLDataType x);
void SListPopBack(List* lt);
void SListPopFront(List* lt);

SListNode* BuyListNode(SLDataType x);
int SListFind(List* lt, SLDataType x);
void SListInsert(SListNode* pos, SLDataType x);
void SListErase(SListNode* pos);
int SListSize(List* lt);
int SListEmpty(List* lt);
void SListPrint(List* lt);

#endif

void SListInit(List* lt)
{
	lt->_pHead = (SListNode*)malloc(sizeof(SListNode));
	lt->_pHead->_next = NULL;
	lt->_pHead->_prev = NULL;
}

void SListDestory(List* lt)
{
	free(lt);
}

void SListPushBack(List* lt, SLDataType data)
{
	assert(lt);
	SListNode* NewNode = BuyListNode(data);
	SListNode* cur = lt->_pHead;
	while (cur->_next)
	{
		cur = cur->_next;
	}

	cur->_next = NewNode;
	NewNode->_prev = cur;
}

void SListPushFront(List* lt, SLDataType data)
{
	assert(lt);
	SListNode* NewNode = BuyListNode(data);
	SListNode* cur = lt->_pHead->_next;

	lt->_pHead->_next = NewNode;
	NewNode->_next = cur;
	cur->_prev = NewNode;
	NewNode->_prev = lt->_pHead;
}
void SListPopBack(List* lt)
{
	assert(lt);

	SListNode* DelNode;
	SListNode* cur = lt->_pHead;
	while (cur->_next)
	{
		cur = cur->_next;
	}
	DelNode = cur;
	cur = DelNode->_prev;
	cur->_next = NULL;
	free(DelNode);
}

void SListPopFront(List* lt)
{
	assert(lt);

	SListNode* DelNode;
	SListNode* cur = lt->_pHead->_next;

	DelNode = cur;
	cur = DelNode->_next;
	lt->_pHead->_next = cur;
	cur->_prev = lt->_pHead;

	free(DelNode);
}

SListNode* BuyListNode(SLDataType data)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL)
		return 0;

	NewNode->_data = data;
	NewNode->_next = NULL;
	NewNode->_prev = NULL;

	return NewNode;
}

int SListFind(List* lt, SLDataType data)
{
	assert(lt);

	SListNode* cur = lt->_pHead->_next;
	while (cur)
	{
		if (cur->_data == data)
			return 1;
		cur = cur->_next;
	}
	return 0;
}

void SListInsert(SListNode* pos, SLDataType data)
{

}

void SListErase(SListNode* pos)
{

}

int SListSize(List* lt)
{
	int count = 0;
	SListNode* cur = lt->_pHead->_next;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
int SListEmpty(List* lt)
{
	if (SListSize(&lt) == 0)
		return 0;
	else
		return 1;
}

void SListPrint(List* lt)
{
	assert(lt);
	SListNode* cur = lt->_pHead;
	while (cur->_next)
	{
		cur = cur->_next;
		printf("%d--> ",cur->_data);
	}
	printf("NULL\n");
}