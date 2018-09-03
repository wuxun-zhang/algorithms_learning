#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	// BFS
	// set all zeros be the starting position
	// updating the distance of ones until all zero positions have been searched
	vector<vector<int>> undateMatrix(vector<vector<int>>& matrix){
		int m = matrix.size(), int n = matrix[0].size();
		vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
		queue<pp> q;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(matrix[i][j]==0)
					q.push({i,j});
				else
					matrix[i][j] = INT_MAX;
			}
		}
		while(!q.empty()){
			auto t = q.fornt();
			q.pop();
			for(auto dir:dirs){
				int x=t.first+dir[0], y=t.second+dir[1];
				if(x<0 || x>=m || y<0 || y>=n || matrix[x][y]<=matrix[t.first][t.second])
					continue;
				matrix[x][y] = matrix[t.first][t.second]+1;
				q.push({x,y});
			}
		}
		return matrix;
	}

	vector<vector<int>> undateMatrix_v2(vector<vector<int>>& matrix){
		int m=matrix.size(), n=matrix[0].size();
		vector<vector<int>> res(m, vector<int>(n, INT_MAX-1));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(matrix[i][j]==0)
					res[i][j]=0;
				else{
					if(i>0)
						res[i][j]=min(res[i][j], res[i-1][j]+1);
					if(j>0)
						res[i][j]=min(res[i][j], res[i][j-1]+1);
				}
			}
		}

		for(int i=m-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				if(res[i][j]>1){
					if(i<m-1)
						res[i][j]=min(res[i][j], res[i+1][j]+1);
					if(j<n-1)
						res[i][j]=min(res[i][j], res[i][j+1]+1);
				}
			}
		}
		return res;		
	}
private:
	using pp = pair<int, int>;
};