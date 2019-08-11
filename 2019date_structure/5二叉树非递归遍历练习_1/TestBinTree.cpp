
#include <iostream>
#include "BinTree.h"

int n = 0;

int main()
{
	DataType array[] = { 'A','B','C','*','*','*','D','E','*','*','F','*','*' };
	BNode pRoot;
	CreateBinTree(&pRoot, array, 12, &n, '*');


	//�ݹ����������
	printf("�ݹ������������");
	printf("\nǰ�������");
	PrintBinTree(pRoot);
	printf("\n���������");
	LPrintBinTree(pRoot);
	printf("\n���������");
	RPrintBinTree(pRoot);

	//�ǵݹ����������
	printf("\n\n�ǵݹ������������");
	printf("\nǰ�������");
	FPrintBinTree(pRoot);
	printf("\n���������");
	FLPrintBinTree(pRoot);
	printf("\n�����������һ��");
	FRPrintBinTree(pRoot);
	printf("\n���������������");
	PostOrderTraversal(pRoot);

	//�������
	//���������ӡ 
	printf("\n���������������");
	LevelBinTree(pRoot);

	//��������������ڵ����
	int size = SizeBinTree(pRoot);
	printf("\nSize = %d\n", size);

	printf("\nHello World!\n");
	system("pause");
	return 0;
}