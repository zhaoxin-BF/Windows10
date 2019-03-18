#include"Paixu.h"

int main()
{
	PGrade grade;
	InitGrade(&grade);

	PushGrade(&grade, 101, 88);
	PushGrade(&grade, 102, 15);
	PushGrade(&grade, 103, 222);
	PushGrade(&grade, 104, 60);
	PushGrade(&grade, 105, 77);
	PushGrade(&grade, 106, 100);
	PushGrade(&grade, 107, 2);
	PushGrade(&grade, 108, 47);

	PrintGrade(&grade);


	printf("\n\n≈≈–Ú∫Û£∫\n");
	SelectGrade(&grade);

	PrintGrade(&grade);

	getchar();
	return 0;
}