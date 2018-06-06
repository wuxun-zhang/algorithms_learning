#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct base {
	base() :mem(123) {}
protected:
	int mem;
};

struct derived :public base {
	derived() = default;
	derived(int i) :mem(i) {}
	int get_mem()
	{
		return mem;
	}
protected:
	int mem;	// 与直接基类或间接基类相冲的变量优先查找当前作用域，若未找到再往外层（基类）作用域查找
};

//void main()
//{
//	/*derived A(233);
//	std::cout << A.get_mem() << std::endl;*/
//
//	const char* a = "asdhcnhdb";
//	vector<char> b(a, a+9);
//	string c(b.cbegin(), b.cend());
//	cout << c << endl;
//	//c.resize(15, '*');
//	//cout << c << endl;
//	//c.insert(2, 5, '!');
//	//cout << c << endl;
//	int idx = c.find('dh');
//	//c.erase(c.begin() + idx, c.end());
//	cout << idx << endl;
//
//	while (1)
//	{
//		string input;
//		cout << "输入一个字符串：" << endl;
//		cin >> input;
//		cout << "输入需要查找的子字符串：";
//		string substr;
//		cin >> substr;
//		int idx = input.rfind(substr);	// 从右往左搜索，返回第一个匹配的字符串的首字符位置
//		cout << "返回" << substr << "在" << input << "的索引：" << idx << endl;
//	}
//}
