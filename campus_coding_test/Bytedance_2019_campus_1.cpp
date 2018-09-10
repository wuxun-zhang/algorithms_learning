#include<iostream>
#include<vector>
#include <stack>
using namespace std;

using pp = pair<int, int>;

int main(void){
	int N, M;
	while(cin>>N>>M){
		vector<pp> relation(M);
		for(int i=0; i<M; i++)
			cin>>relation[i].first>>relation[i].second;

		stack<int> s;
		vector<int> indegree(M, 0);
		for(auto item : relation)
			indegree[--item.second]++;

		for(int i=0; i<M; i++){
			if(!indegree[i])
				s.push(i);
		}
		int count = 0;
		vector<int> count_each(M, 0);
		while(!s.empty()){
			int top =  s.top();
			s.pop();
			for(auto r : relation){
				if(r.first == top){
					if(!(--indegree[r.second])){
						count_each[--r.second]++;
						s.push(r.second);
					}
				}
			}
			++count;
		}

		//if (count != M)
		//	cout << M <<endl;
		//else{
			int count_sum = 0;
			for(auto item : count_each){
				if(item == M)
					count_sum++;
			}
			cout<<count_sum<<endl;
		//}
	}
	return 0;
}