#include"BinTree.h"
int i = 0;
int main()
{
	char str[] = "ABD###CE##F";
	PNode pRoot;
	CreateBinTree(&pRoot, str, 11, &i,  '#');
	PNode ppRoot = CopyBinTree(pRoot);

	/*DestoryBinTree(&ppRoot);*/

	printf("size = %d\n",SizeBinTree(ppRoot));

	LevelBinTree(ppRoot);
	printf("\nǰ�����");
	PrintBinTree(ppRoot);
	printf("\n�������");
	LPrintBinTree(ppRoot);
	printf("\n�������");
	RPrintBinTree(ppRoot);
	getchar();
	return 0;
}
