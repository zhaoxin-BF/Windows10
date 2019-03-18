#include"Lise.h"



int main()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintSList(&pHead);
	
	SListPopBack(&pHead);
	SListPopBack(&pHead);

	RetSList(&pHead);
	TRetSlist(&pHead);
	PrintSList(&pHead);

	getchar();
	system("pasue");
	return 0;

}

