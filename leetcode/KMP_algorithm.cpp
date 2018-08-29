/*
Given a text txt[0..n-1] and a pattern pat[0..m-1], 
write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. 
You may assume that n > m
*/

// KMP Algorithm

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	int KMP(string s, string p){
		int i=0, j=0;
		vector<int> next = getNext(p);
		while(i<s.size() && j<p.size()){
			if(j==-1 || t[i]==p[j]){
				i++;
				j++;
			}else{
				j=next[j];
			}
		}
		if(j == p.size())
			return i-j;
		else
			return -1;
	}
private:
	vector<int> getNext(string a){
		int len = a.size();
		vector<int> next(len);
		next[0] = -1;
		int j=0, k=-1;
		while(j<len-1){
			if(k==-1 || p[j]==p[k]){
				if(p[++j]==p[++k])
					next[j] = next[k];
				else
					next[j] = k;
			}else{
				k = next[k];
			}
		}
		return next;
	}
};