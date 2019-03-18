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
	printf("\n前序遍历");
	PrintBinTree(ppRoot);
	printf("\n中序遍历");
	LPrintBinTree(ppRoot);
	printf("\n后序遍历");
	RPrintBinTree(ppRoot);
	getchar();
	return 0;
}
