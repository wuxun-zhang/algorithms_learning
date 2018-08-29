#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		string curStr = "1";
		string preStr;
		for (int i = 1; i < n; i++)
		{
			int count = 1;
			for (string::size_type k = 0; k != curStr.size();)
			{
				if (curStr.size() <= 1)
				{
					preStr = to_string(count) + curStr[0];
					break;
				}
				else
					k++;

				if (curStr[k] == curStr[k - 1])
					count++;
				else
				{
					preStr += to_string(count) + curStr[k - 1];
					count = 1;
				}
			}
			curStr = preStr;
			preStr = "";
		}
		return curStr;
	}
};

void main()
{
	int n;
	Solution sol;
	cout << "请输入一个整数：";
	while (cin >> n)
	{
		cout << (sol.countAndSay(n)) << endl;
	}
}