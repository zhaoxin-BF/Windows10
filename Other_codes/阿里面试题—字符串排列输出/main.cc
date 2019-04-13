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
	vector<int>::iterator right = left; //rightָ������һ��
	--left;//leftָ�����ڶ�������

	//�ҳ���һ����С�Ҵ����
	while (right != v.begin() && *left >= *right)
	{
		if (--right != v.begin())
		{
			--left;
		}
	}

	if (right == v.begin())                         //��right�ߵ��ʼ��λ�ã���ʾȫ���Ѿ����꣬����Ҫ�ڽ�������
	{
		reverse(right, v.end());
		return false;
	}

	vector<int>::iterator last = v.end() - 1;       //ָ�����һ����
	while (*last <= *left)                          //�ҳ����������һ����left�������
	{
		--last;
	}

	swap(*left, *last);                             //��last��left���н���
	reverse(right, v.end());                        //�ڽ�right��������ݽ�������

	return true;
}
void Print(vector<int>& v)
{
	vector<int>::iterator it1 = v.begin();          //��ӡ����������Ϊvector���Σ����õ��������ʺ�ǿ������ת�����
	while (it1 != v.end())
	{
		char c = *it1;
		cout << c;
		++it1;
	}
	cout << endl;

}

bool cmp(int a, int b)                         //STL�����㷨���
{
	return a < b;
}

int main()
{
	clock_t start, stop;
	start = clock();
	vector<int> v;                             //����vector�����洢�ַ���Ascall�룬�������յ����С�
	string s;                                  //�����ַ���
	cin >> s;
	int tmp = 0;
	string::iterator it = s.begin();
	while (it != s.end())                       //���ַ����ֽ�Ϊ�ַ��������ַ���Ascall���������v�У���������
	{
		tmp = (int)*it;                         //ǿ������ת��Ϊ���Σ�������������v�С�
		v.push_back(tmp);
		++it;
	}
	sort(v.begin(), v.end(), cmp);              //��vector�����ݽ����������Ժ���������
	vector<int>::iterator first = v.begin();
	vector<int>::iterator last = v.end();
	int count = 0;
	do
	{
		Print(v);
		count++;

	} while (perm(v));                          //ѭ������
	system("pause");                            //��ͣ����VS�����µ��������
}