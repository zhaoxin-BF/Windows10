#include"Test.h"

int main()
{
	Stack s;
	InitStack(&s);

	PushBackStack(&s, 1);
	PushBackStack(&s, 2);
	PushBackStack(&s, 3);
	PushBackStack(&s, 4);
	PushBackStack(&s, 5);
	PushBackStack(&s, 6);
	PopBackStack(&s);

	printf("size = %d \n",SizeStack(&s));
	PrintStack(s);
	system("pause");
	return 0;


}