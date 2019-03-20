#include<iostream>
using namespace std;

void Swap(int& a, int& b)
{
	a = a - b;
	b = a + b;
	a = b - a;
}

void Print(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void sinsert(int array[], int size)
{
	int i, j, tmp;
	for (i = 1; i < size; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] > array[i])
				;
			else
			{
				break;
			}
		}
		tmp = i;
		while (tmp != j + 1)
		{
			Swap(array[tmp], array[tmp - 1]);
			tmp--;
		}
	}
}

int main()
{
	int n;
	int array[200] = { 0 };
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	sinsert(array, n);

	Print(array, n);
	system("pause");
	return 0;
}