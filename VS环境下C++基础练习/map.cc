////////////////////////////
//前K高频单词 个数 ,两次map 转换倒叙输出
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
//		cout << "键：" <<e->second << "   有：" << e->first<< "个" << endl;
//		e++;
//		n++;
//		if (n == k)
//			break;
//	}
//	return 0;
//}

////////////////////////////////////
//前K 高频统计 map计数，vector排序，输出前K高频单词
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
//		cout << "键：" << e.first << "值：" << e.second << endl;
//	}
//	return 0;
//}


/////////////////////////////////////
//vector 排序

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
//	cout << "第一次输出。。。。。" << endl;
//	v.push_back(4);
//	cout << v.size()<<endl;
//	for (auto e : v) {
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << "第二次默认输出。。。。。" << endl;
//
//	sort(v.begin(), v.end());
//	for (auto e : v) {
//		cout << e << " ";
//	}
//
//	cout << endl;
//	cout << "第三次从小输出。。。。。" << endl;
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
//优先级队列的使用简单练习
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
//		cout << "元素" << p.top() << endl;
//		p.pop();
//	}
//
//	for (int i = 0; i < 10; i++) {
//		q.push(i);
//	}
//	while (!q.empty()) {
//		cout << "元素" << q.top() << endl;
//		q.pop();
//	}
//
//	return 0;
//}


/////////////////////////////////////////
//优先级队列高阶使用，自定义类型的使用

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
//	f1.name = "桃子";
//	f1.price = 13;
//	f2.name = "苹果";
//	f2.price = 45;
//	f3.name = "梨子";
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
//priority_queue 高级用法，判断map.second元素进行建大小堆进行输出
//注意事项：需要重写仿函数，
#include <iostream>
#include <queue>
#include <map>
using namespace std;



//仿函数
class com {
public:
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		return p1.second < p2.second;
	}
};

//仿函数，必须包含在类中的仿函数
struct cmp {
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		//默认是less函数
		//返回true时，a的优先级低于b的优先级（a排在b的后面）
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
		cout << "键：" << p.top().first << "值：" << p.top().second << endl;
		p.pop();
	}

	return 0;

}