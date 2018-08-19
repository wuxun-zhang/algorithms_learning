#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

// dictionary search tree or Trie tree

class Solution{
public:
	// O(n^2)
	string longestCommonPrefix_v1(vector<string>& strs){
		if(strs.empty())
			return "";
		string res("");
		int numStr = strs.size();
		int i, j=0;
		bool isPrefix = true;
		for(j=0; j<strs[0].size(); j++){
			char c = strs[0][j];
			for(i=1; i<numStr; i++){
				if(j>strs[i].size() || strs[i][j] != c)
					return res;
			}
			res.push_back(c);
		}
		return res;		
	}
	// O(n^2)
	string longestCommonPrefix_v2(vector<string>& strs){
		if(strs.empty())
			return "";
		for(int j=0;j<strs[0].size();j++){
			for(int i=0;i<strs.size()-1;i++){
				if(j>=strs[i].size() || j>=strs[i+1].size() ||
					strs[i][j] != strs[i+1][j]){
					return strs[i].substr(0, j);
				}
			}
		}
		return strs[0];
	}
private:
};

int main(void){
	vector<string> in;
	string line, word;
	Solution sol;
	while(getline(cin, line)){
		istringstream wordsStream(line);
		while(wordsStream>>word){
			in.push_back(word);
		}
		cout<< sol.longestCommonPrefix_v1(in) <<endl;
	}
	return 0;
}