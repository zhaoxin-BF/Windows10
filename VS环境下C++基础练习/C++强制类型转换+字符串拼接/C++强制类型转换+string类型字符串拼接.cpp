
#include <string>
#include<sstream>
#include <iostream>
using namespace std;

string Count(string str)
{
	string res = "";
	int i, n = 1;
	for (i = 1; i < str.size(); i++)
	{
		if (str[i-1] == str[i])
		{
			n++;
		}
		else
		{
			stringstream ss;
			ss << n;

			string count;
			ss >> count;

			res = res + count + str[i - 1];
			n = 1;
		}
	}
	stringstream ss;
	ss << n;

	string count;
	ss >> count;

	res = res + count + str[i - 1];

	return res;
}


int main()
{
	string str;
	cin >> str;
	cout << str << endl;

	string res = Count(str);
	cout << res << endl;

	system("pause");
	return 0;
}





int main01()
{
	////////////////////////////////////////////////////////////////////
	//整形转化为string类型，进行字符串拼接
	////////////////////////////////////////////////////////////////////
	//int a = 5;
	//stringstream ss;
	//ss << a;
	//
	//string s2;
	//ss >> s2;

	//string s = "a";
	//s = s2 + s;
	//cout << s << endl; // 30

	system("pause");
	return 0;
}



