#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n>>m;
	int array[3000] = { 0 };
	int i, tmp = 0, tmpp;
	array[0] = 1;

	for (i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3000; j++)
		{
			tmpp = i*array[j];
			array[j] = (tmpp + tmp) % 10;
			tmp = (tmpp + tmp) / 10;
		}
	}
	for (i = m-1; i >= 0;i--)
	{
		cout << array[i];
	}
	system("pause");
}



//Çó´óÊı½×³Ë
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int array[3000] = { 0 };
//	int i,tmp = 0,tmpp;
//	array[0] = 1;
//
//	for (i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < 3000; j++)
//		{
//			tmpp = i*array[j];
//			array[j] = (tmpp + tmp) % 10;
//			tmp = (tmpp + tmp) / 10;
//		}
//	}
//	i = 3000-1;
//	while (!array[i])
//	{
//		i--;
//	}
//	for (; i >=0; i--)
//	{
//		cout << array[i];
//	}
//	system("pause");
//}