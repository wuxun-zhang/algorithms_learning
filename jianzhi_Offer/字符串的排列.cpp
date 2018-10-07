#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
  		if(str.empty())
  			return {};
  		vector<string> allStrs;
		helper(str, 0, allStrs);
  		return allStrs;
    }

private:
	void helper(string pStr, int k, vector<string>& allStrs){
		if(k == pStr.size()-1){
			allStrs.push_back(pStr);
			return;
		}
		unordered_set<char> chars;
		sort(pStr.begin()+k, pStr.end());
		for(int i=k; i<pStr.size(); i++){
			// process the repeated char: need not to exchange these two chars
			if(chars.find(pStr[i]) == chars.end()){
				chars.insert(pStr[i]);
				swap(pStr[i], pStr[k]);
				helper(pStr, k+1, allStrs);
				swap(pStr[i], pStr[k]);
			}
		}
		return;
	}
};

// int main(void){
// 	string in;
// 	Solution sol;
// 	while(cin>>in){
// 		vector<string> allStrs;
// 		allStrs = sol.Permutation(in);
// 		cout<<"All combinations of the above chars are as follows:"<<endl;
// 		for(auto item : allStrs)
// 			cout<<item<<endl;
// 	}
// 	return 0;
// }