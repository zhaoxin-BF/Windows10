#include"Heap.h"
int main()
{
	Heap hp;
	_HPDataType array[] = { 12, 34, 56, 76, 87, 97, 46, 64, 62};
	InitHeap(&hp,array,sizeof(array)/sizeof(_HPDataType));
	//SortHeap(&hp);

	/*PopHeap(&hp);*/
	PushHeap(&hp, 123);
	//DestoryHeap(&hp);

	//printf("%d \n",TopHeap(&hp));

	PrintfHeap(&hp);
	system("pause");
	return 0;
}