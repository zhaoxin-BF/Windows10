#include"SeqList.h"

int main()
{
	PSeqList ps;
	InitSeqList(&ps);
	PushBackSeqList(&ps, 2);
	PushBackSeqList(&ps, 3);
	PushBackSeqList(&ps, 4);
	PushBackSeqList(&ps, 5);
	PushBackSeqList(&ps, 2);
	PushBackSeqList(&ps, 2);
	PushBackSeqList(&ps, 3);
	PushBackSeqList(&ps, 4);
	PushBackSeqList(&ps, 5);
	PushBackSeqList(&ps, 2);

	//PopBackSeqList(&ps);

	//PopFrontSeqList(&ps);
	/*InsertSeqList(&ps,6,1);*/

	//EarseSeqList(&ps,5);
	/*RemoveAllSeqList(&ps,2);*/

	PrintSeqList(&ps);
	printf("Size = %d \n", SizeSeqList(&ps));

	BubbleSort(&ps);
	PrintSeqList(&ps);

	SelectSort(&ps);
	PrintSeqList(&ps);

	getchar();
	return 0;
}