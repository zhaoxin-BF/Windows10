#ifndef __BinTree_h_
#define __BinTree_h_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

typedef char DataType;
///////////////////////////////����

typedef struct Node
{
	DataType _data;
	struct Node* _pNext;
}Node, *PPNode;

typedef struct Queue
{
	PPNode _Qhead;
	PPNode _Qtail;
}Queue;

typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pright;
	DataType _data;
}pNode,*PNode;

PNode BuyBinTree(DataType data);
void CreateBinTree(PNode* pRoot, DataType array[], int size, int* index, DataType invalid);


#endif

PNode BuyBinTree(DataType data)
{
	PNode newNode = (pNode*)malloc(sizeof(pNode));

	newNode->_data = data;
	newNode->_pLeft = NULL;
	newNode->_pright = NULL;

	return newNode;
}

void CreateBinTree(PNode* pRoot, DataType array[], int size, int* index, DataType invalid)
{
	if ((*index < size) && (invalid != array[*index]))
	{
		*pRoot = BuyBinTree(array[*index]);


		++(*index);
		CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);
		++(*index);
		CreateBinTree(&(*pRoot)->_pright, array, size, index, invalid);
	}
}

void PrintBinTree(PNode pRoot)
{
	if(pRoot)
	{
		printf("%c ", (pRoot)->_data);

		PrintBinTree(pRoot->_pLeft);

		PrintBinTree(pRoot->_pright);
	}
}

void LPrintBinTree(PNode pRoot)
{
	if (pRoot)
	{
		LPrintBinTree(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		LPrintBinTree(pRoot->_pright);
	}
}

void RPrintBinTree(PNode pRoot)
{
	if (pRoot)
	{
		RPrintBinTree(pRoot->_pLeft);

		RPrintBinTree(pRoot->_pright);

		printf("%c ", pRoot->_data);
	}
}

PNode CopyBinTree(PNode pRoot)
{
	PNode newpRoot = NULL;
	if (pRoot)
	{
		newpRoot = BuyBinTree(pRoot->_data);

		newpRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		newpRoot->_pright = CopyBinTree(pRoot->_pright);
	}
	return newpRoot;
}

void DestoryBinTree(PNode* pRoot)
{
	if (*pRoot)
	{
		DestoryBinTree(&(*pRoot)->_pLeft);

		DestoryBinTree(&(*pRoot)->_pright);

		free(*pRoot);
		*pRoot = NULL;
	}

}

//void LevelBinTree(PNode pRoot)
//{
//	printf("�������: ");
//	Queue q;
//
//	InitQueue(&q);
//	PushQueue(&q, pRoot);
//
//	while (QueueEmpty(&q))
//	{
//		PNode pCur = QueueFront(&q);
//		printf("%c  ",pCur->_data);
//		PopQueue(&q);
//
//		if (pCur->_pLeft)
//			PushQueue(&q, pCur->_pLeft);
//
//		if (pCur->_pright)
//			PushQueue(&q,pCur->_pright);
//	}
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//int SizeBinTree(PNode pRoot)
//{
//	if (pRoot == NULL)
//		return 0;
//
//	return SizeBinTree(pRoot->_pLeft)+SizeBinTree(pRoot->_pright)+1;
//}
//
////��ʼ������
//void InitQueue(Queue* q)
//{
//	q->_Qhead = q->_Qtail = NULL;
//}
//
////��Ӳ���
//void PushQueue(Queue* q, DataType data)
//{
//	if (q->_Qhead == NULL)
//		q->_Qhead = q->_Qtail = BuyNode(data);
//	else
//	{
//		q->_Qtail->_pNext = BuyNode(data);
//		q->_Qtail = q->_Qtail->_pNext;
//	}
//}
//
////����
//void PopQueue(Queue* q)
//{
//	PPNode DelNode = NULL;
//	DelNode = q->_Qhead;
//	q->_Qhead = q->_Qhead->_pNext;
//	free(DelNode);
//}
////�����µĽڵ�
//PNode BuyNode(DataType data)
//{
//	PPNode newNode = (PPNode)malloc(sizeof(pNode));
//
//	newNode->_data = data;
//	newNode->_pNext = NULL;
//
//	return newNode;
//}
//
////��ӡ����
//void PrintQueue(Queue* q)
//{
//	PPNode pCur = NULL;
//	pCur = q->_Qhead;
//	while (pCur)
//	{
//		printf("%d--> ", pCur->_data);
//		pCur = pCur->_pNext;
//	}
//	printf("NULL\n");
//}
//
//int QueueSize(Queue* q)
//{
//	int count = 0;
//	PPNode PCur = NULL;
//	PCur = q->_Qhead;
//	while (PCur)
//	{
//		count++;
//		PCur = PCur->_pNext;
//	}
//	return count;
//}
//int QueueEmpty(Queue* q)
//{
//	if (q->_Qhead == q->_Qtail)
//		return 0;
//	else
//		return 1;
//}