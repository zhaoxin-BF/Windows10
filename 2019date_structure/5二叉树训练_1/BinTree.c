#include"BinTree.h"
size_t n = 0;
int main()
{
	DataType array[] = {'A','B','C','*','*','*','D','E','*','*','F','*','*'};
	BNode pRoot;
	CreateBinTree(&pRoot,array,12,&n,'*');

	printf("���������");
	PrintBinTree(pRoot);
	printf("\n���������");
	LPrintBinTree(pRoot);
	printf("\n���������");
	RPrintBinTree(pRoot);
	printf("\n���������");
	LevelBinTree(pRoot);

	int size = SizeBinTree(pRoot);
	printf("\nSize = %d\n",size);


	BNode* str = BinTree(pRoot, 'A', size);
	printf("%p", str);

	//DestoryBinTree(&pRoot);

	getchar();
	return 0;
}