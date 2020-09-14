#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>//栈
#include<sstream>//字符流,处理单词类的问题
#include<queue>//队列
#include<map>//树状结构,有序
#include<unordered_map>//哈希结构,无序,快
#include<set>//树状结构,有序
#include<unordered_set>//哈希结构,无序,快
#include<deque>//可从头插也可从尾插
#include<list>

using namespace std;

//涉及逆序又不知道总长的题可以考虑stack+while
//用stack把10进制转为2进制
int itob(int decimal) {
	stack<int> s;
	int res = 0;
	while (decimal != 0) {
		s.push(decimal % 2);
		decimal /= 2;
	}
	while (!s.empty()) {
		res = res * 10 + s.top();
		s.pop();
	}
	return res;
}

//
bool div5(int x) {
	return x%5==0;
}
int main() {
	//-----------------1.string-----------------------
	//cout << "请输入字符串：" << endl;
	//string s;
	//getline(cin, s);//获取1行字符串

	//s += "az";//字符串追加
	//cout << "追加后：" << s << endl;// 输出字符串

	//sort(s.begin(), s.end());//排序
	//cout << "排序后：" << s << endl;

	//s.erase(s.begin());//擦除第一个
	//s.erase(--s.end());//擦除最后一个
	//cout << "擦除首尾后：" << s << endl;

	//s=s.substr(1, -1); //取索引为1到最后的切片/子字符串
	//cout << "基于范围的循环输出：";
	//for (auto x : s) //基于范围的循环
	//	cout << x;
	//cout << endl;
	
	//-----------------2.vector-----------------------
	vector<int> a;//定义一个空vector
	a.push_back(5);//追加
	a.push_back(6);
	a.resize(5);//大小通过补0变为10
	a.erase(a.begin());//删除第一个
	cout << "a现在的大小为：" << a.size() << endl;
	cout << "输出a:" << endl;
	for (auto x : a) cout << x << ' ';//基于范围的循环
	cout << endl;

	vector<int> b(8, 6);//长度8，初始都为6
	vector<int> c(4);//长度4，初始都为0
	vector<int> d{ 3,1,4,1,5,9,2,6 };//直接定义+初始化
	cout << "输入一个长度为8的数组b：";
	for (int i = 0;i < 8;i++) {
		cin >> b[i];
	}
	cout << "打印b1:" << b[1] << endl;
	cout << "打印b2:" << b.at(2) << endl;
	sort(b.begin(), b.end(), greater<int>());//第三个参数为比较器,不写默认从小到大
	cout << "将b排序后输出:";
	for (auto x : b) cout << x << ' ';
	cout << endl;

	//find函数
	int val;
	cout << "请输入查找目标:";
	cin >> val;
	auto it = find(b.begin(), b.end(), val);
	if (it != b.end())
		cout << val << "的位置是:" << it - b.begin() << endl;
	else
		cout << "未找到" << endl;

	//find_if函数
	auto itif = find_if(b.begin(), b.end(), div5);
	if (itif != b.end())
		cout << "能被5整除的位置是:" << itif - b.begin() << endl;
	else
		cout << "b中没有能被5整除的数" << endl;

	//find_first_of函数
	auto itof = find_first_of(b.begin(), b.end(), a.begin(), a.end());
	if (itof != b.end())
		cout << "b中第一次出现a的位置是:" << itof - b.begin() << endl;
	else
		cout << "b未找到a中的元素" << endl;

	//-----------------3.stack-----------------------
	//stack<int> s;//定义一个空stack
	//s.push(2);//入栈
	//s.push(3);
	//cout << s.top() << endl;//,取栈顶元素,后进先出
	//s.pop();//出栈,无返回值
	//cout << s.top() << endl;
	//cout << "现在大小为:" << s.size() << endl;

	//cout << "4转二进制" << itob(4) << endl;
	//
	////将字符串逆序打印
	//string str;
	//cout << "请输入一句话:";
	//getline(cin, str);
	//stringstream ss;
	//ss << str;//把一段话一起流入
	//stack<string> st;
	//while (ss >> str) {//一次流出一个单词
	//	st.push(str);
	//}
	//while (!st.empty()) {
	//	cout << st.top();
	//	st.pop();
	//	if (!st.empty()) cout << ' ';
	//}
	//cout << endl;

	////字符串转数字
	//string str1 = "1234";
	//stringstream ss1;
	//cout << str1 << endl;
	//ss1 << str1;
	//int i;
	//ss1 >> i;
	//cout << i + 5 << endl;
	////字符串转数字方法2
	//int ii;
	//cout << stoi(str1) + 5 << endl;
	//cout << to_string(i)+'5' << endl;//数字转字符串

	//-----------------4.quene-----------------------
	//queue<int> q;
	//q.push(5);
	//q.push(6);
	//cout << q.front() << endl;
	//q.pop();
	//cout << q.front() << endl;
	//cout << q.size() << endl;

	//-----------------5.map-----------------------
	//map<int, int> m;//有序的树状结构
	//m[6] = 3;
	//m[4] = 9;
	//m[5] = 2;
	//for (auto x:m)
	//	cout << x.first << ' ' << x.second << endl;
	//cout << endl;

	//unordered_map<int, int> um;//无序的哈希结构,不可排序
	//um[6] = 3;
	//um[4] = 9;
	//um[5] = 2;
	//for (auto x : um)
	//	cout << x.first << ' ' << x.second << endl;
	//cout << endl;

	//vector<pair<int, int>> v(um.begin(), um.end());//转成vector
	//sort(v.begin(), v.end(), greater<pair<int, int>>());//后排序
	//for (auto x : v) cout << x.first << ' ' << x.second << endl;


	//-----------------6.set-----------------------
	//set<int> s;
	//s.insert(3);
	//s.insert(3);
	//s.insert(4);
	//cout << s.size() << endl;//无重复
	//for (auto x : s) cout << x << ' ';
	//cout << endl;


	//-----------------7.deque-----------------------
	//deque<int> d;
	//d.push_back(1);//插入
	//d.push_back(2);
	//d.push_front(3);
	//d.push_front(4);
	//for (auto x : d) cout << x << ' ';
	//cout << endl;

	//d.pop_back();//删除
	//d.pop_front();
	//for (auto x : d) cout << x << ' ';
	//cout << endl;
	//
	//sort(d.begin(), d.end());//排序
	//for (auto x : d) cout << x << ' ';
	//cout << endl;


	//-----------------8.list-----------------------
	//list<int> li;
	//li.push_back(6);
	//li.push_front(5);
	//li.insert(++li.begin(), 7);
	//for (auto x : li) cout << x << ' ';
	//cout << endl;


	return 0;
}
