#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	// 快速排序的思想
	// 使用Partition函数，时间复杂度为nlog2(k)
	vector<int> GetLeastKNumbers_v1(vector<int>& num, int k) {
		if (num.empty())
			return vector<int>{};
		int length = num.size();
		int start = 0, end = length - 1;
		int index = myPartition(num, start, end);
		while (index != k - 1) {
			if (index > k - 1) {
				end = index-1;
				index = myPartition(num, start, end);
			}
			else {
				start = index+1;
				index = myPartition(num, start, end);
			}
		}
		vector<int> result;
		for (int i = 0; i < k; i++) {
			result.push_back(num[i]);
		}
		return result;
	}
	// 使用最大堆找到前（n-k）个最大的数，则剩下的自然是k个最小的数
	// 时间复杂度为nlog2（k）
	vector<int> GetLeastKNumbers_v2(vector<int>& num, int k) {
		if (num.empty() || k > num.size())
			return vector<int>{};
		vector<int> result;
		int length = num.size();
		int start = length/2 - 1;
		for (int index = start; index >= 0;index--) {
			maxHeap(num, index, length - 1);
		}
		for (int index = length-1; index > length - k - 1; index--) {
			mySwap(num[0], num[index]);
			maxHeap(num, 0, index - 1);
		}
		for (int i = 0; i < k; i++)
			result.push_back(num[i]);
		return result;
	}
	// 使用priority_queue
	// 默认为最大堆
	vector<int> GetLeastKNumbers_v3(vector<int>& num, int k) {
		if (num.empty() || k > num.size())
			return vector<int>{};
		priority_queue<int> q;
		int length = num.size();
		for (int i = 0; i < length; i++) {
			if (i < k)
				q.push(num[i]);
			else {
				if (num[i] < q.top())
				{
					q.pop();
					q.push(num[i]);
				}
			}
		}
		vector<int> result;
		for (int i = 0; i < k; i++) {
			int top = q.top();
			q.pop();
			result.push_back(top);
		}
		return result;
	}
private:
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
	void maxHeap(vector<int>& num, int start, int end) {
		int lchild;
		while (1) {
			lchild = 2 * start + 1;
			if (lchild > end)
				break;
			if (lchild + 1 <= end && num[lchild] < num[lchild + 1])
				lchild += 1;
			if (num[start] < num[lchild]) {
				mySwap(num[start], num[lchild]);
				start = lchild;
			}
			else {
				break;
			}
		}
	}
	template<typename T>
	void mySwap(T& a, T& b) {
		a = a^b;
		b = a^b;
		a = a^b;
	}

};

//int main(void) {
//	vector<int> in{9,8,7,0,6,4,8};
//	Solution sol;
//	for (auto& item : in)
//		cout << item << " ";
//	cout << endl;
//	vector<int> out = sol.GetLeastKNumbers_v3(in, 4);
//	for (auto& item : out)
//		cout << item << " ";
//	cout << endl;
//	return 0;
//}