#include<string>
using namespace std;

class Solution{
public:
	// O(m*n)
	int strStr(string haystack, string needle){
		int len1 = haystack.size();
		int len2 = needle.size();
		if(!len2)
			return 0;
		if((!len1 && len2) ||(len1<len2))
			return -1;

		int j=0;
		for(int i=0; i<=len1-len2; i++){
			if(haystack[i] == needle[j]){
				int tmp=i;
				while(tmp+1<len1 && j+1<len2 && haystack[tmp+1]==needle[j+1]){
					tmp++;
					j++;
				}
				if(j==len2-1)
					return i;
				else
					j=0;
			}
		}
		return -1;
	}

	// O(m*n)
	int strStr_v2(string haystack, string needle){
		for(int i=0;;i++){
			for(int j=0;;j++){
				// substring found
				if(j == needle.size())
					return i;
				// substring not found
				if(i+j == haystack.size())
					return -1;
				// if not matched, continue to next loop
				if(needle[j] != haystack[i+j])
					break;
			}
		}
	}

	int strStr_v3(string haystack, string needle){
		
	}
	
	// KMP
	int strStr_v4(string haystack, string needle){

	}
private:

};