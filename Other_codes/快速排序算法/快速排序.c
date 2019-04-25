#include <stdio.h>

int quickSortPart(int a[], int left, int right)
{
	int temp = a[right];
	while (left<right)
	{
		while (left<right&&a[left]<temp)
		{
			left++;
		}
		a[right] = a[left];
		while (left < right&&a[right] >= temp)
		{
			right--;
		}
		a[left] = a[right];
	}
	a[right] = temp;
	return right;
}

void quickSort(int a[], int left, int right)
{
	if (left<right)
	{
		int mid = quickSortPart(a, left, right);
		quickSort(a, left, mid - 1);
		quickSort(a, mid + 1, right);
	}

}

void Print(int array[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[10] = { 1, 5, 8, 7, 4, 9, 6, 3, 2, 0 };
	int right = sizeof(array) / sizeof(array[0]) - 1;
	int left = 0;

	Print(array, right + 1);

	quickSort(array, left, right);
	Print(array, right + 1);

	printf("Hello world!\n");
	system("pause");
	return 0;
}