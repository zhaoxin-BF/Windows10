//数组去零元素
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int arr[1000] = { 0 };
//	int i, j, tmp;
//	for (i = 0, j = 0; i<n; i++)
//	{
//		cin >> tmp;
//		if (tmp != 0)
//		{
//			arr[j] = tmp;
//			j++;
//		}
//	}
//	for (i = 0; i < j; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	system("pause");
//	return 0;
//}

//大写转小写，小写转大写
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	int i;
//	for (i = 0; i < s.size(); i++)
//	{
//		if ('A' <= s[i] && s[i] <= 'Z')
//			s[i] = s[i] + 32;
//		else
//		{
//			s[i] = s[i] - 32;
//		}
//	}
//	cout << s;
//	system("pause");
//	return 0;
//}



//三个数排序
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a, b, c;
//	int tmp;
//	cin >> a >> b >> c;
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	cout << a << " " << b << " " << c << " " << endl;
//	system("pause");
//	return 0;
//}

//大写转小写
//#include <iostream>
//
//using namespace std;
//int main() {
//	char a;
//	cin >> a;
//	a = a + 32;
//	cout << a ;
//	system("pause");
//}

//找出数组最大的元素
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int arr[100] = { 0 };
//	int tmp,i;
//	for (i = 0; i<n; i++)
//	{
//		cin >> tmp;
//		arr[i] = tmp;
//	}
//	int max = 0;
//	for (i = 1; i<n; i++)
//	{
//		if (arr[max] < arr[i])
//			max = i;
//	}
//	cout << arr[max] << " " << max;
//	system("pause");
//	return 0;
//}


//打印图案
//#include <iostream>
//#include <stdio.h>
//
//using namespace std;
//
//int zhishu(int a, int x)
//{
//	int i,ret = 1;
//	for (i = 0; i < x; i++)
//	{
//		ret = ret*a;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int i, j;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= n-i; j++)
//		{
//			cout << " ";
//		}
//		for (j = 1; j <=i*2-1; j++)
//		{
//			cout << '*';
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
