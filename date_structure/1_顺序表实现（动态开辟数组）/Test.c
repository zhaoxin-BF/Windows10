#include"SeqListD.h"

int main()
{
	SeqListD s;
	SeqListDInit(&s);

	SeqListDPushBack(&s, 1);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);

	PrintSeqListD(&s);
	printf("size = %d\n", SeqListDSize(&s));
	printf("capacity = %d\n", SeqListDCapacity(&s));

	SeqListDPushBack(&s, 4);
	printf("size = %d\n", SeqListDSize(&s));
	printf("capacity = %d\n", SeqListDCapacity(&s));

	SeqListDPopBack(&s);
	printf("size = %d\n", SeqListDSize(&s));
	printf("capacity = %d\n", SeqListDCapacity(&s));

	SeqListDClear(&s);
	printf("size = %d\n", SeqListDSize(&s));
	printf("capacity = %d\n", SeqListDCapacity(&s));

	PrintSeqListD(&s);
	getchar();
	return 0;
}