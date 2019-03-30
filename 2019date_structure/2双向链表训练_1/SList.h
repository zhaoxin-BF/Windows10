#ifndef __SLIST_H__
#define __SLIST_H__

#include<stdio.h>
#include<malloc.h>

typedef int DataType;

typedef struct Node
{
	DataType _data;
	struct Node* _pFront;
	struct Node* _pNext;
}Node,*PNode;

void InitSList(PNode* s);
PNode BuyNode(DataType data); 
void InsertSList(PNode* s, int n, DataType data);
void EarseSList(PNode* s, int n);
int FindNum(PNode* s, DataType data);
void PushbackSList(PNode* s,DataType data);
void PopbackSList(PNode* s);
void PrintSList(PNode* s);




#endif

void InitSList(PNode* s)
{
	*s = NULL;
}

PNode BuyNode(DataType data)
{
	PNode NewNode = (PNode)malloc(sizeof(Node));

	NewNode->_data = data;
	NewNode->_pFront = NewNode->_pNext = NULL;

	return NewNode;
}

void InsertSList(PNode* s, int n, DataType data)
{
	PNode NewNode = BuyNode(data);
	PNode pCur = *s;
	n--;
	while (--n)
	{
		pCur = pCur->_pNext;
	}
	NewNode->_pNext = pCur->_pNext;
	pCur->_pNext = NewNode;
	NewNode->_pFront = pCur;
	NewNode->_pNext->_pFront = NewNode;
}

void EarseSList(PNode* s, int n)
{
	PNode DelNode;
	PNode pCur = *s;
	while (--n)
	{
		pCur = pCur->_pNext;
	}
	DelNode = pCur;
	pCur = DelNode->_pFront;

	pCur->_pNext = DelNode->_pNext;
	DelNode->_pNext->_pFront = pCur;

	free(DelNode);
}

int FindNum(PNode* s,DataType data)
{
	int n = 0;
	PNode pCur = *s;
	while (pCur)
	{
		n++;
		if (pCur->_data == data)
			return n;
		pCur = pCur->_pNext;
	}
}

void PushbackSList(PNode* s, DataType data)
{
	PNode NewNode = BuyNode(data);
	if (*s == NULL)
	{
		*s = NewNode;
	}
	else
	{
		PNode pCur = *s;
		while (pCur->_pNext != NULL)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = NewNode;
		NewNode->_pFront = pCur;
	}
}

void PopbackSList(PNode* s)
{
	PNode DelNode;
	PNode pCur = *s;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	DelNode = pCur;
	pCur = DelNode->_pFront;
	pCur->_pNext = NULL;
	DelNode->_pFront = NULL;


	free(DelNode);
}

void PrintSList(PNode* s)
{
	PNode pCur = *s;
	while (pCur)
	{
		printf("%d ", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}



