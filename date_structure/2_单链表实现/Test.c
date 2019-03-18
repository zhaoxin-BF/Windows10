#include"List.h"

int main()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);

	SListPushFront(&pHead, 0);
	SListPopBack(&pHead);
	//SListPopFront(&pHead);

	PrintSList(pHead);
	getchar();
	return 0;
}