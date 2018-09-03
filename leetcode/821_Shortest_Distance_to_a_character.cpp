#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	// BFS
	// first Time : search from start to end
	// second Time : search from end to start
	vector<int> shortestToChar(string S, char c){
		if(S.find(c)==S.end())
			return vector<int>{};
		vector<int> res(S.size(), INT_MAX-1);
		for(int i=0;i<S.size();i++){
			if(S[i]==c)
				res[i]=0;
			else{
				if(i>0)
					res[i]=min(res[i], res[i-1]+1);
			}
		}

		for(int i=S.size()-1;i>=0;i--){
			if(res[i]>1){
				if(i<S.size()-1)
					res[i]=min(res[i], res[i+1]+1);
			}
		}
		return res;
	}

	// standard solution for BFS: queue
	vector<int> shortestToChar_v2(string S, char C){
		queue<int> q;
		int dirs[2] = {-1,1};
		vector<int> res(S.size(), 0);
		for(int i=0;i<S.size();i++){
			if(S[i]==C)
				q.push(i);
			else
				res[i]=INT_MAX;
		}
		while(!q.empty()){
			auto t=q.front();
			q.pop();
			// two dorections: left and right
			for(int i=0;i<2;i++){
				int x=t+dirs[i];
				if(x<0 || x>=S.size() || res[x]<=res[t])
					continue;
				else{
					res[x]=min(res[x], res[t]+1);
					q.push(x);
				}
			}
		}
		return res;
	}
};