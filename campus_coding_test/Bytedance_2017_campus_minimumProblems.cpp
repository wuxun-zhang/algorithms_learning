#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	Solution(){}
	~Solution(void){}

	int minProblems(vector<int>& factor){
		int num=factor.size();
		int res=0, count=1;
		sort(factor.begin(), factor.end());
		for(int i=1;i<num;i++){
			if(factor[i]-factor[i-1]<=10)
				count++;
			else{
				// cannot make up enough 3 problems
				if(count%3!=0)
					res+=3-(count%3);
				count=1;
			}
		}
		if(count%3!=0)
			res+=3-count%3;
		return res;
	}
};

//int main(void){
//	Solution sol;
//	int n;
//	while(cin>>n){
//		vector<int> f(n);
//		for(auto& item:f)
//			cin>>item;
//		cout<<sol.minProblems(f)<<endl;
//	}
//	return 0;
//}