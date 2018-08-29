/*
Given a string of character, 
find the length of longest proper prefix which is also a proper suffix
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	int longestPrefixSuffix(string in){
		if(in.empty())
			return 0;
		// length of the previous longest prefix suffix
		int len=0, M=in.size();
		// lps[i] represents the length of longest prefix suffix before i-th char
		vector<int> lps(M, 0);
		lps[0] = 0;

		int i=1;
		while(i < M){
			if(in[i] == in[len])
			{
				len++;
				lps[i] = len;
				i++;
			}else{
				// backward to the last position
				// start position, len=0
				if(len != 0)
					len = lps[len-1];
				else
				{
					lps[i] = 0;
					i++;
				}
			}
		}
		int max=0;
		for(int i=1; i<M; i++){
			if(max<lps[i])
				max=lps[i];
		}
		return lps[M-1];
	}
};

//int main(void)
//{
//	Solution sol;
//	string s;
//	while(cin>>s){
//		cout<<sol.longestPrefixSuffix(s)<<endl;
//	}
//	return 0;
//}