#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

bool perm(vector<int>& v)
{
	vector<int>::iterator left = v.end();
	--left;
	vector<int>::iterator right = left; //right指向倒数第一个
	--left;//left指向倒数第二个数字

	//找出第一对左小右大的数
	while (right != v.begin() && *left >= *right)
	{
		if (--right != v.begin())
		{
			--left;
		}
	}

	if (right == v.begin())                         //当right走到最开始的位置，表示全部已经排完，不需要在进行排列
	{
		reverse(right, v.end());
		return false;
	}

	vector<int>::iterator last = v.end() - 1;       //指向最后一个数
	while (*last <= *left)                          //找出从右往左第一个比left大的数字
	{
		--last;
	}

	swap(*left, *last);                             //将last和left进行交换
	reverse(right, v.end());                        //在将right往后的数据进行逆置

	return true;
}
void Print(vector<int>& v)
{
	vector<int>::iterator it1 = v.begin();          //打印函数，参数为vector整形，利用迭代器访问后强制类型转换输出
	while (it1 != v.end())
	{
		char c = *it1;
		cout << c;
		++it1;
	}
	cout << endl;

}

bool cmp(int a, int b)                         //STL排序算法相关
{
	return a < b;
}

int main()
{
	clock_t start, stop;
	start = clock();
	vector<int> v;                             //创建vector用来存储字符的Ascall码，用以最终的排列。
	string s;                                  //输入字符串
	cin >> s;
	int tmp = 0;
	string::iterator it = s.begin();
	while (it != s.end())                       //将字符串分解为字符，并将字符的Ascall码存入容器v中，用以排列
	{
		tmp = (int)*it;                         //强制类型转换为整形，存入整形容器v中。
		v.push_back(tmp);
		++it;
	}
	sort(v.begin(), v.end(), cmp);              //对vector的数据进行排序，用以后续的排序
	vector<int>::iterator first = v.begin();
	vector<int>::iterator last = v.end();
	int count = 0;
	do
	{
		Print(v);
		count++;

	} while (perm(v));                          //循环排列
	system("pause");                            //暂停程序，VS环境下的特殊语句
}