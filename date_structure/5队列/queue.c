#include"queue.h"

int main()
{
	Queue q;
	InitQueue(&q);
	PushQueue(&q, 1);
	PushQueue(&q, 2);
	PushQueue(&q, 3);

	PopQueue(&q);

	printf("%d\n", QueueSize(&q));
	PrintQueue(&q);

	getchar();
	return 0;
}