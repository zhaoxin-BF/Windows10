#include"Stack.h"

int main()
{
	Stack s;
	InitStack(&s);

	PushbackStack(&s, 1);
	PushbackStack(&s, 2);
	PushbackStack(&s, 3);
	PushbackStack(&s, 4);

	PopbackStack(&s);

	int size = SizeStack(&s);
	printf("Size = %d\n", size);
	PrintStack(s);

	system("pause");
	return 0;
}