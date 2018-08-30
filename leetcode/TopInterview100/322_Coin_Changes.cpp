#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int coinChanges(vector<int>& coins, int amount) {
		// cannot initialized by INT_MAX
		// because dp[i]+1 will be overflow
		vector<int> dp(amount + 1, amount+1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (coins[j] <= i)
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
		// illegal if dp[i] is larger than amount, 
		// because the amount of money is made of at most amount coins of 1
		return dp[amount] > amount ? -1 : dp[amount];
	}
	// recursive
	int coinChanges_v2(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		return coinChangesDFS(coins, amount, dp);
	}

	int coinChanges_v3(vector<int>& coins, int amount) {
		unordered_map<int, int> dp;
		dp[0] = 0;
		return coinChangesDFS_HashTable(coins, amount, dp);
	}
private:
	// DFS
	// traverse all situations
	int coinChangesDFS(vector<int>& coins, int amount, vector<int>& dp) {
		if (amount < 0)
			return -1;
		if (dp[amount] != INT_MAX)
			return dp[amount];
		for (int i = 0; i < coins.size(); i++) {
			int tmp = coinChangesDFS(coins, amount - coins[i], dp);
			if (tmp >= 0)
				dp[amount] = min(dp[amount], tmp + 1);
		}
		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
	// hash table
	int coinChangesDFS_HashTable(vector<int>& coins, int amount, unordered_map<int, int>& dp) {
		if (amount < 0)
			return -1;
		if (dp.find(amount) != dp.end())
			return dp[amount];
		int cur = INT_MAX;
		for (int i = 0; i < coins.size(); i++) {
			int tmp = coinChangesDFS_HashTable(coins, amount - coins[i], dp);
			if (tmp >= 0)
				cur = min(cur, tmp + 1);
		}
		return dp[amount] = cur == INT_MAX ? -1 : cur;
	}
};

