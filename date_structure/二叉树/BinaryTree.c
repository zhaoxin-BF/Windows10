#include"BinaryTree.h"

int main()
{
	char array[] = { 'A', 'B', 'D', '#', '#','#', 'C',
		'E', '#', '#', 'F', '#', '#' };
	size_t i = 0;
	BTNode* tree = BintryTreeCreate(array, sizeof(array) / sizeof(DataType), &i);

	BintryTreePrevOrder(tree);
	printf("\n");
	BintryTreePrevOderNonR(tree);

	BintryTreeInOrder(tree);
	printf("\n");
	BintryTreeInOderNonR(tree);

	BintryTreePostOrder(tree);
	printf("\n");
	BintryTreePostOrderNonR(tree);

	BintryTreeLeveOrder(tree);
	printf("\n");

	printf("%d\n",BintryTreeComplete(tree));

	system("pause");
	return 0;
}