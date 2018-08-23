#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// the maximum length of substring between the given string and its palindrome string
// we only need to know the startIdx and length of palindrome in the given
// string, then the resukt can be derived through calling the function
// s.substr(startIdx, length) 

class Solution{
public:
	string longestPalindrome_v1(string s){
		int startIdx=0, left=0, right=0, len=0;
		for(int i=0; i<s.size(); i++){
			if(s[i] == s[i+1]){
				left=i;
				right=i+1;
				searchPalindrome(s, left, right, startIdx, len);
			}
			left=right=i;
			searchPalindrome(s, left, right, startIdx, len);
		}
		if(len == 0)
			len = s.size();
		return s.substr(startIdx, len);
	}

	string longestPalindrome_v2(string s){
		int n = s.size();
		int startIdx=0, max_len=0;
		for(int i=0; i<n; i++){
			int len = expand(s, i, i);
			if(i+1<n){
				len = max(len, expand(s, i, i+1));
			}
			if(max_len<len){
				startIdx = i-(len-1)/2;
				max_len = len;
			}
		}
		return s.substr(startIdx, max_len);
	}

	//** DP
	// dp[i, j] = 1		if i==j
	// 			= s[i] == s[j] if j=i+1
	//			= s[i] == s[j] && dp[i-1,j+1]=1 if i-j>1 
	string longestPalindrome_v3(string s){
		int n = s.size();
		if(n<1)
			return "";
		int dp[n][n] = {0}, left=0, right=0, len=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<i;j++){
				dp[j][i] = (s[j]==s[i] && (i-j<2 || dp[j+1][i-1]));
				if(dp[j][i] && len<i-j+1){
					len=i-j+1;
					left = j;
					right = i;
				}
			}
			dp[i][i] = 1;
		}
		return s.substr(left, right-left+1);
	}

	// Manacher's Algorithm
	string longestPalindrome_v4(string s){
		string t = "$#";
		for(int i=0;i<s.size(); i++){
			t += s[i];
			t += '#';
		}
		int p[t.size()] = {0}, id=0, mx=0, resId=0, resMx=0;
		for(int i=0;i<t.size(); i++){
			p[i] = mx>i?min(p[2*id-i], mx-i):1;
			while(t[i+p[i]] == t[i-p[i]])
				++p[i];
			if(mx<i+p[i]){
				mx=i+p[i];
				id=i;
			}
			if(resMx<p[i]){
				resMx=p[i];
				resId=i;
			}
		}
		return s.substr((resId-resMx)/2, resMx-1);		
	}
private:
	void searchPalindrome(string s, int left, int right, int &startIdx, int &len){
		int step=1;
		while((left-step)>=0 && (right+step)<s.size()){
			if(s[left-step] != s[right+step])
				break;
			step++;
		}
		int wide = right-left+2*step-1;
		if(len<wide){
			len = wide;
			startIdx = left-step+1;
		}
	}

	int expand(string& s, int i, int j){
		int n = s.size();
		while(i>=0 && j<n && s[i] == s[j]){
			i--;
			j++;
		}
		return j-i-1; // the length of the searched palindrome
	}
};