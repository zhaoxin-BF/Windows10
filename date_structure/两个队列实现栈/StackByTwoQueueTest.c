#include"StackByTwoQueue.h"
int main()
{
	Stack s;
	StackByTwoQueueInit(&s);

	StackByTwoQueuPush(&s, 1);
	StackByTwoQueuPush(&s, 2);
	StackByTwoQueuPush(&s, 3);

	StackByTwoQueuePop(&s);

	StackByTwoQueuPush(&s, 3);

	printf("StackTop = %d\n", StackByTwoQueueTop(&s));
	printf("StackTop = %d\n", StackByTwoQueueBack(&s));
	printf("StackSize = %d\n",SizeStack(&s));

	PrintStackByTwoQueueBack(&s);
	system("pause");
	return 0;
}