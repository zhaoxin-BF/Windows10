#include"Stack.h"

int main()
{
	Stack s;
	InitStack(&s);
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	PushStack(&s, 4);
	PushStack(&s, 5);
	PushStack(&s, 6);
	PushStack(&s, 7);

	PrintStack(&s);
	getchar();
	return 0;
}