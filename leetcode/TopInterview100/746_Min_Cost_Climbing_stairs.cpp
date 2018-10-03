#include<iosream>
#include<vector>
#include<unordered_map>
using namespace std;

// DP
// dp[n] = min(dp[n-1], dp[n-2]) + cost[n]

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=INT32_MAX, b=INT32_MAX;
        int len = cost.size();
        for(int i=0; i<len; i++){
        	if(i%2==0){
        		a = a==INT32_MAX ? cost[i]:min(a, b)+cost[i];
        	}else{
        		b = b==INT32_MAX ? cost[i]:min(b, a)+cost[i];
        	}
        }
        return min(a, b);
    }

    int minCostClimbingStairs_opt1(vector<int>& cost){
    	int a=0, b=0;
    	for(auto num : cost){
    		int t = min(a, b) + num;
    		a = b;
    		b = t;
    	}
    	return min(a, b);
    }

    int _01_minCostClimbingStairs(vector<int>& cost){
    	int n = cost.size();
    	vector<int> dp(n+1, 0);
    	for(int i=2; i<n+1; i++){
    		dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
    	}
    	return dp.back();
    }

    int _02_minCostClimbingStairs(vetcor<int>& cost){
    	int n = cost.size();
    	vector<int>& dp(n, 0);
    	dp[0]=cost[0];
    	dp[1]=cost[1];
    	for(int i=2; i<n; i++){
    		dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    	}
    	return min(dp[n-1], dp[n-2]);
    }

    // recursive
    // use hash table to store values calculated before
    int _03_minCostClimbingStairs(vector<int>& cost){
    	unordered_map<int, int> memo;
    	return helper(cost, cost.size(), memo);
    }

private:
	int helper(vetcor<int>& cost, int i, unordered_map<int, int>& memo){
		if(memo.count(i))
			return memo[i];
		if(i<=1)
			return memo[i] = cost[i];
		return memo[i] = ((i==cost.size()) ? 0:cost[i]) + 
							min(helper(cost,i-1,memo), helper(cost,i-2,memo));
	}
};