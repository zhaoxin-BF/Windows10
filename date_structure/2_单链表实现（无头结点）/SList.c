#include"SList.h"

int main()
{
	PNode s;
	InitSList(&s);
	PushBackSList(&s, 1,3);
	PushBackSList(&s, 2,1);
	PushBackSList(&s, 3,7);
	PushBackSList(&s, 4,2);
	PushBackSList(&s, 5,4);
	PushBackSList(&s, 6,8);
	PushBackSList(&s, 7,4);

	printf("Size = %d\n", SizeSList(&s));
	PrintSList(&s);
	JoseCycle(&s, 2);
	getchar();
	return 0;
}





















//int main()
//{
//	int size;
//	PNode pHead;
//	InitSList(&pHead);
//	PushBackSList(&pHead,1);
//
//	PushBackSList(&pHead, 2);
//	PushBackSList(&pHead, 3);
//	PushBackSList(&pHead, 9);
//
//	/*PopBackSList(&pHead);*/
//	//InsertSList(&pHead,3,6);
//	EarseSList(&pHead,1);
//
//    size = SizeSList(&pHead);
//	printf("Size = %d\n",size);
//	PrintSList(&pHead);
//	
//
//	getchar();
//	return 0;
//}