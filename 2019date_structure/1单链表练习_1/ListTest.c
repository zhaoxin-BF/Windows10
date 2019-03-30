#include<stdio.h>
#include"List.h"

int main()
{
	PNode n;
	InitList(&n);
	PushBack(&n, 1);
	PushBack(&n, 2);
	PushBack(&n, 3);
	PushBack(&n, 4);
	PushBack(&n, 5);
	PushBack(&n, 6);
	PushBack(&n, 7);
	PushBack(&n, 8);
	RList(&n);

	PrintList(n);
	getchar();
	return 0;
}