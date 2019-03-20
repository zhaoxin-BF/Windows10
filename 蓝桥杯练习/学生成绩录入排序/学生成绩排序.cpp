#include<iostream>
#include<string>
using namespace std;

typedef struct student
{
	string _name;
	string _sex;
	int _age;
	int _score;
}stu;

int main()
{
	stu arr[1000];
	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i]._name >> arr[i]._sex >> arr[i]._age >> arr[i]._score;
	}
	int j, k;
	stu tmp;
	for (j = 1; j < n; j++){
		for (k = 0; k < n - j; k++){
			if (arr[k]._score > arr[k + 1]._score)
			{
				tmp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = tmp;
			}
		}
	}
	for ( i = 0; i < n; i++)
	{
		cout << arr[i]._name << " " << arr[i]._sex << " " << arr[i]._age << " " << arr[i]._score<<endl;
	}
	system("pause");
	return 0;
}