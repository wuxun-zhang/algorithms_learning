#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Solution{
public:
	// BFS
	bool canJump(vector<int>& nums){
		if(nums.empty())
			return true;
		int len = nums.size();
		vector<int> visited(len, 0);
		queue<pp> q;
		q.push({nums[0], 0});
		visited[0] = 1;
		while(!q.empty()){
			pp cur = q.front();
			q.pop();
			if (visited[len-1]) {
				return true;
			}
			for(int i=1; i<=cur.first; i++){
				if(i+cur.second<len && !visited[i+cur.second]){
					visited[i+cur.second] = 1;
					q.push(make_pair(nums[i+cur.second], i+cur.second));
				}
			}
		}
		return false;
	}

	// DP
	bool canJump_v2(vector<int>& nums){
		int len = nums.size();
		vector<int> dp(len, 0);
		for(int i=1; i<len; i++){
			// the remaining steps at the i-th position 
			dp[i] = max(dp[i-1], nums[i-1]) - 1;
			if(dp[i] < 0)
				return false;
		}
		return dp.back()>=0;
	}

	// Greedy algorithm
	bool canJump_v3(vector<int>& nums){
		int reach=0;
		// only consider the farest distance that can be reachable
		for(int i=0; reach+1<nums.size() && i<=reach; i++){
			reach = max(reach, i+nums[i]);
		}
		return reach+1>=nums.size();
	}
private:
	using pp = pair<int, int>;
};

//int main(void){
//	vector<int> a{2,5,0,0};
//	Solution sol;
//	cout<<(sol.canJump_v2(a)?"true":"false")<<endl;
//	return 0;
//}