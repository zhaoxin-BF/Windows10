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

//创建二叉树单个节点
BNode BuyBinTree(DataType data);
//创建整个二叉树
void CreateBinTree(BNode* pRoot, DataType array[], int size, int* index, DataType invalid);

//前序遍历打印
void PrintBinTree(BNode pRoot);
//中序遍历打印
void LPrintBinTree(BNode pRoot);
//后续遍历打印
void RPrintBinTree(BNode pRoot);

//非递归前序遍历打印
void FPrintBinTree(BNode pRoot);
//非递归中序遍历打印
void FLPrintBinTree(BNode pRoot);
//非递归后续遍历打印
void FRPrintBinTree(BNode pRoot);
void PostOrderTraversal(BNode BT);

//层序遍历打印 
void LevelBinTree(BNode pRoot);



//拷贝二叉树--深拷贝（赋值拷贝）
BNode CopyBinTree(BNode pRoot);
//销毁二叉树
void DestoryBinTree(BNode* pRoot);
//返回节点数目
int SizeBinTree(BNode pRoot);


//2019/8/26 晚新增函数

//层序遍历分层打印输出
void LevelPrintBinTree(BNode pRoot);
//返回二叉树的高度
int HighBinTree(BNode pRoot);
//返回叶子结点个数
int SizeLeafNode(BNode pRoot);
//打印叶子结点
void PrintLeafNode(BNode pRoot);

