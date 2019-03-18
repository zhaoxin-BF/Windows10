#include"QueueByTwoStack.h"
int main()
{
	Queue q;
	QueueByTwoStackInit(&q);
	QueueByTwoStackPush(&q, 1);
	QueueByTwoStackPush(&q, 2);
	QueueByTwoStackPush(&q, 3);
	QueueByTwoStackPush(&q, 4);

	QueueByTwoStackPop(&q);

	QueueByTwoStackPush(&q, 5);
	QueueByTwoStackPush(&q, 6);

	printf("Front = %d\n",QueueByTwoStackFront(&q));
	printf("Tail  = %d\n", QueueByTwoStackBack(&q));

	printf("Queue size =%d\n", QueueByTwoStackSize(&q));

	PrintQueueByTwoStack(&q);

	system("pause");
	return 0;
}