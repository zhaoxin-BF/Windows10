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
}Node, *PNode;

void InitList(PNode* pHead);
void PushBack(PNode* pHead, DataType data);
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

void PrintList(PNode pHead)
{
	PNode pCur = pHead;
	while (pCur)
	{
		printf(" %d ->", pCur->_data);
		pCur = pCur->_PNext;
	}
	printf(" NULL\n");
}

/////////////////////////////////////////单链表逆至
//void RList(PNode* pHead)
//{
//	PNode p1, p2, p3;
//	p1 = *pHead;
//	p2 = p1->_PNext;
//	p3 = p2;
//
//	p1->_PNext = NULL;
//
//	while (p3)
//	{
//		p3 = p3->_PNext;
//		p2->_PNext = p1;
//		p1 = p2;
//		p2 = p3;
//	}
//	*pHead = p1;
//}

////////////////////////////////单链表逆至第二遍
void RList(PNode* pHead)
{
	PNode p0 = *pHead;
	PNode p1 = p0->_PNext;
	PNode p2 = p0->_PNext;
	p0->_PNext = NULL;
	while (p1)
	{
		p2 = p1->_PNext;
		p1->_PNext = p0;
		p0 = p1;
		p1 = p2;
	}
	*pHead = p0;
}

///////////////////////////////////单链表排序
void Swap(DataType *a, DataType *b)
{
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}

void SortList(PNode *pHead)
{
	PNode pCur = *pHead;
	int size = 0;
	while (pCur)
	{
		size++;
		pCur = pCur->_PNext;
	}
	pCur = *pHead;
	int i, j;
	for (i = 1; i < size;i++)
	{
		for (j = 0; j < size - i;j++)
		{
			if (pCur->_data > pCur->_PNext->_data)
				Swap(&(pCur->_data), &(pCur->_PNext->_data));
			pCur = pCur->_PNext;
		}
		pCur = *pHead;
	}
}


//////////////////////////////////////////////两排好序的单链表相交，顺序输出
//方法一、（简单粗暴的方法，直接相连排序输出）
PNode ConnectTwoList(PNode *p1, PNode *p2)
{
	PNode pCur = *p1;
	while (pCur->_PNext)
	{
		pCur = pCur->_PNext;
	}
	pCur->_PNext = *p2;
	SortList(p1);
	return *p1;
}


//方法二、(不排序输出)
PNode UnConnectTwoList(PNode *p1, PNode *p2)
{
	PNode H, Next, a, b, pCur;
	if ((*p1)->_data < (*p2)->_data)
	{
		H = *p1;
		a = H->_PNext;
		b = *p2;
	}
	else
	{
		H = *p2;
		a = *p1;
		b = H->_PNext;
	}
	pCur = H;
	while (a && b)
	{
		if ((a->_data < b->_data) && (a != NULL && b != NULL))
		{
			Next = a;
			a = a->_PNext;
		}
		else
		{
			Next = b;
			b = b->_PNext;
		}

		pCur->_PNext = Next;
		pCur = pCur->_PNext;

		if (a == NULL)
		{
			Next = b;
			b = b->_PNext;
			pCur->_PNext = Next;
			pCur = pCur->_PNext;
		}
		if (b == NULL)
		{
			Next = a;
			a = a->_PNext;
			pCur->_PNext = Next;
			pCur = pCur->_PNext;
		}
	}
	return H;
}
