#include<iostream>
#include<string>
using namespace std;

//(标准IO中的cin>>在读取数据时，均是以空格等空白字符为结束字符)

// 返回字符串中最后一个单词的长度，没有则返回零

// hello world
//   hello 
// (space)
// Method1：istringstream
int lengthOfLastWord(const string& s)
{
	if (s.empty())
		return 0;
	istringstream is(s);
	string word;
	while (is >> word);	// 不断将字符串流中的单词写入word中，不包括空格
	return word.size();
}

// Method2
int lengthOfLastWord_v2(const string& s)
{
	if (s.empty())
		return 0;
	int cnt = 0;
	int i = s.size() - 1;
	while (i >= 0 && s[i] == ' ')
		i--;	// 从右找到第一个非空格字符
	while (i >= 0 && s[i] != ' ')
	{
		cnt++;	// 直到遇见下一个空格字符结束
		i--;
	}
	return cnt;
}

void main()
{
	string s;
	while (getline(cin, s))
	{
		cout << lengthOfLastWord(s) << endl;
	}
}
