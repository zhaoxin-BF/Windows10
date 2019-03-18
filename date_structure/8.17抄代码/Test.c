#include"Queue.h"
int main()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	//QueuePop(&q);

	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));

	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueEmpty(&q));

	PrintQueue(&q);

	system("pause");
	return 0;
}