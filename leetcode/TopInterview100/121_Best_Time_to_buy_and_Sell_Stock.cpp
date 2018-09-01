#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int n = prices.size();
		int base = prices[0];
		int maxP = INT32_MIN;
		for (int i = 1; i < n; i++) {
			if (maxP < prices[i] - base)
				maxP = prices[i] - base;
			if (base > prices[i])
				base = prices[i];
		}
		return maxP > 0 ? maxP : 0;
	}
};

//int main(void) {
//	int n;
//	while (cin >> n) {
//		vector<int> a(n);
//		for (int i = 0; i < n; i++)
//			cin >> a[i];
//		Solution sol;
//		cout << sol.maxProfit(a) << endl;
//	}
//	return 0;
//}