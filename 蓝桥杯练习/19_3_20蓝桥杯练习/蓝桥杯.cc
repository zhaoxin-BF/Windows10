
//判断字母大小
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	char c;
//	if ('A' <= c&&c <= 'Z')
//	{
//		cout << "upper";
//	}
//	if ('a' <= c && c <= 'z')
//		cout << "lower";
//	system("pause");
//	return 0;
//}

//打印图案*
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	int i,j;
//	cin >> n;
//	for (i = n; i > 0; i--)
//	{
//		for (j = 1; j <= i;j++)
//		{
//			cout << "*"<<" ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//对比字符串是否相同
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int judge(string a, string b,int n)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		if (a[i] != b[i])
//			return 0;
//	}
//	return 1;
//}
//
//int sum(string a, string b, int n)
//{
//	int i, sa = 0, sb = 0;
//	for (i = 0; i < n; i++)
//	{
//		sa += 'a[i]';
//		sb += 'b[i]';
//	}
//	if (sa == sb)
//		return 1;
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//	if (a.size() != b.size())
//	{
//		cout << "N" << endl;
//		return 0;
//	}
//	int i;
//	for (i = 0; i < a.size(); i++)
//	{
//		if ('A' <= a[i] && a[i] <= 'Z')
//			a[i] = a[i] + 32;
//		if ('A' <= b[i] && b[i] <= 'Z')
//			b[i] = b[i] + 32;
//	}
//	cout << sum(a, b, a.size());
//	/*if (judge(a, b, a.size())||sum(a,b,a.size()))
//	{
//		cout << "Y"<<endl;
//	}
//	else
//	{
//		cout << "N" << endl;
//	}*/
//	system("pause");
//	return 0;
//}


//输出最小公倍数
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int i,a, b;
//	cin >> a >> b;
//	for (i = 1;; i++)
//	{
//		if ((a*i) % b == 0)
//			break;
//	}
//	cout << a*i << endl;
//	system("pause");
//	return 0;
//}


//求水仙花数
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n,s,b,g;
//	cin >> n;
//	b = n / 100;
//	s = n % 100 / 10;
//	g = n % 100 % 10;
//	if (b*b*b + s*s*s + g*g*g == n)
//		cout << "Yes" << endl;
//	else
//		cout << "No"<<endl;
//	system("pause");
//	return 0;
//}


//判断是否为完数
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int sum = 0;
//	int i;
//	for (i = 1; i <= n/2; i++)
//	{
//		if (n%i == 0)
//		{
//			sum = sum + i;
//		}
//	}
//	if (sum == n)
//		cout << "YES" << endl;
//	else
//		cout << "NO" << endl;
//	system("pause");
//	return 0;
//}

//三个数排序
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//
//int main()
//{
//	vector<int> s;
//	int tmp, i;
//	for (i = 0; i < 3; i++)
//	{
//		cin >> tmp;
//		s.push_back(tmp);
//	}
//	sort(s.begin(), s.end(), cmp);
//	for (int i = 0; i < 3; i++)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}


//简单加法

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int i,sum = 0;
//	for (i = 3; i < 1000; i++)
//	{
//		if (i % 3 == 0 || i % 5 == 0)
//		{
//			sum += i;
//		}
//	}
//	cout << sum<<endl;
//	system("pause");
//	return 0;
//}




//打印完数
#include <iostream>

using namespace std;

int main()
{
	int sum;
	int i,j;
	for (j = 1; j < 9999; j++)
	{
		sum = 0;
		for (i = 1; i <= j / 2; i++)
		{
			if (j%i == 0)
			{
				sum = sum + i;
			}
		}
		if (sum == j)
		{
			cout << j << endl;
		}
	}
	system("pause");
	return 0;
}