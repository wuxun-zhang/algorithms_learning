#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// 计算两个二进制字符串的和，结果仍用二进制表示
// 类似于计算两个单链表表示的十进制数的和

string addBinary(string a, string b)
{
	if (a.empty() || b.empty())
		return "";
	string result;
	string::size_type len_a = a.size(), len_b = b.size();
	int i = len_a-1, j = len_b-1, sum = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			sum += a[i--] - '0';
		if (j >= 0)
			sum += b[j--] - '0';
		result = to_string(sum % 2) + result;
		sum /= 2;
	}
	if (sum)
		result = to_string(sum) + result;
	return result;
}



void main()
{
	string a, b;
	while (cin >> a >> b)
	{
		cout << addBinary(a, b) << endl;
	}
}

