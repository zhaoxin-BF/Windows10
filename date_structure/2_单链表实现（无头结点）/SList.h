#ifndef __SList_h_
#define __SList_h_

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int TypeData;

typedef struct Node
{
	TypeData _data;
	TypeData _password;
	struct Node* _pNext;
}Node,*PNode;

//不带头结点的单链表

void InitSList(PNode* pHead);
void PushBackSList(PNode* pHead, TypeData data, TypeData password);
PNode BuySListNode(TypeData data);
int SIzeSList(PNode* pHead);
void DestorySList(PNode* pHead);
void PrintSList(PNode* pHead);
void JoseCycle(PNode* pHead, int k);


#endif

//初始化不带头节点的单链表
void InitSList(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}

//尾插
void PushBackSList(PNode* pHead,TypeData data,TypeData password)
{
	PNode pNewNode = NULL;
	assert(pHead);

	pNewNode = BuySListNode(data,password);
	//空链表
	if (*pHead == NULL)
		*pHead = pNewNode;
	else
	{
		PNode pCur = *pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;

		pCur->_pNext = pNewNode;
	}
	//非空链表
}


//创建新节点
PNode BuySListNode(TypeData data,TypeData password)
{
	PNode pNewNode = (PNode)(malloc(sizeof(Node)));
	if (pNewNode == NULL)
		return NULL;

	pNewNode->_pNext = NULL;
	pNewNode->_data = data;
	pNewNode->_password = password;
	return pNewNode;
}

//计算链表元素个数
int SizeSList(PNode* pHead)
{
	assert(pHead);
	if (NULL == *pHead)
		return 0;
	else
	{
		int count = 0;
		PNode pCur = *pHead;
		while (pCur)
		{
			count++;
			pCur = pCur->_pNext;
		}
		return count;
	}
}


//销毁链表
void DestorySList(PNode* pHead)
{
	PNode pDelNode = NULL;
	assert(pHead);

	while (*pHead)
	{
		pDelNode = *pHead;
		*pHead = pDelNode->_pNext;
		free(pDelNode);
	}
	return;
}

//打印单链表
void PrintSList(PNode* pHead)
{
		PNode pCur = *pHead;
		while (pCur)
		{
			printf("%d--> ", pCur->_data);
			pCur = pCur->_pNext;
		}
		printf("NULL\n");
}

void JoseCycle(PNode* pHead, int k)
{
	PNode cur = *pHead;
	PNode pCur = *pHead;
	while (cur->_pNext)
	{
		cur = cur->_pNext;
	}
	cur->_pNext = pCur;
	cur = pCur;
	int count = k;
	while (cur != cur->_pNext)
	{
		PNode del = NULL;
		while (--count)
		{
			cur = cur->_pNext;
		}
		count = cur->_password;
		printf("\tDELETE::%d\n", cur->_data);
		cur->_data = cur->_pNext->_data;
		del = cur->_pNext;
		cur->_pNext = del->_pNext;
		free(del);
		del = NULL;
	}
	printf("RESULT::%d\n", cur->_data);
}



//void InitSList(PNode* pHead);
//void PushBackSList(PNode* pHead, TypeData data);
//void PopBackSList(PNode* pHead);
//PNode BuySListNode(TypeData data);
//int SizeSList(PNode* pHead);
//void InsertSList(PNode* pHead, TypeData size,TypeData data);
//void EarseSList(PNode* pHead, TypeData size);
//void PrintSList(PNode* pHead);
//
//
//#endif
//
//void InitSList(PNode pHead)
//{
//	assert(pHead);
//	pHead = NULL;
//}
//
//void PushBackSList(PNode pHead, TypeData data)
//{
//	PNode NewNode = NULL;
//	assert(pHead);
//
//	NewNode = BuySListNode(data);
//
//	if (pHead == NULL)
//		pHead = NewNode;
//	else
//	{
//		PNode pCur = pHead;
//		while (pCur->_pNext)
//			pCur = pCur->_pNext;
//
//		pCur->_pNext = NewNode;
//	}
//	return;
//}
//
//void PopBackSList(PNode pHead)
//{
//	assert(pHead);
//	if (pHead == NULL)
//		return;
//
//	else if ((pHead)->_pNext == NULL)
//	{
//		free(pHead);
//		pHead = NULL;
//	}
//	else
//	{
//		PNode pCur = pHead;
//		while (pCur->_pNext->_pNext)
//			pCur = pCur->_pNext;
//
//		free(pCur->_pNext);
//		pCur->_pNext = NULL;
//	}
//	return;
//
//}
//
//PNode BuySListNode(TypeData data)
//{
//	PNode pNewNode = (PNode)malloc(sizeof(Node));
//	if (pNewNode == NULL)
//		return NULL;
//	
//	pNewNode->_data = data;
//	pNewNode->_pNext = NULL;
//	
//	return pNewNode;
//
//}
//
//int SizeSList(PNode pHead)
//{
//	assert(pHead);
//	if (pHead == NULL)
//		return 0;
//	else
//	{
//		int count = 0;
//		PNode pCur = pHead;
//		while (pCur)
//		{
//			count++;
//			pCur = pCur->_pNext;
//		}
//		return count;
//	}
//
//
//}
//
//
//
//void PrintSList(PNode pHead)
//{
//	assert(pHead);
//
//	PNode pCur = pHead;
//
//	while (pCur)
//	{
//		printf("%d --> ",pCur->_data);
//		pCur = pCur->_pNext;
//	}
//	printf("NULL");
//}
//
//void InsertSList(PNode pHead, TypeData size, TypeData data)
//{
//	PNode NewNode = BuySListNode(data);
//	PNode pCur = pHead;
//	int count = 2;
//
//	if (size <= SizeSList(pHead))
//	{
//		while (count < size)
//		{
//			count++;
//			pCur = pCur->_pNext;
//		}
//		
//		NewNode->_pNext = pCur->_pNext;
//		pCur->_pNext = NewNode;
//	}
//		
//}
//
//void EarseSList(PNode pHead, TypeData size)
//{
//		PNode pCur = pHead;
//		PNode Ears;
//		int count = 2;
//		while (count < size)
//		{
//			count++;
//			pCur = pCur->_pNext;
//		}
//		Ears = pCur->_pNext;
//		pCur->_pNext = Ears->_pNext;
//}