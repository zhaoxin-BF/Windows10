#include"SList.h"
int main()
{
	List lt;
	SListInit(&lt);
	SListNode* cur;

	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 4);
	SListPushBack(&lt, 5);

	SListPushFront(&lt, 0);

	SListPopBack(&lt);
	SListPopFront(&lt);

	printf("%d \n",SListFind(&lt, 7));
	printf("Size = %d \n", SListSize(&lt));

	//SListDestory(&lt);


	SListPrint(&lt);

	system("pause");
	return 0;
}