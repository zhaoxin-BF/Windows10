#include "List.h"

int main()
{
	PNode p,p1,p2;
	InitList(&p);
	PushBack(&p, 1);
	PushBack(&p, 2);
	PushBack(&p, 3);	
	PushBack(&p, 4);
	PushBack(&p, 5);
	PushBack(&p, 6);
	PushBack(&p, 7);

	InitList(&p1);
	PushBack(&p1, 3);
	PushBack(&p1, 4);
	PushBack(&p1, 5);
	PushBack(&p1, 6);
	PushBack(&p1, 7);
	PushBack(&p1, 8);
	PushBack(&p1, 9);

	PrintList(p);
	PrintList(p1);
	p2 = UnConnectTwoList(&p, &p1);

	PrintList(p2);
	system("pause");
	return 0;
}
