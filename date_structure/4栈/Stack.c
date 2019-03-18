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
	PushStack(&s, 6);

	PopStack(&s);
	printf("top = %d \n",TopStack(&s));
	PrintStack(&s);
	getchar();
	return 0;
}

















//#include"Stack.h"
//
//int main()
//{
//	Stack s;
//	InitStack(&s);
//	PushStack(&s, 1);
//	PushStack(&s, 2);
//	PushStack(&s, 3);
//	PushStack(&s, 4);
//	PushStack(&s, 5);
//
//	PopStack(&s);
//	printf("top = %d\n", TopStack(&s));
//
//	PrintStack(&s);
//	getchar();
//	return 0;
//}
