

#include"string"
#include"iostream"
using namespace std;




int  main()
{
	string str;
	cin >> str;
	int length = str.length();
	int index = 0;
	int i;
	int j;
	for (i = 0; i<length; i = j)
	{
		index = 1;
		for (j = i + 1; j<length; ++j)
		{
			if (str[i] == str[j])
				index++;
			else
				break;
		}
		cout << index << str[i];
	}
	cout << endl;
	system("pause");
	return 0;
}