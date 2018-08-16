#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	// reverse内部调用了swap函数
	void rotate_v1(vector<int>& nums, int k) {
		if (nums.empty() || k < 0)
			return;
		if (k == nums.size() || k == 0)
			return;
		int length = nums.size();
		k = (k > length) ? (k%length) : k;
		reverse(nums.begin(), nums.begin()+length-k);
		reverse(nums.begin() + length - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
	// 
	void rotate_v2(vector<int>& nums, int k)
	{
		int n = nums.size();
		vector<int>::iterator it = nums.begin();
		for (; k = k%n; n -= k, it += k)
		{
			// Swap the last k elements with the first k elements. 
			// The last k elements will be in the correct positions
			// but we need to rotate the remaining (n - k) elements 
			// to the right by k steps.
			for (int i = 0; i < k; i++)
			{
				swap(it[i], it[n - k + i]);
			}
		}
	}
	// 
	void rotate_v3(vector<int>& nums, int k) {
		if (nums.empty())
			return;
		int n = nums.size(), start = 0;
		while (n && (k %= n)) {
			for (int i = 0; i < k; i++) {
				swap(nums[i+start], nums[n - k + i + start]);
			}
			n -= k;
			start += k;
		}
	}
private:
	using IterType = vector<int>::iterator;
	
};

//int main(void) {
//	vector<int> nums = { 1,2,3,4,5,6,7,8 };
//	Solution sol;
//	int k;
//	while (cin >> k) {
//		sol.rotate_v3(nums, k);
//		for (auto item : nums) {
//			cout << item << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}