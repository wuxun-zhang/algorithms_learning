#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using pp = pair<int,int>;
vector<vector<int> > praser(const string& line){

}

int greatestSquare(vector<vector<int> >& p){
	int m = p.size();
	int n = p[0].size();
	vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
	queue<pp> q;
	vector<vector<int>> visited(m, vector<int>(n, 0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(p[i][j] == 1)
				q.push({i,j});
		}
	}
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		for(auto dir:dirs){
			int x = t.first+dir[0], y = t.second+dir[1];
			if(visited[x][y] && (x<0 || x>=m || y<0 || y>=n))
				continue;
			p[t.first][t.second] = p[t.first][t.second] + p[x][y];
			q.push({x, y});
			visited[x][y] = 1;
		}
	}
	int max_square = INT32_MIN;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(max_square<p[i][j])
				max_square = p[i][j];
		}
	}
	return max_square;
}