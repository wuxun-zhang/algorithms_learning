#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*
** hints: two pointers
*/

class Solution{
public:
	int lengthOfLongestSubstring(string& s){
		if(s.empty()){
			return 0;
		}
		unordered_map<char, int> charMap;
		int start=-1, maxLen=0;
		for(int i=0; i<s.size(); i++){
			if(charMap.find(s[i]) != charMap.end()){
				// make sure that the start value must be 
				// the lastest
				start = max(start, charMap[s[i]]);
			}
			charMap[s[i]] = i;
			maxLen = max(maxLen, i-start);
		}
		return maxLen;
	}
};