#include"Queue.h"

int main()
{
	Queue q;
	InitQueue(&q);

	PushQueue(&q, 0);
	PushQueue(&q, 1);
	PushQueue(&q, 1);
	PushQueue(&q, 1);
	PushQueue(&q, 1);
	PushQueue(&q, 1);
	PushQueue(&q, 1);

	//PopQueue(&q);

	printf("%d\n",SizeQueue(&q));

	PrintQueue(&q);
	getchar();
	return 0;
}