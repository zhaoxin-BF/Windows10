#include "SearchTree.h"

int main()
{
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9, 10 };
	BSTNode* tree = NULL;
	int i;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		Insert_BSTree(&tree, arr[i]);
	}
	InOrder_BSTree(&tree);
	printf("\n");
	Remove_BSTree(&tree, 5);
	BSTree find = Find_BSTree(&tree, 3);
	InOrder_BSTree(&tree);
	printf("\n");
	if (find != NULL)
		printf("YES!\n");
	else
		printf("NO!\n");
	system("pause");
	return 0;
}