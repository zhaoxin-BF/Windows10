#include"SList.h"

int main()
{
	PNode s;
	InitSList(&s);

	PushbackSList(&s, 1);
	PushbackSList(&s, 2);
	PushbackSList(&s, 3);
	PushbackSList(&s, 4);
	PushbackSList(&s, 5);

	InsertSList(&s,2,10);
	EarseSList(&s,2);

	PopbackSList(&s);

	PrintSList(&s);

	printf("%d \n",FindNum(&s,4));



	getchar();

	return 0;
}