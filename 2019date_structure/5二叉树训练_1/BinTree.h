#ifndef __BINTREE_H__
#define __BINTREE_H__


#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include"Queue.h"


typedef char DataType;

typedef struct BinTreeNode
{
	DataType _data;
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pright;
}pNode,*BNode;

BNode BuyBinTree(DataType data);
//����������
void CreateBinTree(BNode* pRoot, DataType array[], int size, int* index, DataType invalid);
//���������ӡ
void PrintBinTree(BNode pRoot);
//���������ӡ
void LPrintBinTree(BNode pRoot);
//����������ӡ
void RPrintBinTree(BNode pRoot);
//����������--�������ֵ������
BNode CopyBinTree(BNode pRoot);
//���ٶ�����
void DestoryBinTree(BNode* pRoot);
//���������ӡ 
void LevelBinTree(BNode pRoot);
//���ؽڵ���Ŀ
int SizeBinTree(BNode pRoot);


#endif

//�����������ڵ�
BNode BuyBinTree(DataType data)
{
	BNode NewNode = (pNode*)malloc(sizeof(pNode));

	NewNode->_data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pright = NULL;

	return NewNode;
}

//����������
void CreateBinTree(BNode* pRoot, DataType array[], int size, int* index, DataType invalid)
{
	if ((*index < size) && (invalid != array[*index]))
	{
		*pRoot = BuyBinTree(array[*index]);

		++(*index);
		CreateBinTree(&(*pRoot)->_pLeft,array,size,index,invalid);

		++(*index);
		CreateBinTree(&(*pRoot)->_pright,array,size,index,invalid);
	}
}


//���������ӡ
void PrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);

		PrintBinTree(pRoot->_pLeft);

		PrintBinTree(pRoot->_pright);
	}
}


//���������ӡ
void LPrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		LPrintBinTree(pRoot->_pLeft);

		printf("%c ",pRoot->_data);

		LPrintBinTree(pRoot->_pright);
	}
}
//����������ӡ
void RPrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		RPrintBinTree(pRoot->_pLeft);

		RPrintBinTree(pRoot->_pright);

		printf("%c ",pRoot->_data);
	}
}


//����������--�������ֵ������
BNode CopyBinTree(BNode pRoot)
{
	BNode newpRoot = NULL;
	if (pRoot)
	{
		newpRoot = BuyBinTree(pRoot->_data);

		newpRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		newpRoot->_pright = CopyBinTree(pRoot->_pright);
	}
	return newpRoot;
}

//���ٶ�����
void DestoryBinTree(BNode* pRoot)
{
	if (*pRoot)
	{
		DestoryBinTree(&(*pRoot)->_pLeft);

		DestoryBinTree(&(*pRoot)->_pright);
		
		free(*pRoot);

		*pRoot = NULL;
	}
}


//���������ӡ 
void LevelBinTree(BNode pRoot)
{
	Queue q;
	InitQueue(&q);

	PushQueue(&q,pRoot);

	while (!EmptyQueue(&q))
	{
		BNode pCur = QueueFront(&q);
		printf("%c ",pCur->_data);
		PopQueue(&q);

		if (pCur->_pLeft)
			PushQueue(&q,pCur->_pLeft);

		if (pCur->_pright)
			PushQueue(&q,pCur->_pright);
	}
}

//���ؽڵ���Ŀ
int SizeBinTree(BNode pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	return 1 + SizeBinTree(pRoot->_pLeft) + SizeBinTree(pRoot->_pright);
}

//���ؽڵ��ַ���ǵݹ����һ����������Ա������Ƿ���ȷ����Ա����û�ҵ�size�����0���򷵻�NULL��
BNode* BinTree(BNode pRoot,DataType data,int size)
{
	Queue q;
	InitQueue(&q);

	PushQueue(&q, pRoot);

	while (!EmptyQueue(&q))
	{
		size--;
		BNode pCur = QueueFront(&q);
		if (pCur->_data == data)
		{
			return pCur;
		}
		PopQueue(&q);

		if (pCur->_pLeft)
			PushQueue(&q, pCur->_pLeft);

		if (pCur->_pright)
			PushQueue(&q, pCur->_pright);
	}
	if (size == 0)
		return NULL;
}