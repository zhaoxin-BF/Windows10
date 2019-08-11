#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <queue>
#include <stack>
using namespace std;

typedef char DataType;

typedef struct BinTreeNode
{
	DataType _data;
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pright;
}pNode, *BNode;


////////////////////////////////////////////////////////////////////

//���������������ڵ�
BNode BuyBinTree(DataType data);
//��������������
void CreateBinTree(BNode* pRoot, DataType array[], int size, int* index, DataType invalid);

//ǰ�������ӡ
void PrintBinTree(BNode pRoot);
//���������ӡ
void LPrintBinTree(BNode pRoot);
//����������ӡ
void RPrintBinTree(BNode pRoot);

//�ǵݹ�ǰ�������ӡ
void FPrintBinTree(BNode pRoot);
//�ǵݹ����������ӡ
void FLPrintBinTree(BNode pRoot);
//�ǵݹ����������ӡ
void FRPrintBinTree(BNode pRoot);
void PostOrderTraversal(BNode BT);

//���������ӡ 
void LevelBinTree(BNode pRoot);

//����������--�������ֵ������
BNode CopyBinTree(BNode pRoot);
//���ٶ�����
void DestoryBinTree(BNode* pRoot);
//���ؽڵ���Ŀ
int SizeBinTree(BNode pRoot);

