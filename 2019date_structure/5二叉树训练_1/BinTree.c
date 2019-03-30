#include"BinTree.h"
size_t n = 0;
int main()
{
	DataType array[] = {'A','B','C','*','*','*','D','E','*','*','F','*','*'};
	BNode pRoot;
	CreateBinTree(&pRoot,array,12,&n,'*');

	printf("中序遍历：");
	PrintBinTree(pRoot);
	printf("\n先序遍历：");
	LPrintBinTree(pRoot);
	printf("\n后序遍历：");
	RPrintBinTree(pRoot);
	printf("\n层序遍历：");
	LevelBinTree(pRoot);

	int size = SizeBinTree(pRoot);
	printf("\nSize = %d\n",size);


	BNode* str = BinTree(pRoot, 'A', size);
	printf("%p", str);

	//DestoryBinTree(&pRoot);

	getchar();
	return 0;
}