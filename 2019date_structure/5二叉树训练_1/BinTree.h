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
//创建二叉树
void CreateBinTree(BNode* pRoot, DataType array[], int size, int* index, DataType invalid);
//中序遍历打印
void PrintBinTree(BNode pRoot);
//先序遍历打印
void LPrintBinTree(BNode pRoot);
//后续遍历打印
void RPrintBinTree(BNode pRoot);
//拷贝二叉树--深拷贝（赋值拷贝）
BNode CopyBinTree(BNode pRoot);
//销毁二叉树
void DestoryBinTree(BNode* pRoot);
//层序遍历打印 
void LevelBinTree(BNode pRoot);
//返回节点数目
int SizeBinTree(BNode pRoot);


#endif

//创建二叉树节点
BNode BuyBinTree(DataType data)
{
	BNode NewNode = (pNode*)malloc(sizeof(pNode));

	NewNode->_data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pright = NULL;

	return NewNode;
}

//创建二叉树
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


//中序遍历打印
void PrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);

		PrintBinTree(pRoot->_pLeft);

		PrintBinTree(pRoot->_pright);
	}
}


//先序遍历打印
void LPrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		LPrintBinTree(pRoot->_pLeft);

		printf("%c ",pRoot->_data);

		LPrintBinTree(pRoot->_pright);
	}
}
//后续遍历打印
void RPrintBinTree(BNode pRoot)
{
	if (pRoot)
	{
		RPrintBinTree(pRoot->_pLeft);

		RPrintBinTree(pRoot->_pright);

		printf("%c ",pRoot->_data);
	}
}


//拷贝二叉树--深拷贝（赋值拷贝）
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

//销毁二叉树
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


//层序遍历打印 
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

//返回节点数目
int SizeBinTree(BNode pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	return 1 + SizeBinTree(pRoot->_pLeft) + SizeBinTree(pRoot->_pright);
}

//返回节点地址，非递归遍历一遍二叉树，对比数据是否正确，如对比完后还没找到size会等于0，则返回NULL。
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