////////////////////////////
//ǰK��Ƶ���� ���� ,����map ת���������
//#include <iostream>
//#include <map>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//bool com(pair<int, int>& a, pair<int, int>& b) {
//	return a.second > b.second;
//}
//
// 
//int main()
//{
//	map<int, int> mp;
//	int n = 40;
//	int arr[40] = { 1,2,3,4,5,6,7,8,9,10,
//					1,2,3,5,6,8,7,9,4,15,
//					4,8,5,4,7,6,1,4,1,10,
//					1,5,7,4,6,8,2,5,5,5};
//	char c;
//	for (int i = 0; i < n; i++) 
//	{
//		if (mp.find(arr[i]) != mp.end()) {
//			auto it = mp.find(arr[i]);
//			it->second += 1;
//		}
//		else
//		{
//			mp.insert(make_pair(arr[i], 1));
//		}
//	}
//	map<int, int> sort_mp;
//	int k = 5;
//	n = 0;
//	for (auto e : mp) {
//		sort_mp.insert(make_pair(e.second,e.first));
//	}
//
//	for (auto e : mp) {
//		cout << e.first << "   " << e.second << endl;
//	}
//
//	auto e = sort_mp.rbegin();
//	while (e != sort_mp.rend())
//	{
//		cout << "����" <<e->second << "   �У�" << e->first<< "��" << endl;
//		e++;
//		n++;
//		if (n == k)
//			break;
//	}
//	return 0;
//}

////////////////////////////////////
//ǰK ��Ƶͳ�� map������vector�������ǰK��Ƶ����
//#include <iostream>
//#include <map>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//bool com(pair<int, int>& a, pair<int, int>& b) {
//	return a.second > b.second;
//}
//
// 
//int main()
//{
//	map<int, int> mp;
//	int n = 40;
//	int arr[40] = { 1,2,3,4,5,6,7,8,9,10,
//					1,2,3,5,6,8,7,9,4,15,
//					4,8,5,4,7,6,1,4,1,10,
//					1,5,7,4,6,8,2,5,5,5};
//	char c;
//	for (int i = 0; i < n; i++) 
//	{
//		if (mp.find(arr[i]) != mp.end()) {
//			auto it = mp.find(arr[i]);
//			it->second += 1;
//		}
//		else
//		{
//			mp.insert(make_pair(arr[i], 1));
//		}
//	}
//	vector<pair<int, int>> v;
//	for (auto e : mp) {
//		v.push_back(e);
//	}
//	sort(v.begin(), v.end(), com);
//
//	for (auto e : v) {
//		cout << "����" << e.first << "ֵ��" << e.second << endl;
//	}
//	return 0;
//}


/////////////////////////////////////
//vector ����

//#include <iostream>
//#include <map>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool com(int &a, int &b)
//{
//	return a > b;
//}
//
//int main() {
//	vector<int> v;
//	int n=10;
//	for (int i = n; i > 0; i--) {
//		v.push_back(i);
//	}
//	cout << v.size() << endl;
//	cout << "��һ���������������" << endl;
//	v.push_back(4);
//	cout << v.size()<<endl;
//	for (auto e : v) {
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << "�ڶ���Ĭ���������������" << endl;
//
//	sort(v.begin(), v.end());
//	for (auto e : v) {
//		cout << e << " ";
//	}
//
//	cout << endl;
//	cout << "�����δ�С�������������" << endl;
//
//	sort(v.begin(), v.end(), com);
//	for (auto e : v) {
//		cout << e << " ";
//	}
//
//	return 0;
//}
//



////////////////////////////////////
//���ȼ����е�ʹ�ü���ϰ
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main() 
//{
//	priority_queue<int> p;
//	priority_queue<int, vector<int>, greater<int>> q;
//	for (int i = 0; i < 10; i++) {
//		p.push(i);
//	}
//	while (!p.empty()) {
//		cout << "Ԫ��" << p.top() << endl;
//		p.pop();
//	}
//
//	for (int i = 0; i < 10; i++) {
//		q.push(i);
//	}
//	while (!q.empty()) {
//		cout << "Ԫ��" << q.top() << endl;
//		q.pop();
//	}
//
//	return 0;
//}


/////////////////////////////////////////
//���ȼ����и߽�ʹ�ã��Զ������͵�ʹ��

//#include <iostream>
//#include <queue>
//using namespace std;
//
//
//
//
//class fruit {
//public:
//	friend bool operator < (fruit f1, fruit f2) {
//		return f1.price > f2.price;
//	}
//public:
//	string name;
//	int price;
//};
//
//int main()
//{
//	priority_queue<fruit> p;
//	fruit f1, f2, f3;
//	f1.name = "����";
//	f1.price = 13;
//	f2.name = "ƻ��";
//	f2.price = 45;
//	f3.name = "����";
//	f3.price = 8;
//
//	p.push(f1);
//	p.push(f2);
//	p.push(f3);
//
//	while (!p.empty()) {
//		cout << p.top().name << ": " << p.top().price << endl;
//		p.pop();
//	}
//	return 0;
//}



///////////////////////////////////////////////
//priority_queue �߼��÷����ж�map.secondԪ�ؽ��н���С�ѽ������
//ע�������Ҫ��д�º�����
#include <iostream>
#include <queue>
#include <map>
using namespace std;



//�º���
class com {
public:
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		return p1.second < p2.second;
	}
};

//�º�����������������еķº���
struct cmp {
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		//Ĭ����less����
		//����trueʱ��a�����ȼ�����b�����ȼ���a����b�ĺ��棩
		return p1.second < p2.second;
	}
};

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, com > p;
	map<int, int> mp;
	int n = 40;
	int arr[40] = { 1,2,3,4,5,6,7,8,9,10,
					1,2,3,5,6,8,7,9,4,15,
					4,8,5,4,7,6,1,4,1,10,
					1,5,7,4,6,8,2,5,5,5};
	char c;
	for (int i = 0; i < n; i++) 
	{
		if (mp.find(arr[i]) != mp.end()) {
			auto it = mp.find(arr[i]);
			it->second += 1;
		}
		else
		{
			mp.insert(make_pair(arr[i], 1));
		}
	}
	for (auto e : mp) {
		p.push(e);
	}
	
	while(!p.empty())
	{
		cout << "����" << p.top().first << "ֵ��" << p.top().second << endl;
		p.pop();
	}

	return 0;

}