#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

int helper(unordered_map<int, int>& m){
	int min_idx = INT32_MAX;
	for(auto item:m){
		if(min_idx > item.second)
			min_idx = item.second;
	}
	return min_idx;
}

int main(void){
	int N, M;
	cin>>N>>M;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
	}

	unordered_map<int, int> m;
	int left=0, right=0;
	int min_length = INT32_MAX;
	for(int i=0;i<N;i++){
		if(m.find(a[i]) != m.end()){
			m[a[i]] = i;
			left = helper(m);
			min_length = min(min_length, (++right)-left);
		}else{
			m[a[i]] = i;
			min_length = (++right)-left;
		}
		//right++;
	}

	cout<<((min_length==INT32_MAX)?0:min_length)<<endl;
	return 0;
}