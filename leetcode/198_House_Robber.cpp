#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rob_v1(vector<int>& nums)
	{
		if (nums.empty())
			return -1;
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return *max_element(nums.begin(), nums.end());

		vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = nums[1];
		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);	// 将当前位置的dp值更新为前面所有不相邻元素之和的最大值
		}
		return dp[nums.size() - 1];
	}
	//
	int rob_v2(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int even = 0, odd = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			// 
			if (i % 2 == 0)
				even = max(even + nums[i], odd);
			else
				odd = max(odd + nums[i], even);
		}
		return max(even, odd);
	}
	//
	int rob_v3(vector<int>& nums) {
		int len = nums.size();

		if (len == 0)
			return 0;
		if (len == 1) {
			return nums[0];
		}

		int sum1 = 0;
		int sum2 = nums[0];
		for (int i = 1; i < len; i++) {
			int t = sum2;
			sum2 = sum1 + nums[i];
			sum1 = max(sum1, t);
		}

		return max(sum1, sum2);
	}
};


//int main(void) {
//	int n;
//	while (cin >> n) {
//		vector<int> num(n);
//		for (int i = 0; i < n; i++)
//			cin >> num[i];
//		Solution sol;
//		cout << sol.rob_v2(num) << endl;
//	}
//	return 0;
//}