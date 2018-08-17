#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		int length = numbers.size();
		int mid = length >> 1, start=0, end = length-1;
		int index = myPartition(numbers, start, end);
		while (index != mid) {
			if (index < mid) {
				start = index + 1;
				index = myPartition(numbers, start, end);
			}
			else {
				end = index - 1;
				index = myPartition(numbers, start, end);
			}
		}
		int result = numbers[mid];
		if (!CheckEltMoreThanHalfNum(numbers, result))
			result = 0;
		return result;
	}
	int MoreThanHalfNum_Solution_v2(vector<int>& numbers) {
		int count = 1, length = numbers.size();
		int result = numbers[0];
		for (int i = 1; i < length; i++) {
			if (count == 0) {
				result = numbers[i];
				count = 1;
			}
			else if (result == numbers[i])
				++count;
			else
				--count;
		}
		if (!CheckEltMoreThanHalfNum(numbers, result))
			return 0;
		return result;
	}
private:
	// QuickSort kernel
	int myPartition(vector<int>& num, int start, int end) {
		int base = num[start];
		while (start < end) {
			while (start < end&&num[end] >= base)
				end--;
			num[start] = num[end];
			while (start < end&&num[start] <= base)
				start++;
			num[end] = num[start];
		}
		num[start] = base;
		return start;
	}
	// 判断查找到的值出现次数是否超过数组长度的一半
	bool CheckEltMoreThanHalfNum(vector<int>& numbers, int elt) {
		int count = 0, length = numbers.size();
		for (auto& item : numbers) {
			if (item == elt)
				count++;
		}
		if (count > (length >> 1))
			return true;
		return false;
	}
};

//int main(void) {
//	int n;
//	Solution sol;
//	while (cin >> n) {
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		cout << sol.MoreThanHalfNum_Solution_v2(a) << endl;
//	}
//	return 0;
//}