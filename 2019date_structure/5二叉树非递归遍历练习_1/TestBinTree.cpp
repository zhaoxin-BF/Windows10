
#include <iostream>
#include "BinTree.h"

int n = 0;

int main()
{
	DataType array[] = { 'A','B','C','*','*','*','D','E','*','*','F','*','*' };
	BNode pRoot;
	CreateBinTree(&pRoot, array, 12, &n, '*');


	//递归遍历二叉树
	printf("递归遍历二叉树：");
	printf("\n前序遍历：");
	PrintBinTree(pRoot);
	printf("\n中序遍历：");
	LPrintBinTree(pRoot);
	printf("\n后序遍历：");
	RPrintBinTree(pRoot);

	//非递归遍历二叉树
	printf("\n\n非递归遍历二叉树：");
	printf("\n前序遍历：");
	FPrintBinTree(pRoot);
	printf("\n中序遍历：");
	FLPrintBinTree(pRoot);
	printf("\n后序遍历方法一：");
	FRPrintBinTree(pRoot);
	printf("\n后序遍历方法二：");
	PostOrderTraversal(pRoot);

	//层序遍历
	//层序遍历打印 
	printf("\n二叉树层序遍历：");
	LevelBinTree(pRoot);

	//返回输出二叉树节点个数
	int size = SizeBinTree(pRoot);
	printf("\nSize = %d\n", size);

	printf("\nHello World!\n");
	system("pause");
	return 0;
}