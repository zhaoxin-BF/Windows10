#include"SeqListD.h"

int main()
{
	SeqListD s;
	Init(&s);
	PushBack(&s, 1);
	PushBack(&s, 2);
	PushBack(&s, 1);
	PushBack(&s, 2);

	PopBack(&s);
	Print(&s);

	system("pause");
	return 0;
}