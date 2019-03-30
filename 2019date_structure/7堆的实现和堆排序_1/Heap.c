#include "Heap.h"

int main()
{
	Heap hp;
	_HPDataType array[] = { 12, 34, 56, 76, 87, 97, 46, 64, 62, 25, 85, 99, 88, 77, 950 };
	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]));

	SortHeap(&hp);

	Print(&hp);

	system("pause");
	return 0;
}