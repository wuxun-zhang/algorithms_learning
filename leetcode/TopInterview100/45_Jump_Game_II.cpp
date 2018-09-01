#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Solution{
public:
	// BFS
	// Time limit exceed
	int jump(vector<int>& nums){
		if(nums.empty())
			return 0;
		int len = nums.size();
		vector<int> visited(len, 0);
		queue<pp> q;
		// first : index
		// second: count
		q.push({0, 0});
		visited[0] = 1;
		while(!q.empty()){
			pp cur = q.front();
			q.pop();
			if (cur.first == len-1) {
				return cur.second;
			}
			for(int i=1; i<=nums[cur.first]; i++){
				if(i+cur.first<len && !visited[i+cur.first]){
					visited[i+cur.first] = 1;
					q.push(make_pair(i+cur.first, cur.second+1));
				}
			}
		}
		return -1;
	}

	// 
	int jump_v2(vector<int>& nums){
		int res=0, n=nums.size(), i=0, cur=0;
		while(cur<n-1){
			++res;
			int pre = cur;
			for(; i<=pre; i++){
				cur = max(cur, i+nums[i]);				
			}
		}
		return res;
	}

	// use greedy algorithm to update the farest distance reached
	int jump_v3(vector<int>& nums){
		int res=0, n=nums.size(), last=0, cur=0;
		for(int i=0; i<n-1; i++){
			cur = max(cur, i+nums[i]);
			if(i == last){
				res++;
				last = cur;
				if(cur>=n-1)
					break;
			}
		}
		return res;
	}

	int jump_v4(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int count = 1, maxN = nums[0], i = 1, nextMax = 0;
        if(maxN >= nums.size()-1)
            return count;
        while(true) {
            for(; i <= maxN; i++) {
                if(i+nums[i] >= nums.size()-1)
                    return count+1;
                nextMax = max(nextMax, i+nums[i]);
            }
            maxN = nextMax;
            count++;
        }
        return count++;
    }
private:
	using pp = pair<int, int>;
};