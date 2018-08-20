#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// the maximum length of substring between the given string and its palindrome string

class Solution{
public:
	string longestPalindrome(string s){
		string a(s);
		string result = "";
		reverse(a.begin(), a.end());
		int n = s.size();
		vector<vector<int>> dp(n+1,vector<int>(n+1, 0));
		for(int i=0;i<n;i++){
			dp[i][0] = a[i] == s[0]?1:0;
			dp[0][i] = a[0] == s[i]?1:0;
		}
		string itm="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i-1] == s[j-1]){
					itm.push_back(a[i-1]);
				}else{
					itm = "";
				}
				if(result.size()<itm.size()){
					result = itm;
				}
			}
		}
		return result;
	}

	string longestPalindrome_v2(string s){
		int length = s.size();
		int dp[length][length] = {0};
		int left=0, right=0, len=0;
		for(int i=0;i<length;++i){
			for(int j=0;j<i;j++){
				
			}
		}
	}
private:

};