#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int roman2integer(string s) {
		unordered_map<char, int> sym2val;
		sym2val.insert(make_pair('I', 1));
		sym2val.insert(make_pair('V', 5));
		sym2val.insert(make_pair('X', 10));
		sym2val.insert(make_pair('L', 50));
		sym2val.insert(make_pair('C', 100));
		sym2val.insert(make_pair('D', 500));
		sym2val.insert(make_pair('M', 1000));
		int length = s.size();
		int result = 0;
		bool isNeedMatch = false;
		for (int i = 0; i < length; i++) {
			result += sym2val[s[i]];
			if (isNeedMatch) {
				if (s[i - 1] == 'I' && (s[i] == 'X' || s[i]=='V'||s[i]=='L'||s[i]=='C'||s[i]=='D'||s[i]=='M')) {
					result-=2*1;
					isNeedMatch = false;
					continue;
				}
				else if (s[i - 1] == 'V' && (s[i] == 'X' || s[i] == 'L' || s[i] == 'C' || s[i] == 'D' || s[i] == 'M'))
				{
					result -= 2*5;
					isNeedMatch = false;
					continue;
				}
				else if (s[i - 1] == 'X' && (s[i] == 'L' || s[i] == 'C' || s[i] == 'D' || s[i] == 'M'))
				{
					result -= 2*10;
					isNeedMatch = false;
					continue;
				}
				else if (s[i - 1] == 'L' && (s[i] == 'C' || s[i] == 'D' || s[i] == 'M'))
				{
					result -= 2 * 50;
					isNeedMatch = false;
					continue;
				}
				else if (s[i - 1] == 'C' && (s[i] == 'D' || s[i] == 'M'))
				{
					result -= 2 * 100;
					isNeedMatch = false;
					continue;
				}
				else if (s[i - 1] == 'D' && s[i] == 'M')
				{
					result -= 2 * 500;
					isNeedMatch = false;
					continue;
				}
			}

			if (s[i] == 'I' || s[i] == 'V' || s[i] == 'X' || s[i] == 'L'|| s[i] == 'C'|| s[i] == 'D') {
				isNeedMatch = true;
			}
		}
		return result;
	}
	int romanToInt(string s) {
		unordered_map<char, int> mapRI;
		mapRI['I'] = 1;
		mapRI['V'] = 5;
		mapRI['X'] = 10;
		mapRI['L'] = 50;
		mapRI['C'] = 100;
		mapRI['D'] = 500;
		mapRI['M'] = 1000;

		int num = 0;

		int size = s.size();
		int lastInt = INT_MAX;
		int currInt = INT_MAX;

		for (int i = 0; i < size; i++) {
			lastInt = currInt;
			currInt = mapRI[s[i]];

			if (lastInt < currInt) {
				num -= lastInt;
				num += (currInt - lastInt);
			}
			else {
				num += currInt;
			}
		}

		return num;
	}
private:

};

//int main(void) {
//	string s;
//	Solution sol;
//	while (cin >> s) {
//		cout << sol.roman2integer(s) << endl;
//	}
//	return 0;
//}